
#ifndef __LOG_H__
#define __LOG_H__

/*! \file logger.h
	\brief Definitions of logger functions and variables.
	\details File to defined the logger functions and variables. Function prototypes are in prototypes.h.
	\see logfun prototypes.h
*/

//defines
#define DOLOG 				1 //!< Enable or disable logging (1/0). \ingroup logfun
#define LOG_SAMPLING_FAC	1 //!< Sampling factor of data logging (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME \ingroup logfun
#define sd					SD.sdfs //!< SD fat object (uses sd fat included in SD library). \ingroup logfun
#define SD_CONFIG			SdioConfig(FIFO_SDIO) //!< Configuration type of sd card. \ingroup logfun
#define PREALLOC			1024L*1024L*1024L //!< Log file preallocation (in bytes). \ingroup logfun
#define DATAPACKET_SIZE		sizeof(float)*64 //!< Size of logged data packet (in bytes). \details Note that sizeof(float)=4. \ingroup logfun
#define RING_BUF_SIZE		DATAPACKET_SIZE*10 //!< Size of the ring buffer. \details Bytes of data packet multiplied by the buffered samples. \ingroup logfun
#define SDSECTOR_SIZE		512 //!< Size of the SD sector (in bytes). \details Note that it is a multiple of #DATAPACKET_SIZE \ingroup logfun
#define FILENAME_MAXSIZE	32 //!< Max length of the name of the log file. \details Standard length of the name should be 27 chars w/ format log_YYYY-MM-DD_hh.mm.ss.sbb. \see FILENAME_FORMAT \ingroup logfun
#define FILENAME_FORMAT		"log_%04d-%02d-%02d_%02d.%02d.%02d.sbb" //!< Log filename format. \details The current name format is log_YYYY-MM-DD_hh.mm.ss.sbb. \ingroup logfun
#define FILENAME_ENTRIES	year(), month(), day(), hour(), minute(), second() //!< Entries of the log filename format. \details Please refer to #FILENAME_FORMAT for the filename format used. \ingroup logfun \see FILENAME_FORMAT

#if DOLOG == 1

//variables and objects
boolean doLog = true; //!< True when logging. \ingroup logfun
char filename[FILENAME_MAXSIZE] = { 0 }; //!< Log filename. \ingroup logfun
float fill_packet[(DATAPACKET_SIZE - sizeof(ControlClass::controlModel_U) - sizeof(ControlClass::controlModel_Y)) / sizeof(float)]; //!< Fill the data packet. \details Float array to fill the data packet with NaN for invalid values. \see NAN_VAL \ingroup logfun
uint64_t logSampleWritten = 0; //!< Number of logged bytes \details The number of the written bytes into the log file, in order to troncate the file correctly at the end. \see log_closer() \ingroup logfun
FsFile logFile; //!< Log file object. \ingroup logfun
RingBuf<FsFile, RING_BUF_SIZE> log_buf; //!< Ring buffer object. \details Ring buffer object with base class FsFile and size #RING_BUF_SIZE. \see RING_BUF_SIZE \ingroup logfun

//start logger function
void start_logger(void) {

	//start SD card
	if (!sd.begin(SD_CONFIG)) doLog = false;

	//create filename 
	sprintf(filename, FILENAME_FORMAT, FILENAME_ENTRIES);

	//create log file
	logFile = sd.open(filename, O_RDWR | O_CREAT | O_TRUNC);
	if (!logFile) doLog = false;
	logFile.preAllocate(PREALLOC);

	//begin ring buffer
	log_buf.begin(&logFile);

	//fill log_packet with nan vals
	for (int i = 0; i < (sizeof(fill_packet) / sizeof(float)); i++) fill_packet[i] = *((float*) &nanVal);
  
  if (doLog) LEDmode = LedMode::LOG;
}

//log closer function
void log_closer(void) {
	if (doLog) {
		log_buf.writeOut(log_buf.bytesUsed());
		logFile.flush();
		logFile.truncate(DATAPACKET_SIZE*logSampleWritten);
		logFile.close();
		doLog = false;
		LEDmode = LedMode::DEF;
	}
}


//do log stuff
void do_logger(void) {
	uint32_t startWriteLogTime = micros();

	if (!doLog) {
		return;
	}

	//write data to buffer
	if (counters.log == 0) {

		//write to ring buffer
		log_buf.write((uint8_t*) &ctrl.controlModel_U, sizeof(ControlClass::controlModel_U));
		log_buf.write((uint8_t*) &ctrl.controlModel_Y, sizeof(ControlClass::controlModel_Y));
		log_buf.write((uint8_t*) &fill_packet[0], sizeof(fill_packet));
		logSampleWritten++;

		//reset counter
		counters.log = LOG_SAMPLING_FAC - 1;
	}
	else counters.log--;


	//check used bytes in ring buffer
	size_t ringBufBytesUsed = log_buf.bytesUsed();
	if ((ringBufBytesUsed + logFile.curPosition() > (PREALLOC - DATAPACKET_SIZE))) {
		log_closer();
		return;
	}

	//write out SDSECTOR_SIZE bytes from ring buffer if logFile is free
	if ((ringBufBytesUsed >= SDSECTOR_SIZE) && !logFile.isBusy()) {
		if (SDSECTOR_SIZE != log_buf.writeOut(SDSECTOR_SIZE)) {
			log_closer(); //issue if written-out bytes are not equal to SDSECTOR_SIZE
			return;
		}
	}
                       
	//timing
	timing.dt_logger = micros() - startWriteLogTime;
}

#else //empty funs if not logging
void start_logger(void) {}
void do_logger(void) {}
void log_closer(void) {}
//add more empty logging functions here if necessary

#endif
#endif
