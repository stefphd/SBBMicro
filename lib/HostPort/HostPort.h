//HostPort.h
/*
Class for managing hostPC-MCU transfer operations. To initialize the object call e.g.
HostPort myhost(&Serial, 0xFFFFFFFF, 0xFFFFFFEE)
where Serial is the used port for communication (USB in this case), 0xFFFFFFFF are 4 bytes (uint32) of start bytes (i.e. header), 
while 0xFFFFFFEE are 4 bytes (uint32) of stop bytes (i.e. terminator).
To attach an object to trasmit use in the setup
myhost.attachTx((uint8_t*) object, sizeof(object))
where (uint8_t*) object is the object pointer (i.e. the RAM address of its first byte), while sizeof(object) its size (in bytes).
The number of objects that can be trasmitted is MAX_NUM (defined in this file), while the max number of bytes is BUF_SIZE (defined
in this file), including header and terminator bytes.
Use myhost.write() to transmit the object (usually used in the loop)
Simiarly, an object can be attached and receive
myhost.attachRx((uint8_t*) object, sizeof(object)) //in the setup
myhost.read() //in the loop

Class written by SL, 11-22-2021
*/

#ifndef _HOSTPORT_H
#define _HOSTPORT_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define BUF_SIZE 256 //size of buffers
#define MAX_OBJS 3 //max num of attached objects
#define MASK_HOSTPORT 0x000000FF //mask for bitwise operations
#define TIMEOUT_HOSTPORT 500 //timeout (us)

class HostPort {
public:
	//constructors
	HostPort(Stream* serial, uint32_t startBytes, uint32_t stopBytes); //constructor with both header and terminator
	HostPort(Stream* serial, uint32_t startBytes); //constructor with header only
	HostPort(Stream* serial); //constructor w/o header and terminator

	//funs
	boolean attachRx(uint8_t* pointer, size_t size); //attach object for rx
	boolean attachTx(uint8_t* pointer, size_t size); //attach object for tx
	boolean write(); //write attached objects, return true if data written
	boolean read(); //read attached object, return true is data read

private:
	//funs
	void init(void); //general init in costructors
	void copyrx(void); //copy _rx_buf in _ptr_rx when reading was ok

	//vars
	uint8_t _rx_buf[BUF_SIZE]; //rx buffer
	uint8_t _tx_buf[BUF_SIZE]; //tx buffer
	uint32_t _start_bytes; //header bytes
	uint32_t _stop_bytes; //terminator bytes
	uint8_t* _ptr_rx[MAX_OBJS]; //rx pointer array
	uint8_t* _ptr_tx[MAX_OBJS]; //tx pointer array
	size_t _size_rx[MAX_OBJS]; //rx size array (in bytes)
	size_t _size_tx[MAX_OBJS]; //tx size array (in bytes)
	size_t _totSize_rx; //tot size of rx objects (in bytes)
	size_t _totSize_tx; //tot size of tx objects (in bytes)
	uint8_t _numObj_rx; //num of rx objects
	uint8_t _numObj_tx; //num of tx objects
	Stream* _serial; //port for communication
};

#endif