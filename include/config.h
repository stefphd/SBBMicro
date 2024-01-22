/*! \file config.h
	\brief General configurations for the source code.
	\details Configuration file with defines and macros for the source code of the 
	SBB Micro code. This includes PIN definitions, BUS settings, DAC settings, 
	definitions of constants and factors, conversions of raw data, 
	and other user-defined parameters.
	\note Building is necessary for changes to take effect.
	\see config bus pin constants macros userparams
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__


/*! @defgroup config Configurations
	\brief Settings, defines and macros.
	\details Defines and macros for the source code of the SBB Micro code. 
	This includes PIN definitions, BUS settings, DAC settings, 
	definitions of constants and factors, conversions of raw data, 
	and other user-defined parameters.
	\note Building is necessary for changes to take effect.
   @{
*/
//....................................BUSES....................................

/*! @defgroup bus Bus settings
   \brief Settings for the buses.
   \details Settings of the used buses for the communications with sensorsaand drivers. 
   This includes defines for the SPI and UART(s) used for the sensors, settings for the
   ADCs, DACs, and PWM.
	\warning Be careful to modify this parameters. Changes may lead to possible short circuits which kill the circuit.
   @{
 */

//SPI
#define USED_SPI		SPI1 //!< Used SPI for sensor IO bus.
#define SPISPEED_IMU	10e6 //!< Speed of IMU SPI, max is 10e6.
#define SPISPEED_MAG	10e6 //!< Speed of MAG SPI, max is 10e6.
#define SPISPEED_DAC	10e6 //!< Speed of MAG SPI, max is 20e6.

//UART
#define UART_SPEEDSENS	Serial7 //!< Used UART for speed sensor bus.
#define BAUD_SPEEDSENS	4e6 //!< Baudrate of the UART for speed sensor bus.
#define UART_GPS		Serial2 //!< Used UART for GPS sensor bus.
#define BAUD_GPS_DEF	9600 //!< Default baudrate of GPS sensor (for init only).
#define BAUD_GPS		57600 //!< Actual baudrate of GPS sensor.
#define GPS_EXTBUFSIZE	128 //!< Extra buffer size for GPS sensor UART.
#define UART_SBUS		Serial8 //!< Used UART for SBUS communication. /details The UART used for the SBUS receiver. This runs with a baudrate of 100000. Initialization and setting is performed by the SBUS library.

//ADC
#define ADC_RES			12 //!< ADC resolution (in bits).
#define ADC_AVERAGE		8 //!< ADC averaging 1/2/8/16 (samples). The more the averaging, the less the noise, but the more the reading time.

//DAC
#define DAC_RES			12 //!< DAC resolution (in bits).
#define DAC_MTR_CH		0 //!< DAC channel for motor control.
#define DAC_THROTTLE_CH 1 //!< DAC channel for throttle control.

//PWM
#define PWM_RES			12 //!< PWM resolution in bit (max is 14).
#define PWM_FREQ		5e3 //!< PWM frequency (max is 5kHz).
#define PWM_MIN			0.1F //!< Minimum PWM value for motor current reference.
#define PWM_MAX			0.9F //!< Maximum PWM value for motor current reference.

/*! @} */ 

//.....................................PINS....................................

/*! @defgroup pin Pin settings
   \brief Settings for the pins.
   \details Used pins in the Teensy 4.1 microcontroller. 
   This includes the chip-select pins used for the SPI, analog input
   pin to read analog signals, PWM pin, and digital in and out pins.
   \warning Be careful to change the pin settings. Changes may lead to possible short circuits which kill the circuit.
   @{
 */

//SPI CS PINS
#define CS_IMU			0 //!< Chip select pin of IMU.
#define CS_MAG			2 //!< Chip select pin of MAG.
#define CS_DAC			3 //!< Chip select pin of DAC.

