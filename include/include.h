//main include file
//written by SL

#ifndef __INCLUDE_H__
#define __INCLUDE_H__

/*
include function prototypes - here all functions used in logger.h, sbbmtp.h, functions.h, and debug.h
*/
#include <prototypes.h> 

/*
include libraries used, configurations (define etc), and variables, datatypes and objects
*/
#include <Arduino.h>    //Arduino functions (this actually includes the teensy core)
#include <libs.h>       //include libraries for buses, sensors, etc.
#include <config.h>     //configuration file
#include <objects.h>    //data types, variables, and objects

/*
include implementations - workaround: put in .h file instead of .cpp (which does not work in Arduino environment (?))
*/
#include <logger.h>     //include logger functions
#include <sbbmtp.h>     //include mtp functions
#include <userfun.h>    //include user-defined functions
#include <debug.h>      //include debug functions

#endif