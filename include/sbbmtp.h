//mtp file
//written by SL

#ifndef __MTP_H__
#define __MTP_H__

#define DOMTP //enable MTP

#ifdef DOMTP //must exist both DOMTP and DOLOG for enabling MTP!

//defines
#define STORAGENAME         "SBB Logger"
#define MTP_ENABLE_TIMEOUT  3000 //timeout for enabling mtp mode (ms)

#ifndef DOLOG
#define sd			            SD.sdfs //sd card obj (uses sd fat now included in SD library w/ teensyduino)
#define SD_CONFIG	          SdioConfig(FIFO_SDIO) //configuration of sd card
#endif

//check mtp function
bool check_mtp(void) {
  uint32_t mtp_timer = millis();
  while ((millis()-mtp_timer) <= MTP_ENABLE_TIMEOUT) {
    if (digitalReadFast(ONOFF_STATE_PIN)) { return false; } 
    delay(100); //wait 100ms for the next check
  }
  if (!sd.begin(SD_CONFIG)) { return false; }    
  LEDmode = LedMode::MTP;
  return true;
}

//do mtp
void do_mtp(void) {
  //wait for serial activation
  while (!usb_configuration) {}; //wait untill usb connected

  //create mtp objects (local object to not leak RAM in 'normal' mode)
  MTPStorage_SD storage;  //storate obj for mtp
  MTPD    mtpd(&storage); //mtp obj

  //add SD to storage
  storage.addFilesystem(SD, STORAGENAME);

  //init SD
  // if not init correctly return
  //TODOOOOO

  //mtp loop
  while (true) {
    if (usb_configuration) mtpd.loop(); //do mtp if usb connected
    if ((micros() - sampling_timer) >= SAMPLING_TIME) {
	  	sampling_timer = micros(); //update timer
      do_led();
    }
  }
  return;
}


#else //empty funs if not mtp
bool check_mtp(void) {return false;} //return false if not mtp
void do_mtp(void) {}
//add more empty logging functions here if necessary

#endif
#endif
