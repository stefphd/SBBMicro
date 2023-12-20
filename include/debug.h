
#ifndef __DEBUG_H_
#define __DEBUG_H_

/*! \file debug.h
	\brief Definitions of debug functions and variables.
	\details File to defined the debug functions and variables. Function prototypes are in prototypes.h.
	\see debfun prototypes.h
*/

//defines
#define DODEBUG             1 //!< Enable or disable debugging (1/0). \ingroup debfun
#define HEADER				      0xFF812345 //!< 4-bytes header of data packet. \details Current selected value is an ovf in float, and thus it is safe. \see HostPort \ingroup debfun
#define TERMINATOR			    0xFF8CABDE //!< 4-bytes terminator of data packet. \details Current selected value is an ovf in float, and thus it is safe. \see HostPort \ingroup debfun
#define DEBUG_SAMPLING_FAC	10 //!< Sampling factor of data streaming (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME \ingroup debfun
#define MAX_MISSING_READS   50 //!< Maximum consecutive missing readings. \details The maximum consecutive missing readings after which the overriding with received signals is disabled. \ingroup debfun
//#define USE_HOSTPORT //!< Uncomment to use the HostPort library

#if DODEBUG == 1

//variables and objects
#ifdef USE_HOSTPORT

HostPort hostPort(&Serial, HEADER, TERMINATOR); //!< Object for the host communication with PC vis USB/serial. \see HostPort \ingroup debfun

/*! \brief Receive struct for debug.
	  \details The struct containing the received signals which overrides the corresponding signals in ctrl.controlModel_Y.
    \see debfun debug.h rx_packet
    \ingroup debfun
*/
struct Debug_rx {
	float refin0; //!< Reference input 0.
	float refin1; //!< Reference input 1.
} rx_packet; //!< Struct with received signals. \see Debug_rx \ingroup debfun

uint32_t missing_reads = MAX_MISSING_READS; //!< Counter for missing readings. \details Initial value is set to #MAX_MISSING_READS. \see MAX_MISSING_READS \ingroup debfun

//functions
/*
void start_debug(void) waits for the usb serial for debugging
*/
void start_debug(void) {
	//Serial.begin(12e6) //not necessary with teensy
	//attach pointers (i.e. RAM address of first byte) of objects to transmit and corresponding size
	hostPort.attachTx((uint8_t*) &ctrl.controlModel_U, sizeof(ControlClass::ExtU_controlModel_T)); //control input
	hostPort.attachTx((uint8_t*) &ctrl.controlModel_Y, sizeof(ControlClass::ExtY_controlModel_T)); //control output

	//attach pointers (i.e. RAM address of first byte) of objects to receive and corresponding size
	hostPort.attachRx((uint8_t*) &rx_packet, sizeof(rx_packet)); //receive rx_packet

  //init rx_packet with NaNs
  rx_packet.refin0 = *((float*) &nanVal);
  rx_packet.refin1 = *((float*) &nanVal);
}

