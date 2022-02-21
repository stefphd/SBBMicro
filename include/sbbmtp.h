//mtp file
//written by SL

#ifndef __MTP_H__
#define __MTP_H__

#define DOMTP //enable MTP

#ifdef DOMTP //must exist both DOMTP and DOLOG for enabling MTP!

//includes
#include <MTP.h> //for media transfer protocol with pc (already included when installing teensyduino)
#include <SD.h> //for SD stuff

//defines
#define STORAGENAME "SBB Logger"

//check mtp function
bool check_mtp(void) {
  //timeout on input pin with button (enable is pu) for XX seconds
  //if check success return true
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
  }
  return;
}


#else //empty funs if not mtp
bool check_mtp(void) {return false;} //return false if not mtp
void do_mtp(void) {}
//add more empty logging functions here if necessary

#endif
#endif