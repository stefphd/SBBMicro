
#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

/*! \file prototypes.h
	\brief Declaration of prototypes.
	\details File for the declaration of all function prototypes. Function definitions are in 
    main.cpp, logger.h, sbbmtp.h, userfun.h, debug.h.
	\see main.cpp logger.h sbbmtp.h userfun.h debug.h
*/

// prototypes for functions.h
/*! @defgroup userfun User functions
   \brief User-defined functions.
   \details Definition of the user defined functions called in main().
   \see main userfun.h
   @{
*/

/*! \brief Get the CPU temperature.
	\details Extern function to get the CPU temperature in Celsius degrees.
    \return The CPU temperature in Celsius degrees.
    \see https://forum.pjrc.com/threads/59813-Teensy-4-0-Internal-Temperature-measurement
*/
extern float tempmonGetTemp(void);

/*! \brief Set the CPU clock.
	\details Extern function to set the CPU clock.
    \param frequency The CPU clock in Hz.
    \return The actual CPU frequency in Hz.
    \see https://forum.pjrc.com/threads/57444-How-to-change-clock-speed-on-Teensy-4-0
*/
extern "C" uint32_t set_arm_clock(uint32_t frequency);

/*! \brief Initialize the IO buses.
	\details Function to initialize the IO buses for the sensors and drivers. This incluses
    initialization of SPI and the related sensors (IMU, magnetometer, and DAC), 
    initialization of the UARTs for the speed sensor and GPS.
    \see USED_SPI UART_SPEEDSENS UART_GPS
*/
void start_IObus(void);

/*! \brief Start the IO buses.
	\details Function to start the IO buses for the sensors and drivers after initialization. 
    This incluses the setting of sensors (IMU, magnetometer, GPS, ADC, PWM and DAC).
*/
void set_IObus(void);

/*! \brief Perform the zero.
	\details Function to perform the zero-calibration of some sensors. These include
     the torsiometer, the actual motor current and the actual steer rate. It also sets
     the pre-defined offsets (e.g. for the gyrometer).
    \see RiderTorque::riderTorque_offset GYROX_OFFSET GYROY_OFFSET GYROZ_OFFSET
*/
void do_zeros(void);

/*! \brief Set the GPIO.
	\details Function to set general-purpose input-output digital pins, depending on their usage. 
    This also includes the assignment of a default (initial) state for the digital output pins.
*/
void set_GPIO(void);

/*! \brief Start the brake stepper motor.
	\details Function to start and set the stepper motor acting on the brake lever.
*/
void start_brake_stepper(void);

/*! \brief Get sensor readings.
	\details Function to get the sensor readings (raw values only). Sensors are read with the specified sampling factor.
    \see SAMPLING_TIME SPEED_SAMPLING_FAC IMU_SAMPLING_FAC MAG_SAMPLING_FAC
*/
void get_sensors(void);

/*! \brief Update the control loop.
	\details Function to convert sensor readings to convenient units and update the control loop with the new sensor readings.
    \see macros
*/
void do_control(void);

/*! \brief Check for errors.
	\details Function to check for possible errors, such as unfeasible values of signals or limit exceeding.
    A error state variable is modified if errors are found.
*/
void check_error(void);

/*! \brief Check for SBUS.
	\details Function to check for unfeasible values of SBUS channels, which must be within #MIN_SBUS and #MAX_SBUS.
    The function checks also for lost frame and fail safe.
    \return True if success, false for errors.
    \see MIN_SBUS MAX_SBUS
*/
bool check_sbus(void);

/*! \brief Set the drivers.
	\details Function to set the drivers, such as the steer-motor driver and the throttle via the DAC. Drivers are set only if no error is found.
    \see macros
*/
void set_driver(void);

/*! \brief Callback for tuning off.
	\details Callback function called when the microcontroller turns of, in order to end stuff before (e.g. close the log file).
*/
void turnoff_callback(void);

/*! \brief Check the battery voltage.
	\details Function to check possible under- or over-voltage of the battery.
    \return True if the battery voltage is between #MIN_VOLTAGE and #MAX_VOLTAGE (no under- or over-voltage occured).
    \see MIN_VOLTAGE MAX_VOLTAGE
*/
boolean check_voltage(void);

/*! \brief Get internal RTC time.
	\details Function to get the internal RTC time of the microcontroller.
    \return The internal RTC time, as a time_t type, which are the seconds elapsed from 1970 1 Jan 00:00:00.
*/
time_t getTime(); 

/*! \brief Management of the status LED.
	\details Function to manage the status LED according to the microcontroller mode. Depending on the LED blinking, 
    the microcontroller mode is:
    - Default mode without signal-logging: LEDmode is LedMode::DEF, LED blinks depending on #DEF_LED.
    - Default mode with signal-logging: LEDmode is LedMode::LOG, LED blinks depending on #LOG_LED.
    - MTP mode: LEDmode is LedMode::MTP, LED blinks depending on #MTP_LED.
    - Error mode: LEDmode is LedMode::ERR, LED blinks depending on #ERR_LED.
    \see LedMode DEF_LED LOG_LED MTP_LED ERR_LED
*/
void do_led();

/*! \brief Flush the UARTs.
	\details Function to flush the receive buffer of the UARTs.
    \see UART_SPEEDSENS UART_GPS
*/
void serial_flush();

/*! @} */


//prototypes for logger.h