//ANALOG PINS
#define STEER_POS		A16 //!< Steer position analog input pin.
#define STEER_SPEED		A0 //!< Steer speed analog input pin.
#define ACT_CURR		A1 //!< Actual current analog input pin.
#define RIDER_TRQ		A17 //!< Rider torque analog input pin.
#define VOLTAGE			A15 //!< Battery voltage analog input pin.
#define FORK_DISP		A14 //!< Front fork displacement analog input pin.

//PWM
#define PWM_PIN			18 //!< PWM pin for motor current reference.

//DIGITAL OUT
#define MTR_EN_PIN		16 //!< Digital out for motor enable.
#define MTR_DIR_PIN		17 //!< Digital out for motor direction.
#define RELAY_EN_PIN	33 //!< Digital out for relay enable.
#define BR_DIR_PIN		21 //!< Digital out for brake motor direction.
#define BR_STEP_PIN		22 //!< Digital out for brake motor step.
#define BR_SLEEP_PIN	23 //!< Digital out for brake motor sleep.

//DIGITAL IN 
#define ONOFF_STATE_PIN	36 //!< Digital in for on/off buttun state (diode between onoff and this).

/*! @} */ 

//.............................CONSTANTS & FACTORS.............................

/*! @defgroup constants Constants
   \brief Constant and factor definitions.
   \details Definition of the constants and factors. 
   This includes the fundamental sampling time and the sampling factors for sensors etc. 
   (expressed in units of the fundamental sempling time), the output data rate of sensors, 
   the gains, offsets, and conversions for sensors and units, and limits values.
   @{
 */

//TIMES
#define SAMPLING_TIME		1e3 //!< Sampling time of the control loop (us). \details This is also the fundamental sampling time of the system. All other sampling times are expresed in units of this value. \warning Must be consistent with that in Simulink. 
#define SPEED_SAMPLING_FAC	1 //!< Sampling factor of speed sensor (expressed in units of #SAMPLING_TIME). \note This is the rate at which the sensor is read, not its output data rate. \warning Not used now. Speed sensor is read as fast as possible. \see SAMPLING_TIME
#define IMU_SAMPLING_FAC	1 //!< Sampling factor of IMU (expressed in units of #SAMPLING_TIME). \note This is the rate at which the sensor is read, not its output data rate (i.e. #ACC_ODR or #GYRO_ODR). \see SAMPLING_TIME ACC_ODR GYRO_ODR
#define MAG_SAMPLING_FAC	5 //!< Sampling factor of magnetometer (expressed in units of #SAMPLING_TIME). \note This is the rate at which the sensor is read, not its output data rate (i.e. #MAG_ODR). \see SAMPLING_TIME MAG_ODR
#define SBUS_SAMPLING_FAC	14 //!< Sampling factor of the SBUSr receiver. \note This is the rate at which the sensor is read, not its output data rate. \warning Not used now. SBUS is read as fast as possible. \see SAMPLING_TIME
#define DEF_LED 			500 //!< Sampling factor of led in default mode (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME LedMode::DEF
#define LOG_LED 			500 //!< Sampling factor of led in log mode (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME LedMode::LOG
#define MTP_LED 			250 //!< Sampling factor of led in mtp mode (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME LedMode::MTP
#define ERR_LED 			10000 //!< Sampling factor of led in error mode (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME LedMode::ERR
#define MTPWAIT_LED			100 //!< Sampling factor of led in mtp wait mode (expressed in units of #SAMPLING_TIME). \see SAMPLING_TIME LedMode::MTPWAIT

//OUTPUT DATA RATE
#define ACC_ODR			3333 //!< Output data rate of accelerometer (sps). \note This is not the rate at which the sensor is read (i.e. #IMU_SAMPLING_FAC). \see IMU_SAMPLING_FAC
#define GYRO_ODR		3333 //!< Output data rate of gyrometer (sps). \note This is not the rate at which the sensor is read (i.e. #IMU_SAMPLING_FAC). \see IMU_SAMPLING_FAC
#define MAG_ODR			200 //!< Output data rate of magnetometer (sps). \note This is not the rate at which the sensor is read (i.e. #MAG_SAMPLING_FAC). \see MAG_SAMPLING_FAC

