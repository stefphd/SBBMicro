
#ifndef __LIBS_H__
#define __LIBS_H__

/*! \file libs.h
	\brief Include of libraries.
	\details File to include the necessary (external) library for objects. 
	\see objects.h
*/

#include <ISM330DHCXSensor.h> //for imu https://github.com/stm32duino/ISM330DHCX
#include <LIS3MDLSensor.h> //for magnetometer https://github.com/stm32duino/LIS3MDL
#include <Adafruit_GPS.h> //for GPS 
#include <SPI.h> //for SPI communication (already included when installing teensyduino)
#include <ADC.h> //for ADC stuff https://github.com/pedvide/ADC (already included when installing teensyduino)
#include <ADC_util.h> //for ADC stuff https://github.com/pedvide/ADC (already included when installing teensyduino)
#include <MCP492X.h>  //for DAC https://github.com/michd/Arduino-MCP492X, modified by SL to use different SPI and added function latch() to latch DAC output
#include <SerialTransfer.h> //for serial trasfer with speed sensor https://github.com/PowerBroker2/SerialTransfer
#include <TimeLib.h> //for date & time (already included when installing teensyduino)
#include <T4_PowerButton.h> //for on/off button management https://github.com/FrankBoesing/T4_PowerButton/blob/master/examples/power/power.ino
#include <SD.h> //for saving in SD, includes SDFat
#include <RingBuf.h> //ring buffer for logging
#include <MTP.h> //for media transfer protocol with pc (already included when installing teensyduino)
#include <sbus.h> //for SBUS communication protocol with remote controller https://github.com/bolderflight/SBUS - modified by SL (simplifications)
#include <HostPort.h> //for debug operations
#include <controlModel.h> //include control model librariy (generated with the Embedeed coder)

#endif
