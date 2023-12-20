
#ifndef __MTP_H__
#define __MTP_H__

/*! \file sbbmtp.h
	\brief Definitions of MTP functions and variables.
	\details File to defined the MTP functions and variables. Function prototypes are in prototypes.h.
	\see mtpfun prototypes.h
*/

//defines
#define DOMTP               1 //!< Enable or disable MTP (1/0). \ingroup mtpfun
#define STORAGENAME         "SBB Logger" //!< MTP storage name. \details The name shown in the PC when connecting the USB. \ingroup mtpfun
#define MTP_ENABLE_TIMEOUT  3000 //!< Timeout for enabling MTP mode (ms). \details If the on/off button is pressed for a time longer than this, the microcontroller enters in MTP mode. \ingroup mtpfun

#if DOMTP == 1 //must exist both DOMTP and DOLOG for enabling MTP!

//check mtp function
bool check_mtp(void) {
  uint32_t mtp_timer = millis();
  while ((millis()-mtp_timer) <= MTP_ENABLE_TIMEOUT) {
    if (digitalReadFast(ONOFF_STATE_PIN)) { return false; } 
    delay(100); //wait 100ms for the next check
  }
  if (!sd.begin(SD_CONFIG)) { return false; }    
  LEDmode = LedMode::MTPWAIT; //set LEDmode to MTPWAIT by default
  return true;
}

//do mtp
void do_mtp(void) {
  //create mtp objects (local object to not leak RAM in 'normal' mode)
  MTPStorage_SD storage;  //storate obj for mtp
  MTPD    mtpd(&storage); //mtp obj
  //add SD to storage
  storage.addFilesystem(SD, STORAGENAME);
  //wait for USB connected
  while (true) {
    if (USB_CONNECTED) {
      LEDmode = LedMode::MTP;
      mtpd.loop();
    }
    else
      LEDmode = LedMode::MTPWAIT;
    if ((micros() - sampling_timer) >= SAMPLING_TIME) {
	  	sampling_timer = micros(); //update timer
      do_led();
    }
  }
}


#else //empty funs if not mtp
bool check_mtp(void) {return false;} //return false if not mtp
void do_mtp(void) {}
//add more empty logging functions here if necessary

#endif
#endif
