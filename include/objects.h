
#ifndef __OBJECTS_H__
#define __OBJECTS_H__

/*! \file objects.h
	\brief Declaration of types, objects and variables.
	\details File to declare namespace, type definition, and global variables and objects.
	\see vars
*/

/*! @defgroup vars Variables
    \brief Declarations of variables and objects.
    \details Definitions of data types and declarations of the global variables and objects, 
	including namespaces and structs.
	\see objects.h
   @{
*/

//namespaces
/*! \brief Led mode constants.
	\details The namespace contains constants for the status LED mode. Depending on the LED blinking, 
    the microcontroller mode is:
    - Default mode without signal-logging: LEDmode is LedMode::DEF, LED blinks depending on #DEF_LED.
    - Default mode with signal-logging: LEDmode is LedMode::LOG, LED blinks depending on #LOG_LED.
    - MTP mode: LEDmode is LedMode::MTP, LED blinks depending on #MTP_LED.
    - Error mode: LEDmode is LedMode::ERR, LED blinks depending on #ERR_LED.
	- MTP wait for USB connected: LEDmode is LedMode::MTPWAIT, LED blicks depending on #MTPWAIT_LED
    \ingroup do_led logfun mtpfun
*/
namespace LedMode {
	constexpr int8_t DEF = 0; //!< Default mode without signal-logging.
	constexpr int8_t LOG = 1; //!< Default mode with signal-logging.
	constexpr int8_t MTP = 2; //!< MTP mode.
	constexpr int8_t ERR = 3; //!< Error mode.
	constexpr int8_t MTPWAIT = 4; //!< MTP wait for USB connected.
}

//strcut def
/*! \brief IMU raw data.
	\details The struct contains the raw data from the IMU (not rotated) and the offsets of the gyrometers:
	- Accelerations are in g.
	- Angular velocities are in mdeg/s.
	- Magnetic field is in mG.
	Accelerations and angular velocities are expressed in the accelorometer-fixed frame, while the 
	magnetic field in the magnetometer-fixed frame.

	\see constants
    \ingroup vars
*/
struct ImuData { //raw acc (g), gyro (mdeg/s), and mag (mG) data
	int32_t accs_mg[3]; //!< Raw accelerations (in g). \details x,y,z values are expressed in the accelorometer-fixed frame. \see ACC_SCALE
	int32_t gyros_mdps[3]; //!< Raw angular velocities (in mdeg/s). \details x,y,z values are expressed in the accelorometer-fixed frame. \see GYRO_SCALE
	int32_t mags_mG[3]; //!< Raw magnetic field (in mG). \details x,y,z values are expressed in the magnetometer-fixed frame. \see MAG_SCALE
	float gyros_offset[3]; //!< Gyrometer offsets (in mdeg/s). \see GYROX_OFFSET GYROY_OFFSET GYROZ_OFFSET
};

/*! \brief Speed raw data.
	\details The struct contains the raw data from the speed sensor:
	- Speed is in cm/s.
	- Distance is in units of 0.25m.

	\see constants
    \ingroup vars
*/
struct Speed { //raw and filtered speed
	int16_t speed; //!< Vehicle speed (in mm/s). \see SPEED_SCALE
	uint16_t dist; //!< Elapsed distance (in units of 0.25m). \see DIST_SCALE
};

/*! \brief GPS raw data.
	\details The struct contains the raw data from the GPS:
	- Latitude and longitude are in degrees.
	- Speed is in knots.

	\see constants
    \ingroup vars
*/
struct GPSData { //raw lat (deg), long (deg), speed (knots), fix
	boolean fix = false; //!< Fix value. \details Fix is true when the GPS is connected and works.
	float lat; //!< Latitude (in degrees).
	float lon; //!< Longitude (in degrees).
	float speed; //!< Ground speed (in knots). \see GPSSPEED_SCALE
};

/*! \brief Torsiometer raw data.
	\details The struct contains the raw data from the torsiometer.
	- Rider torque is in bits.
	- Rider torque offset is in Nm.

	\see constants macros
    \ingroup vars
*/
struct RiderTorque { //raw steer torque and offset
	uint16_t riderTorque; //!< Rider torque (in bits). \details Measured value from the ADC. \see RIDER_TRQ CONVERT_RIDERTRQ_TO_NM
	float riderTorque_offset; //!< Rider torque offset (in Nm). \details The value is found from a zero procedure at the startup. \see do_zeros() 
};