//GAINS & CONVERSION
#define SPEED_SCALE		1.0e-3F //!< Speed scale. \details mm/s to m/s.
#define DIST_SCALE		0.25F //!< Distance scale. \details Units of 0.25m to m.
#define ACC_SCALE		(-1.0e-3F*9.806F) //!< Acceleration scale. \details mg to m/s^2. -1 is to have actual accelerations (no the inertial ones).
#define GYRO_SCALE		(1.0e-3F*PI/180.0F) //!< Gyrometer scale \details mdps to rad/s.
#define MAG_SCALE		0.1F //!< Magnetometer scale. \details mG to uT.
#define GPSSPEED_SCALE	0.5144F //!< GPS speed scale. \details Knots to m/s.
#define GAIN_RIDERTRQ	0.141F //!< Gain of rider torque (Nm/(mV/V), with 5V supply). \details Value from torsiometer calibration.
#define OFFSET_RIDERTRQ -(324.11*GAIN_RIDERTRQ) //!< Offset of rider torque (mV/V). \details Value from torsiometer calibration. Actually this is not strickly necessary, since a zero procedure is performed in do_zeros(). 
#define GAIN_STEERPOS	50.9F/180.0F*PI //!< Fain of steer position. \details Value from steer-angle sensor calibration.
#define OFFSET_STEERPOS -30.7F/180.0F*PI //!< Offset of steer position. \details Value from steer-angle sensor calibration.
#define GAIN_STEERVEL	(2.0F*1000.0F/60.0F*2.0F*PI) //!< Gain of steer velocity. \details Value from ESCON Studio.
#define OFFSET_STEERVEL (-1000.0F/60.0F*2.0F*PI) //!< Offset of steer velocity. \details Value from ESCON Studio.
#define GAIN_ACTCURR	2*MAX_REFCUR //!< Gain of actual motor current. \details Value from ESCON Studio.
#define OFFSET_ACTCURR	-MAX_REFCUR //!< Offset of actual motor current. \details Value from ESCON Studio.
#define GAIN_VOLTAGE	3.3F*1.027F*160.0F/10.0F //!< Gain of voltage. \details Value from voltage divider resistors (10k and 150k) and a correction factor from a calibartion.
#define OFFSET_VOLTAGE	0.0F //!< Offset of voltage. \details No offset necessary.
#define GAIN_FORKDISP	-152.935F //!< Fain of front fork displacement. \details Value from frok-displacement sensor calibartion.
#define OFFSET_FORKDISP 0.107F //!< Offset of front fork displacement. \details Value from frok-displacement sensor calibartion.
#define GYROX_OFFSET    +0.0059F/GYRO_SCALE //!< Offset of gyro x. \details Value from offset calibration of the IMU.
#define GYROY_OFFSET    -0.0066F/GYRO_SCALE //!< Offset of gyro y. \details Value from offset calibration of the IMU.
#define GYROZ_OFFSET    -0.0080F/GYRO_SCALE //!< Offset of gyro z. \details Value from offset calibration of the IMU.

