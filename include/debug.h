//debug file
//written by SL

#ifndef __DEBUG_H_
#define __DEBUG_H_

#define DODEBUG //enable debug

#ifdef DODEBUG

//defines
#define HEADER				      0xFF812345 //start byte of data transfer - ovf in float (not used)
#define TERMINATOR			    0xFF8CABDE //stop byte of data transfer - ovf in float (not used)
#define DEBUG_SAMPLING_FAC	2 //sampling factor of speed sensor (expressed in units of SAMPLING_TIME)
#define MAX_MISSING_READS   50 //max consecutive missing reads

//variables and objects
HostPort debug_port(&Serial, HEADER, TERMINATOR); //tx/rx object for communication with host pc
debut_rx_T rx_packet; //rx object
unsigned long missing_reads = MAX_MISSING_READS; // counts missing read

//functions
/*
void start_debug(void) waits for the usb serial for debugging
*/
void start_debug(void) {
	//Serial.begin(12e6) //not necessary with teensy
	//attach pointers (i.e. RAM address of first byte) of objects to transmit and corresponding size
	debug_port.attachTx((uint8_t*) &ctrl.controlModel_U, sizeof(ControlClass::ExtU_controlModel_T)); //control input, this are 20*4=80 bytes
	debug_port.attachTx((uint8_t*) &ctrl.controlModel_Y, sizeof(ControlClass::ExtY_controlModel_T)); //control output, this are 11*4=44 bytes
	//to trasmitted bytes are 80+44=124bytes, plus 4*2=8 bytes of start and stop bytes, resulting in 132 bytes to transmit

	//attach pointers (i.e. RAM address of first byte) of objects to receive and corresponding size
	debug_port.attachRx((uint8_t*) &rx_packet, sizeof(rx_packet)); //receive rx_packe, this are 2*4=8bytes

  rx_packet.curr_ref = *((float*) &nanVal);
  rx_packet.throttle_ref = *((float*) &nanVal);
}

/*
void do_debug(void) performs debug stuff
*/
void do_debug(void) {
    
    //this is done in the main loop
    if (missing_reads<MAX_MISSING_READS) { //read the last receive packet util missing_reads<MAX_MISSING_READS
      if (*((uint32_t*)&rx_packet.curr_ref) != nanVal) ctrl.controlModel_Y.curr_ref = rx_packet.curr_ref;
      if (*((uint32_t*)&rx_packet.throttle_ref) != nanVal) ctrl.controlModel_Y.throttle_ref = rx_packet.throttle_ref;
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

			//write and read
			uint32_t streamStartTime = micros();
			debug_port.write(); //write data to debug port - send control input, output and additional user data
      if (debug_port.read()) missing_reads = 0; //read from debug port - overwrite control output structure)
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