/*! \brief Steering raw data.
	\details The struct contains the raw data from the steering sensors.
	- Steering angle and rate are in bits.
	- Steering rate offset is in rad/s.

	\see constants macros
    \ingroup vars
*/
struct Steer { //raw steer torque and offset
	uint16_t steerPos; //!< Steering angle (in bits). \details Measured value from ADC at the steering shaft. \see STEER_POS CONVERT_STEERPOS_TO_RAD
	uint16_t steerVel; //!< Steering rate (in bits). \details Measured value from ADC at the steer-motor shaft. \see STEER_SPEED CONVERT_STEERVEL_TO_RADPS STEERVEL_RATIO
	float steerVel_offset; //!< Steering rate offset (in rad/s). \details The value is found from a zero procedure at the startup. \see do_zeros() 
};

/*! \brief Fork displacement raw data.
	\details The struct contains the raw data from the fork displacement sensor.
	- Fork displacement is in bits.
	- Fork displacement offset in in mm.

	\see constants macros
    \ingroup vars
*/
struct ForkDisp { //raw front fork displacement
	uint16_t forkDisp; //!< Fork displacement (in bits). \details Measured value from ADC. \see FORK_DISP CONVERT_FORKDISP_TO_MM
	float forkDisp_offset; //!< Fork displacement offset (in mm). \see FULLEXT_FORKDISP
};

/*! \brief Actual motor current raw data.
	\details The struct contains the raw data of the motor actual current.
	- Actual current is in bits.
	- Actual current offset in in A.

	\see constants macros
    \ingroup vars
*/
struct ActCurr { //raw actual motor current and offset
	uint16_t actCurr; //!< Actual current (in bits). \details Measured value from ADC. \see ACT_CURR CONVERT_ACTCURR_TO_A
	float actCurr_offset; //Actual current offset (in A). \details The value is found from a zero procedure at the startup. \see do_zeros() 
};

/*! \brief Battery voltage raw data.
	\details The struct contains the raw data of the battery voltage.
	- Battery voltage is in bits.
	- Battery voltage offset is V.

	\see constants macros
    \ingroup vars
*/
struct Voltage {
	uint16_t batVolt; //!< Battery voltage (in bits). \details Measured value from ADC at the steering shaft. \see VOLTAGE CONVERT_VOLTAGE_TO_V
	float batVolt_offset = 0; //!< Battery voltage offset (inV). \details The value is set to 0. \see do_zeros()
};

/*! \brief Counters for lower sampling rate.
	\details The struct contains counters for lower sampling rate than #SAMPLING_TIME.
	\see constants
    \ingroup vars
*/
struct Counter {
	uint16_t speedSensor = 0; //!< Counter for speed sensor. \see SPEED_SAMPLING_FAC
	uint16_t imu = 0; //!< Counter for IMU. \see IMU_SAMPLING_FAC
	uint16_t mag = 0; //!< Counter for magnetometer. \see MAG_SAMPLING_FAC
	uint16_t debug = 0; //!< Counter for debugging. \see debfun DEBUG_SAMPLING_FAC 
	uint16_t log = 0; //!< Counter for data logging. \see logfun LOG_SAMPLING_FAC
	uint16_t LED = 0; //!< Counter for LED blinking. \see LedMode DEF_LED LOG_LED MTP_LED ERR_LED
};

/*! \brief Time taken by functions.
	\details The struct contains values to count the time taken by functions.
    \ingroup vars
*/
struct Timing {
	uint32_t dt_cycle; //!< Cycle time. \details The time at which the main cycle is called. The value is equal to #SAMPLING_TIME, except for possible overrunning. \see SAMPLING_TIME
	uint32_t tet; //!< Task execution time. \details The Time taken by the whole cycle. The value is lower than #SAMPLING_TIME, except for possible overrunning. \see SAMPLING_TIME
	uint32_t dt_debug; //!< Debug time. \details The time taken by the debugging. The value is much lower than #SAMPLING_TIME, except for possible overrunning. \see debfun SAMPLING_TIME
	uint32_t dt_logger; //!< Logger time. \details The time taken by the data logging. The value is much lower than #SAMPLING_TIME, except for possible overrunning. \see logfun SAMPLING_TIME
	uint32_t max_tet = 0; //!< Maximum TET.
	uint32_t min_tet = -1; //!< Minimum TET.
};