//SBUS
#define NUM_CH_SBUS		7 //!< Number channels from SBUS. \details Number of the stored channel from the SBUS. \see RemoteCtrl
#define MAX_SBUS		1811 //!< Maximum value from SBUS. \details Maximum value received by the SBUS.
#define MIN_SBUS		172 //!< Minimum value from SBUS. \details Minimum value received by the SBUS.
#define ZERO_SBUS		992 //!< Zero-value for SBUS. \details Value corresponding to zero for the SBUS. This is hust the average of #MAX_SBUS and #MIN_SBUS. \see MAX_SBUS MIN_SBUS
#define TRESHOLD_LOGIC_SBUS	1400 //!< Treshold for SBUS logic channels. \details Treshold value for logic state received by the SBUS. If greaten than this value, it is a high state. \attention This value should be larger than #ZERO_SBUS, in order to recognize it as a low state. \see ZERO_SBUS
#define TRESHOLD_POS_SBUS	1400 //!< Treshold for positive value. \details Treshold value for positive state received by the SBUS. If greaten than this value, it is a +1.
#define TRESHOLD_NEG_SBUS	600 //!< Treshold for negative value. \details Treshold value for positive state received by the SBUS. If lower than this value, it is a -1.
#define MAX_MISSING_SBUS	10*SBUS_SAMPLING_FAC //!< Maximum missing packets for SBUS. \details Maximum missing packets for the SBUS communication. \note Check for missing packet is performed avery #SAMPLING_TIME milliseconds. \see SAMPLING_TIME
#define MAX_REF_INPUT	1 //!< Maximum value for input reference. \details Maximum value for the input reference in the control model. Signals from SBUS (int16_t) are remapped within #MIN_SBUS and #MAX_SBUS as float numbers. \see MIN_SBUS MAX_SBUS CONVERT_CHANNEL_TO_FLOAT
#define MIN_REF_INPUT	-1 //!< Minimum value for input reference. \details Minimum value for the input reference in the control model.  Signals from SBUS (int16_t) are remapped within #MIN_SBUS and #MAX_SBUS as float numbers. \see MIN_SBUS MAX_SBUS CONVERT_CHANNEL_TO_FLOAT
#define SBUS_THROTTLE_CH 2 //!< Throttle channel in SBUS. \details Channel of SBUS for throttle reference. \warning Channel number is one-based.
#define SBUS_ROLL_CH	1 //!< Roll channel in SBUS. \details Channel of SBUS for roll reference. \warning Channel number is one-based.
#define SBUS_EN_CH		5 //!< Enable channel in SBUS. \details Channel of SBUS for enable signal. \warning Channel number is one-based.
#define SBUS_BR_CH		6 //!< brake channel in SBUS. \details Channel of SBUS for brake signal. \warning Channel number is one-based.
#define SBUS_THR_OR		3 //!< Direct throttle channel in SBUS. \details Channel of SBUS for overrideing the throttle channel. \warning Channel number is one-based.
#define SBUS_SEL_CH		7 //!< 3 selector channel in SBUS. \warning Channel number is one-based.

//LIMITS
#define MAX_REFCUR		10 //!< Maximum reference current. \warning Must be consistent with that in ESCON studio and Simulink. 
#define MAX_REFTHROTTLE 1.0F //!< Maximum throttle value. \warning Must be consistent with that in Simulink. 
#define MIN_VOLTAGE		15 //!< Minimum battery voltage (undervoltage) (V).
#define MAX_VOLTAGE		40 //!< Maximum battery voltage (overvoltage) (V).
#define MAX_STEER_ANGLE 0.35 //!< Maximum steering angle. \details Maximum steering angle above which motor drivers are disabled and the system stops.

//BRAKE MOTOR
#define MAX_BR_SPEED	10 //!< Maximum brake motor speed (mm/s).
#define MAX_BR_ACC		25 //!< Maximum brake motor acceleration (mm/s2).
#define BR_STEPS		200 //!< Number of steps of the brake motor.
#define BR_SPEED_RATIO 	1 //!< Speed ratio of the brake motor to brake lever (mm/revolution).
#define MAX_BR_DISP 	12.0F //!< Maximum brake lever displacement (mm).

/*! @} */

//....................................MACROS....................................

/*! @defgroup macros Macros
   \brief Macro definitions.
   \details Definition of the macros for conversions and utilities.
   This includes definitions of macros for unit conversions and utilities, such such enable macros.
   @{
*/

//CONVERSIONS
/*! \brief Convert rider torque to Nm.
	\details Macro for the conversion of the rider torque from raw value (in bits from the ADC) to Nm.
	The macro makes use of #GAIN_RIDERTRQ, #OFFSET_RIDERTRQ, and #ADC_RES to remap the values using a linear interpolation.
	\param X The ADC value to convert (in bits).
	\return The value in Nm.
	\see ADC_RES GAIN_RIDERTRQ OFFSET_RIDERTRQ
*/
#define CONVERT_RIDERTRQ_TO_NM(X)		(GAIN_RIDERTRQ * X / (powf(2, ADC_RES) - 1) * 3.3F / 5.0F * 1.0e3 + OFFSET_RIDERTRQ) //macro for conversion of rider torque to Nm

