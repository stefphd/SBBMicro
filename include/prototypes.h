//function prototypes
//written by SL

#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

//prototypes for main.cpp

/*! @defgroup mainfun Entry-point functions
   \brief Entry-point functions of the Arduino environment.
   \details Definition of the entry-point functions setup() and loop() used in the Arduino environment. 
   The main function is automatically created during compilation by the Arduino builder.
   \see main.cpp
   @{
*/

/*! \brief Setup function of Arduino environment.
	\details The setup funtion runs once when the microcontroller turns on. It initializes and sets the buses, 
    enables the main relay, and performs initial checks.
*/
void setup();

/*! \brief Loop function of Arduino environment.
	\details The loop function runs over and over again forever, untill the microcontroller turns off.
    A non-blocking timer is used with a sampling time of #SAMPLING_TIME. During the cycle the function reads 
    the sensors, converts the readings into convenient units, performs a control steps, checks possible errors, 
    sets the drivers, does debug stuff, and finally logs all the necessary signals.
    \see SAMPLING_TIME
*/
void loop();

/*! @} */


// prototypes for functions.h
/*! @defgroup userfun User functions
   \brief User-defined functions.
   \details Definition of the user defined functions called in setup() and loop().
   \see setup() loop() userfun.h
   @{
*/

/*! \brief Initialize the IO buses.
	\details Function to initialize the IO buses for the sensors and drivers. This incluses
    initialization of SPI and the related sensors (IMU, magnetometer, and DAC), 
    initialization of the UARTs for the speed sensor and GPS.
    \see USED_SPI UART_SPEEDSENS UART_GPS
*/
void start_IObus(void);

/*! \brief Set the IO buses.
	\details Function to set the IO buses for the sensors and drivers after initialization. 
    This incluses the setting of sensors (IMU, magnetometer, GPS, ADC, PWM and DAC).
*/
void set_IObus(void);

/*! \brief Perform the zero.
	\details Function to perform the zero-calibration of some sensors. These include
     the torsiometer, the actual motor current and the actual steer rate. It also sets
     the pre-defined offsets (e.g. for the gyrometer).
    \see GYROX_OFFSET GYROY_OFFSET GYROZ_OFFSET
*/
void do_zeros(void);

/*! \brief Set the GPIO.
	\details Function to set general-purpose input-output digital pins, depending on their usage. 
    This also includes the assignment of a default (initial) state for the digital output pins.
*/
void set_GPIO(void);

/*! \brief Get sensor readings.
	\details Function to get the sensor readings (raw values only). Sensors are read with the specified sampling factor.
    \see SAMPLING_TIME SPEED_SAMPLING_FAC IMU_SAMPLING_FAC MAG_SAMPLING_FAC
*/
void get_sensors(void);

/*! \brief Update the control loop.
	\details Function to convert sensor readings to convenient units and update the control loop with the new sensor readings.
*/
void do_control(void);

/*! \brief Check for errors.
	\details Function to check for possible errors, such as unfeasible values of signals or limit exceeding.
    A error state variable is modified if errors are found.
*/
void check_error(void);

/*! \brief Set the drivers.
	\details Function to set the drivers, such as the steer-motor driver and the throttle via the DAC. Drivers are set only if no error is found,
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
	\details Function to flush the receive buffer of the UARTs before calling loop().
    \see UART_SPEEDSENS UART_GPS loop()
*/
void serial_flush();

/*! @} */


//prototypes for logger.h

/*! @defgroup logfun Logger functions
    \brief Functions for signal logging.
    \details Definition of the logger functions. This includes function to initialize the logger, log the signals, 
    and close the log when the microcontroller turns off.
    The signal logging makes use of the built-in SD card using SDIO card configuration for best performances.
    The logger creates a *.sbb file where signals are saved in binary (as float types, i.e. 4 bytes per value) 
    in group of #DATAPACKET_SIZE bytes per sample. This means a maximum number of signal logged of 
    #DATAPACKET_SIZE/sizeof(float). A ring buffer is used to write to the SD card only when free, in order to have a low
    writing time.
   \see logger.h SD_CONFIG DATAPACKET_SIZE
   @{
*/

/*! \brief Initialize the logger.
	\details Function to initialize the logger. It initializes the SD card and create a log file with 
    name having format log_YYYY-MM-YY_hh.mm.ss.sbb.
    \see FILENAME_FORMAT
*/
void start_logger(void);

/*! \brief Initialize the logger.
	\details Function to initialize the logger. It initializes the SD card and create a log file with 
    name having format log_YYYY-MM-YY_hh.mm.ss.sbb.
    \see FILENAME_FORMAT
*/
void log_closer(void);
void do_logger(void);

/*! @} */


//prototypes for sbbmtp.h
bool check_mtp(void);
void do_mtp(void);

//prototypes for debug.h
void start_debug(void);
void do_debug(void);


#endif