
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
#define DEBUG_SAMPLING_FAC	2 //!< Sampling factor of data streaming (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME \ingroup debfun
#define MAX_MISSING_READS   50 //!< Maximum consecutive missing readings. \details The maximum consecutive missing readings after which the overriding with received signals is disabled. \ingroup debfun

#if DODEBUG == 1

//variables and objects
HostPort hostPort(&Serial, HEADER, TERMINATOR); //!< Object for the host communication with PC vis USB/serial. \see HostPort \ingroup debfun

/*! \brief Receive struct for debug.
	  \details The struct containing the received signals which overrides the corresponding signals in ctrl.controlModel_Y.
    \see debfun debug.h rx_packet
    \ingroup debfun
*/
struct Debug_rx {
	float curr_ref; //!< Reference current.
	float throttle_ref; //!< Reference throttle.
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
  rx_packet.curr_ref = *((float*) &nanVal);
  rx_packet.throttle_ref = *((float*) &nanVal);
}

/*
void do_debug(void) performs debug stuff
*/
void do_debug(void) {
    
    //this is done in the main loop
    if (missing_reads<MAX_MISSING_READS) { //set the last receive packet until missing_reads<MAX_MISSING_READS and if not NaN
      if (*((uint32_t*)&rx_packet.curr_ref) != nanVal) {
        ctrl.controlModel_Y.curr_ref = rx_packet.curr_ref;
        remote_raw.ch[SBUS_EN_CH-1] = TRESHOLD_LOGIC_SBUS;
      }
      if (*((uint32_t*)&rx_packet.throttle_ref) != nanVal) {
        ctrl.controlModel_Y.throttle_ref = rx_packet.throttle_ref;
        remote_raw.ch[SBUS_EN_CH-1] = TRESHOLD_LOGIC_SBUS;
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

      ctrl.controlModel_Y.user_data[1] = timing.dt_cycle;
      ctrl.controlModel_Y.user_data[3] = analogRead(RIDER_TRQ);

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

//add more debug functions here

#else //empty funs if not debug
void start_debug(void) {}
void do_debug(void) {}

//add more empty debug functions here if necessary

#endif
#endif