/*! \brief Convert steer position to radiants.
	\details Macro for the conversion of the steer position from raw value (in bits from the ADC) to radiants.
	The macro makes use of #GAIN_STEERPOS, #OFFSET_STEERPOS, and #ADC_RES to remap the values using a linear interpolation.
	\param X The ADC value to convert (in bits).
	\return The value in radiants.
	\see ADC_RES GAIN_STEERPOS OFFSET_STEERPOS
*/
#define CONVERT_STEERPOS_TO_RAD(X)		(GAIN_STEERPOS * X / (powf(2, ADC_RES) - 1) + OFFSET_STEERPOS) //macro for conversion of steer position to rad

/*! \brief Convert steer rate to rad/s.
	\details Macro for the conversion of the steer rate from raw value (in bits from the ADC) to rad/s.
	The macro makes use of #GAIN_STEERVEL, #OFFSET_STEERVEL, and #ADC_RES to remap the values using a linear interpolation.
	\param X The ADC value to convert (in bits).
	\return The value in rad.
	\see ADC_RES GAIN_STEERVEL OFFSET_STEERVEL
*/
#define CONVERT_STEERVEL_TO_RADPS(X)	((GAIN_STEERVEL * X / (powf(2, ADC_RES) - 1) + OFFSET_STEERVEL)/STEERVEL_RATIO) //macro for conversion of steer velocity to rad/s

/*! \brief Convert steer rate to rad/s.
	\details Macro for the conversion of the steer rate from raw value (in bits from the ADC) to rad/s.
	The macro makes use of #GAIN_STEERVEL, #OFFSET_STEERVEL, and #ADC_RES to remap the values using a linear interpolation.
	\param X The ADC value to convert (in bits).
	\return The value in rad.
	\see ADC_RES GAIN_STEERVEL OFFSET_STEERVEL
*/
#define CONVERT_ACTCURR_TO_A(X)			(-(GAIN_ACTCURR * X / (powf(2, ADC_RES) - 1) + OFFSET_ACTCURR)) //macro for conversion of actual motor current to A

/*! \brief Convert reference current to PWM value.
	\details Macro for the conversion of the reference current to a PWM value.
	The macro makes use of #MAX_REFCUR, #PWM_MIN, #PWM_MAX, and #PWM_RES to remap the values using a linear interpolation. The sign is removed.
	\param X The reference current.
	\return The PWM value.
	\see MAX_REFCUR PWM_MIN PWM_MAX PWM_RES
*/
#define CONVERT_CURRENT_TO_PWM(X)		(PWM_MIN * (powf(2, PWM_RES) - 1) + abs((PWM_MAX - PWM_MIN) * X / MAX_REFCUR * (powf(2, PWM_RES) - 1))) // convert the motor current to PWM value

/*! \brief Convert reference current to DAC value.
	\details Macro for the conversion of the reference current to a DAC value.
	The macro makes use of #MAX_REFCUR, and #DAC_RES to remap the values using a linear interpolation. The sign is removed.
	\param X The reference current.
	\return The DAC value.
	\see MAX_REFCUR DAC_RES
*/
#define CONVERT_CURRENT_TO_DAC(X)		abs(X / MAX_REFCUR * (powf(2, DAC_RES) - 1)) //convert the motor current to DAC value

/*! \brief Convert reference throttle to DAC value.
	\details Macro for the conversion of the reference throttle to a DAC value.
	The macro makes use of #MAX_REFTHROTTLE, and #DAC_RES to remap the values using a linear interpolation. The sign is removed.
	\param X The reference throttle.
	\return The DAC value.
	\see MAX_REFTHROTTLE DAC_RES
*/
#define CONVERT_TRHOTTLE_TO_DAC(X)  	(X / MAX_REFTHROTTLE * (powf(2, DAC_RES) - 1)) //convert the throttle to DAC value