/*! \brief Signals from remote controller.
	\details The struct contains values of the signals sent by the remote controller.
    \ingroup vars
*/
struct RemoteCtrl { //controller channels
	/*! \brief Channels from remote controller.
		\details The array contains values of the channels sent by the remote controller.
		The size of the array is #NUM_CH_SBUS. Current channels are:
		- Channel 1: up/down positoon of the left stick.
		- Channel 2: left/right positoon of the right stick.
		- Channel 3: up/down positoon of the right stick.
		- Channel 4: left/right positoon of the left stick.
		- Channel 5: logic state of the SD switch.
		- Channel 6: logic state of the SE switch.

		Values range from #MIN_SBUS to #MAX_SBUS and are initialized to #ZERO_SBUS. For logic channels the low state is #MIN_SBUS, while the
		high state is #MAX_SBUS.
		\note Channel type depends on the settings of remote controller. 
		\see NUM_CH_SBUS MIN_SBUS MAX_SBUS ZERO_SBUS
	*/
	int16_t ch[NUM_CH_SBUS] = { ZERO_SBUS }; 
	//bool lost_frame = true; // Lost frame. \details The lost frame is true when a frame is lost from the receiver. It is initialize to true (frame is lost at the begginging).
	uint32_t missing_frame = 0; //!< Number of missing frame. \details The counter increment when failing to read SBUS or frame is lost. The counter is reset when reading success. When #MAX_MISSING_SBUS is reached, an error is thrown. \see MAX_MISSING_SBUS
};

/*! \brief Save the IO startu status.
	\details The struct contains flags which identify if the corresponding IO is started successfully.
    \ingroup vars
*/
struct IOstatus {
	bool imu, accen, gyroen;
	bool mag, magen;
	bool dac;
	bool speedsens;
	bool gps;
	bool sbus;
};

//global variables
uint32_t sampling_timer = 0; //!< Timer for the main cycle. \details The timer is used to run the main cycle at a sampling time of #SAMPLING_TIME. \see SAMPLING_TIME
uint8_t GPSserial_extra_buffer[GPS_EXTBUFSIZE];
uint32_t nanVal = NAN_VAL; //!< NaN variable. \see logfun debfun NAN_VAL
int8_t LEDmode = LedMode::DEF; //!< LED mode variable. \details Default value is LedMode::DEF. \see LedMode
boolean LEDstate = false; //!< LED state. \see do_led()
Timing timing; //!< Timing of functions.
Counter counters; //!< Counters for lower sampling rate.
ImuData imuData_raw; //!< Raw data from IMU and magnetometer.
Speed speed_raw; //!< Raw data from speed sensor.
GPSData gpsData_raw; //!<Raw data from the GPS.
RiderTorque riderTorque_raw; //!< Raw data from the torsiometer.
ActCurr actCurr_raw; //!< Raw data from the motor current sensor.
Steer steer_raw; //!< Raw data from the steering sensors.
ForkDisp forkDisp_raw; //!< Raw data from the fork-displacement sensor.
Voltage voltage_raw; //!< Raw data from the battery voltage sensor.
RemoteCtrl remote_raw; //!< Channels from the remote controller.
IOstatus iostatus; //!< IO status flags.

//global objects
ISM330DHCXSensor imu(&USED_SPI, CS_IMU, SPISPEED_IMU); //!< IMU object (accelerometer and gryometer).
LIS3MDLSensor mag(&USED_SPI, CS_MAG, SPISPEED_MAG); //!< Magnetometer object.
ADC *adc = new ADC(); //!< Pointer to ADC object.
Adafruit_GPS gps(&UART_GPS); //!< GPS object.
MCP492X dac(&USED_SPI, SPISPEED_DAC, CS_DAC); //!< DAC object.
ControlClass ctrl; //!< Control object.
SerialTransfer speedSensor; //!< SerialTransfer object for speed sensor.
SbusRx sbus(&UART_SBUS); //!< SBUS object for remote controller.
TS4::Stepper brakeMotor(BR_STEP_PIN, BR_DIR_PIN); //!< Stepper object for the brake motor.

//other user vars
int8_t enable_old = 0;
int8_t enable_new = 0;
uint32_t test_timer = 0, test_start = 0;


/*! @} */

#endif