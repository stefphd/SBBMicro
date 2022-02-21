//logger file
//written by SL

#ifndef __LOG_H__
#define __LOG_H__

#define DOLOG //enable logging - comment to disable

#ifdef DOLOG

//defines
#define LOG_SAMPLING_FAC	2 //sampling factor of data logging (expressed in units of SAMPLING_TIME)
#define sd					SD.sdfs //sd card obj (uses sd fat now included in SD library w/ teensyduino)
#define SD_CONFIG			SdioConfig(FIFO_SDIO) //configuration of sd card
#define PREALLOC			1024L*1024L*1024L //file preallocation (bytes)
#define DATAPACKET_SIZE		sizeof(float)*64 //size of data packet (bytes)
#define RING_BUF_SIZE		DATAPACKET_SIZE*10 //ring buffer size (bytes of data packet multiplied by buffered samples)
#define SDSECTOR_SIZE		512 //size of SD sector (bytes)
#define FILENAME_MAXSIZE	32 //max length of filename (standard length should be 27 chars) w/ format log_YYYY-MM-DD_hh.mm.ss.sbb
#define FILENAME_FORMAT		"log_%04d-%02d-%02d_%02d.%02d.%02d.sbb" //filename string format (now log_YYYY-MM-DD_hh.mm.ss.sbb)
#define FILENAME_ENTRIES	year(), month(), day(), hour(), minute(), second() //filename format entries

//variables and objects
volatile boolean doLog = true; //true when logging ok - volatile b/c used in on/off irq
char filename[FILENAME_MAXSIZE] = { 0 }; //filename
float fill_packet[(DATAPACKET_SIZE - sizeof(ControlClass::controlModel_U) - sizeof(ControlClass::controlModel_Y)) / sizeof(float)];
volatile uint64_t logSampleWritten = 0; //written logged bytes (to troncate the file correctly at the end)
FsFile logFile; //logfile obj
RingBuf<FsFile, RING_BUF_SIZE> log_buf; //ring buffer

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