/*! \brief Convert battery voltage to volts.
	\details Macro for the conversion of the battery voltage from raw value (in bits from the ADC) to volts.
	The macro makes use of #GAIN_VOLTAGE, #OFFSET_VOLTAGE, and #ADC_RES to remap the values using a linear interpolation.
	\param X The ADC value to conver (in bits).
	\return The value in volts.
	\see ADC_RES GAIN_VOLTAGE OFFSET_VOLTAGE
*/
#define CONVERT_VOLTAGE_TO_V(X)			(GAIN_VOLTAGE * X / (powf(2, ADC_RES) - 1) + OFFSET_VOLTAGE) //macro for conversion of battery voltage to V

/*! \brief Convert fork displacement to millimiters.
	\details Macro for the conversion of the fork displacement from raw value (in bits from the ADC) to millimiters.
	The macro makes use of #GAIN_FORKDISP, #OFFSET_FORKDISP, and #ADC_RES to remap the values using a linear interpolation.
	\param X The ADC value to conver (in bits).
	\return The value in volts.
	\see ADC_RES GAIN_FORKDISP OFFSET_FORKDISP
*/
#define CONVERT_FORKDISP_TO_MM(X)		(GAIN_FORKDISP * X / (powf(2, ADC_RES) - 1) + OFFSET_FORKDISP) //macro for conversion of front fork displacement to mm

/*! \brief Convert SBUS channel to float.
	\details Macro for the conversion of the value of a SBUS channel from int16_t to a float within a defined range.
	\param X The value of SBUS channel. It must be within #MIN_SBUS and #MAX_SBUS.
	\param XMIN The minimum value of the float.
	\param XMAX The maximum value of the float.
	\return The float value within MIN and MAX.
	\see MAX_SBUS MIN_SBUS
*/
#define CONVERT_CHANNEL_TO_FLOAT(X, XMIN, XMAX)	(float(X)-MIN_SBUS)/(MAX_SBUS-MIN_SBUS)*(XMAX-XMIN) + XMIN //macro for conversion of SBUS channels to floats

/*! \brief Convert brake lever position to motor steps.
	\details Macro for the conversion of the brake lever position (mm) to the number of steps of the steeper motor.
	\param X The brake lever position (mm).
	\return The number of steps of the steeper motor.
	\see BR_STEPS BR_SPEED_RATIO
*/
#define CONVERT_BRLEV_TO_STEPS(X) ((X*BR_STEPS)/BR_SPEED_RATIO)

/*! \brief Convert throttle to motor steps.
	\details Macro for the conversion of the throttle to the number of steps of the steeper motor.
	\param X The reference throttle.
	\return The number of steps of the steeper motor.
	\see CONVERT_BRLEV_TO_STEPS
*/
#define CONVERT_TRHOTTLE_TO_STEPS(X) CONVERT_BRLEV_TO_STEPS(X / MAX_REFTHROTTLE * MAX_BR_DISP)

#define USB_CONNECTED		(!bitRead(USB1_PORTSC1,7)) //!< Macro for checking the USB connection status- \details See https://forum.pjrc.com/threads/70721-detecting-usb-connection-on-a-teensy-4-0