/*
void do_debug(void) performs debug stuff
*/
void do_debug(void) {
    
    //this is done in the main loop
    if (missing_reads<MAX_MISSING_READS) { //set the last receive packet until missing_reads<MAX_MISSING_READS and if not NaN
      if (*((uint32_t*)&rx_packet.refin0) != nanVal) {
        ctrl.controlModel_U.ref_inputs[0] = rx_packet.refin0;
        //ctrl.controlModel_Y.curr_ref = rx_packet.curr_ref;
        //remote_raw.ch[SBUS_EN_CH-1] = TRESHOLD_LOGIC_SBUS;
      }
      if (*((uint32_t*)&rx_packet.refin1) != nanVal) {
        ctrl.controlModel_U.ref_inputs[1] = rx_packet.refin1;
        //ctrl.controlModel_Y.throttle_ref = rx_packet.throttle_ref;
        //remote_raw.ch[SBUS_EN_CH-1] = TRESHOLD_LOGIC_SBUS;
      } 
    }
    
		if (counters.debug == 0) {

      /*ctrl.controlModel_Y.user_data[1] = missing_reads;
      if (missing_reads<MAX_MISSING_READS) {
  			if (*((uint32_t*)&rx_packet.curr_ref) != nanVal) ctrl.controlModel_Y.user_data[2] = rx_packet.curr_ref;
        else ctrl.controlModel_Y.user_data[2] = -1.0F;
        if (*((uint32_t*)&rx_packet.throttle_ref) != nanVal) ctrl.controlModel_Y.user_data[3] = rx_packet.throttle_ref;
        else ctrl.controlModel_Y.user_data[3] = -1.0F;
      }
      else {
        ctrl.controlModel_Y.user_data[2] = -1.0F;
        ctrl.controlModel_Y.user_data[3] = -1.0F;
      }*/

      //ctrl.controlModel_Y.user_data[1] = timing.dt_cycle;
      //ctrl.controlModel_Y.user_data[3] = get_selector();

			//write and read
			uint32_t streamStartTime = micros();
			hostPort.write(); //write data to debug port - send control input, output and additional user data
      if (hostPort.read()) missing_reads = 0; //read from debug port - overwrite control output structure)
      else { if (missing_reads<MAX_MISSING_READS) missing_reads++;} //increase missing reads (up to MAX_MISSING_READS);
			timing.dt_debug = micros() - streamStartTime;

			//reset counter
			counters.debug = DEBUG_SAMPLING_FAC - 1;
		}
		else counters.debug--;
}

#else

struct TxData {
  ControlClass::ExtU_controlModel_T u;
  ControlClass::ExtY_controlModel_T y;
} txdata; //!< Data to transmit via Serial.
enum serialAction {
  TX_DATA = 0x01,
  TX_TIME = 0x02,
  TX_SIGNAMES = 0x03
}; //!< Serial commands.
const int NUMSIGS = 39; //!< Number of signals.
const char SPLIT_CHAR = '\0'; //!< Char to split strings
String signames[NUMSIGS] = {
    "Speed", "Distance", 
    "Acc x", "Acc y", "Acc z", 
    "Gyro x", "Gyro y", "Gyro z", 
    "Mag x", "Mag y", "Mag z", 
    "Latitude", "Longitude", "GPS Speed",
    "Steer angle", "Steer rate", 
    "Fork disp", 
    "Curr act", 
    "Steer torque", 
    "CPU temp", "Voltage", 
    "Ref input 1", "Ref input 2", 
    "Err state in", 
    "Curr ref", "Throttle", 
    "Roll est", "Yaw est", 
    "Pos est x", "Pos est y",
    "Dist est", "Speed est",
    "Steer angle est", "Steer rate est",  
    "Err state out", 
    "User data 1", "User data 2", "User data 3", "User data 4"
}; //!< Names of the signals.

void start_debug(void) {
 //nothing
}

void do_debug(void) {

  if (USB_CONNECTED) {
    while (Serial.available()) {
      serialAction c = (serialAction) Serial.read();
      switch (c)
      {
      case serialAction::TX_DATA:
        //update vals
        txdata.u = ctrl.controlModel_U;
        txdata.y = ctrl.controlModel_Y;
        txdata.y.user_data[0] = timing.max_tet;
        txdata.y.user_data[1] = timing.dt_cycle;
        txdata.y.user_data[2] = timing.tet;
        txdata.y.user_data[3] = timing.dt_logger;
        //write data
        Serial.write((uint8_t*) &txdata, sizeof(txdata));
        break;
      case serialAction::TX_TIME:
        {float current_time = ((float) micros()) / 1000000.0F;
        Serial.write((uint8_t*) &current_time, sizeof(current_time));}
        break;
      case serialAction::TX_SIGNAMES:
        for (int i = 0; i < NUMSIGS; ++i) {
          Serial.print(signames[i]);
          Serial.print(SPLIT_CHAR);
        }
        break;
      default:
        break;
      }
    }
  }
}

#endif

#else //empty funs if not debug
void start_debug(void) {}
void do_debug(void) {}

//add more empty debug functions here if necessary

#endif
#endif