/*! @defgroup logfun Data logging
    \brief Functions and definitions for signal logging.
    \details Definition of the logger functions, variables, and macros. This include functions to initialize 
    the logger, log the signals, and close the log when the microcontroller turns off.
    The signal logging makes use of the built-in SD card using SDIO card configuration for best performances.
    The logger creates a *.sbb file where signals are saved in binary (as float types, i.e. 4 bytes per value) 
    in group of #DATAPACKET_SIZE bytes per sample. This means a maximum number of signal logged of 
    #DATAPACKET_SIZE/sizeof(float). The data packet is filled with NaN values untill the defined size is reached.    
    A ring buffer is used to write to the SD card only when free, in order to have a low
    writing time. Logging rate is defined by #LOG_SAMPLING_FAC, while the maximum log file dimension is #PREALLOC (in bytes).
    During logging the LEDmode is LedMode::LOG, and status LED blinks depending on #LOG_LED.
    Data logging is not active in MTP mode.
   \see logger.h NAN_VAL LedMode LOG_LED mtpfun
   @{
*/

/*! \brief Initialize the logger.
	\details Function to initialize the logger. It initializes the SD card and create a log file with 
    name having format log_YYYY-MM-YY_hh.mm.ss.sbb.
    \see FILENAME_FORMAT
*/
void start_logger(void);

/*! \brief Close the log file.
	\details Function to flush, truncate, and close the log file. The function is called when turning off the microcntroler, or
    when the maximum log file dimension is reached or a logging error occurs.
*/
void log_closer(void);

/*! \brief Log signals.
	\details Function to log and write the signals to the ring buffer at a sampling rate defined by #LOG_SAMPLING_FAC. 
    The ring buffer is written out to the log file every #SAMPLING_TIME and when the SD card is free, for best performance in terms of writing time.
    The function must be called continously at a sampling rate of #SAMPLING_TIME.
    \see LOG_SAMPLING_FAC SAMPLING_TIME
*/
void do_logger(void);

/*! @} */


//prototypes for sbbmtp.h

/*! @defgroup mtpfun MTP
    \brief Functions and definitions for MTP mode.
    \details Definition of the MTP functions, variables, and macros. This include functions to initialize 
    and run the MTP mode. MTP (standing for media-transfer-protocol) is a communication protocol that 
    allows media files to be transferred automatically to and from portable devices. In particular, the MTP
    mode allows transferring of the log files from the built-in SD card to a PC via USB. 
    To enter in MTP mode, it is sufficient to keep the on/off button pressed for at least #MTP_ENABLE_TIMEOUT 
    milliseconds when turning on. 
    During logging the LEDmode is LedMode::MTP, and status LED blinks depending on #MTP_LED.
    To get the MTP mode working in the PC side:
    - Windows: no additional operation is usually necessary, the microcontroller should be automatically 
    recognized as an MTP device.
    - Linux: install *gMTP* (from [https://gmtp.sourceforge.io/downloads.htmls](https://gmtp.sourceforge.io/downloads.htmls)), 
    which is a MTP client for UNIX and UNIX like systems (this should include the *libmtp* library).

   \see sbbmtp.h LedMode::MTP MTP_LED
   @{
*/


/*! \brief Check for MTP mode.
	\details Function to check the on/off button state with a timeout of #MTP_ENABLE_TIMEOUT milliseconds 
    and to initialize the built-in SD card.
    If SD card initization fails, the MTP mode is not enabled.
    \return True for entering in MTP mode, false otherwise.
    \see MTP_ENABLE_TIMEOUT
*/
bool check_mtp(void);

/*! \brief Run MTP mode.
	\details Function to initialize the MTP and to run the MTP loop. 
    If the USB is not connected, the MTP loop is not run.
    The function is blocking.
*/
void do_mtp(void);

/*! @} */

//prototypes for debug.h

/*! @defgroup debfun Debugging
    \brief Functions and definitions for debugging.
    \details Definition of the debug functions, variables, and macros. This includes functions to initialize 
    and run the debug. Debug consists of:
    - streaming of singals to a possible host PC in real-time.
    - receiving of signals from a possible host PC in real-time, in order to set the drivers manually.

    The signal streaming and receiving is performed using the HostPort class via USB/serial, with a rate defined 
    by #DEBUG_SAMPLING_FAC. 4-bytes header and terminator, defined by 
    #HEADER and #TERMINATOR, are used to indicate the begin and end of the data packet trasmitted or received.
    Trasmitted signals are those in the control input ctrl.controlModel_U and output ctrl.controlModel_Y.
    Received signals are the reference current and throttle, which are used to override the 
    corresponding signals in ctrl.controlModel_Y and to set the drivers.
    If no signals are received for more that #MAX_MISSING_READS times or NaN values are receive for a signal, 
    the corresponding signal in ctrl.controlModel_Y is not overrided.
    Debug is not active in MTP mode.
    \see debug.h HostPort NAN_VAL mtpfun
   @{
*/

/*! \brief Initialize the debug.
	\details Function to initialize the HostPort. It also attaches to the HostPort the objects to trasmit and receive.
    Receive buffer is initialize with NaN values.
    \see HostPort NAN_VAL
*/
void start_debug(void);

//The function must be called continously at a sampling rate of #SAMPLING_TIME.

/*! \brief Stream and receive signals.
	\details Function to stream and receive signals at a sampling rate defined by #DEBUG_SAMPLING_FAC.
    When signals are received, the corresponding signal in ctrl.controlModel_Y is overrided in order to 
    set the driver manually.
    The function must be called continously at a sampling rate of #SAMPLING_TIME.
    \see DEBUG_SAMPLING_FAC SAMPLING_TIME
*/
void do_debug(void);

/*! @} */

#endif