//ENABLES
#define MTR_EN_STATE	HIGH //!< Enable state for steer motor.
#define RELAY_EN_STATE	HIGH //!< Enable state for relay.
#define BR_SLEEP_STATE  HIGH //!< Enable state for brake motor.
#define MTR_ENABLE		digitalWriteFast(MTR_EN_PIN, MTR_EN_STATE), delay(100) //!< Macro for motor enable. \see MTR_EN_PIN MTR_EN_STATE
#define RELAY_ENABLE	digitalWriteFast(RELAY_EN_PIN, RELAY_EN_STATE), delay(500) //!< Macro for relay enable. \see RELAY_EN_PIN RELAY_EN_STATE
#define BR_ENABLE 		digitalWriteFast(BR_SLEEP_PIN, BR_SLEEP_STATE) //!< Macro for brake motor enable. \see BR_SLEEP_PIN BR_SLEEP_STATE
#define BR_DISABLE 		digitalWriteFast(BR_SLEEP_PIN, !BR_SLEEP_STATE) //!< Macro for brake motor enable. \see BR_SLEEP_PIN BR_SLEEP_STATE
#define LEDON			digitalWriteFast(LED_BUILTIN, HIGH) //!< Macro for LED on. \details Standard value for LED_BUILTIN is 13 in the Arduino environment.
#define LEDOFF			digitalWriteFast(LED_BUILTIN, LOW) //!< Macro for LED off. \details Standard value for LED_BUILTIN is 13 in the Arduino environment.

//POWER MANAGEMENT
#define POWER_OFF		SNVS_LPCR |= (1<<6) //!< Macro for turning off the microcontroller. \details Refer to the MCU manual for details. \see https://forum.pjrc.com/threads/59125-Is-there-a-hook-to-know-when-the-on-off-pin-on-the-Teensy-4-0-has-been-grounded

/*! @} */

//...................................USER PARAMS.................................

/*! @defgroup userparams User paramters
   \brief User-defined parameters.
   \details Definition of the user-defined paramters and other miscellanous constants. 
   @{
*/

#define CPU_FREQ			600e6 //!< CPU clock speed (Hz). /warning Maximum value is 816e6 without cooling. \see https://www.pjrc.com/store/teensy40.html
#define MTR_CTRL_MODE		1 //!< Control mode of steer motor (0=PWM or 1=DAC). \warning This setting must be consistent with ESCON Studio.
#define EN_LONG_CTRL		0 //!< Enable the longitudinal control.
#define EN_REMOTE_CTRL 		0 //!< Enable the remote controller.
#define CW					LOW //!< Digital pin state for clockwise torque.
#define NUM_ZERO_SAMPLES	500 //!< Samples used to perform the zero of sensors.
#define STEERVEL_RATIO		(-36.0*1.25) //!< Speed ratio of steer velocity. \details Values from Simulink model.
#define FULLEXT_FORKDISP	0 //!< Fork displacement at full extended suspension (in mm).
#define NAN_VAL				0xFFC00000 //!< NaN value used for invalid data.
#define YINCL_MCUBOX		1.3426 //!< Pitch iinclination of MCU box (in rad). \details Value of 76.928deg, found from a static calibration with the IMU.
const float imu_rotMat[3][3] = { {0, -cosf(YINCL_MCUBOX), -sinf(YINCL_MCUBOX)}, 
								  {-1, 0, 0},  
								  {0, sinf(YINCL_MCUBOX), -cosf(YINCL_MCUBOX)} }; //!< Rotation matrix from IMU frame to SAE body-fixed frame. \details This is the result of Rz(90deg)*Rx(180deg)*Ry(#YINCL_MCUBOX). \see YINCL_MCUBOX
const float mag_rotMat[3][3] = { {cosf(YINCL_MCUBOX), 0, sinf(YINCL_MCUBOX)},
								  {0, -1, 0}, 
								  {-sinf(YINCL_MCUBOX), 0, cosf(YINCL_MCUBOX)} }; //!< Rotation matrix from MAG frame to SAE body-fixed frame. \details This is the result of Ry(180deg)*Ry(#YINCL_MCUBOX). \see YINCL_MCUBOX
//#define SWEEP_TEST
//#define SIN_TEST
//#define TEST_DURATION 10e3
//#define SIN_WAVE 4
//#define IMP_TEST					//!< Flag for impulse test. \details Impulse test consists of a cosine-shaped impulse with amplitude #IMP_AMP and duration #IMP_DUR. 
#define IMP_DUR				100 	//!< Impulse duration (ms). \see IMP_TEST
#define IMP_AMP				-10.0 	//!< Impulse amplitude (A). \see IMP_TEST



/*! @} */

//.......................................EOF.....................................

/*! @} */ 

#endif
