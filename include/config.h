//configuration file
//written by SL

#ifndef __CONFIG_H__
#define __CONFIG_H__

//....................................BUSES....................................
//SPI
#define USED_SPI		SPI1 //used SPI for sensor IO bus
#define SPISPEED_IMU	10e6 //speed of IMU SPI, max is 10e6
#define SPISPEED_MAG	10e6 //speed of MAG SPI, max is 10e6
#define SPISPEED_DAC	10e6 //speed of MAG SPI, max is 20e6

//UART
#define UART_SPEEDSENS	Serial7 //used UART for speed sensor bus
#define BAUD_SPEEDSENS	4e6 //used UART for speed sensor bus
#define UART_GPS		Serial2 //used UART for GPS sensor bus
#define BAUD_GPS_DEF	9600 //default baudrate of GPS sensor (for init only)
#define BAUD_GPS		57600 //actual baudrate of GPS sensor
#define GPS_EXTBUFSIZE	128 //extra buffer size for GPS sensor serial

//ADC
#define ADC_RES			12 //adc resolution (bits)
#define ADC_AVERAGE		8 //adc averaging 1/2/8/16 (samples) - the more the averaging, the less the noise, but the more the reading time

//DAC
#define DAC_RES			12 //dac resolution (bits)
#define DAC_MTR_CH		0 //DAC channel for motor control
#define DAC_THROTTLE_CH 1 //DAC channel for throttle control

//PWM
#define PWM_RES			12 //pwm resolution in bit (max is 14)
#define PWM_FREQ		5e3 //pwm frequency (max is 5kHz)
#define PWM_MIN			0.1F //min pwm for motor current reference
#define PWM_MAX			0.9F //max pwm for motor current reference


//.....................................PINS....................................
//SPI CS PINS
#define CS_IMU			0 //chip select pin of IMU
#define CS_MAG			2 //chip select pin of MAG
#define CS_DAC			3 //chip select pin of DAC

//ANALOG PINS
#define STEER_POS		A16 //steer position analog in
#define STEER_SPEED		A0 //steer speed analog in
#define ACT_CURR		A1 //actual current analog in
#define RIDER_TRQ		A17 //rider torque analog in
#define VOLTAGE			A15 //battery voltage
#define FORK_DISP		A14 //front fork displacement
//PWM
#define PWM_PIN			18 //pwm pin for motor current reference

//DIGITAL OUT
#define MTR_EN_PIN		16 //digital out for motor enable
#define MTR_DIR_PIN		17 //digital out for motor direction
#define RELAY_EN_PIN	33 //digital out for relay enable pin

//DIGITAL IN 
#define ONOFF_STATE_PIN	34 //digital in for on/off buttun state (diode between onoff and this)	

//.............................CONSTANTS & FACTORS.............................
//TIMES
#define SAMPLING_TIME		1e3 //sampling time of control (us) - must be consistent with that in Simulink! 
// SAMPLING_TIME is also the fundamental sampling time of the system - all other sampling times are expresed in units of SAMPLING_TIME
#define SPEED_SAMPLING_FAC	1 //sampling factor of speed sensor (expressed in units of SAMPLING_TIME) - now speed sensor data are read as soon as sent
#define IMU_SAMPLING_FAC	1 //sampling factor of speed sensor (expressed in units of SAMPLING_TIME)
#define MAG_SAMPLING_FAC	5 //sampling factor of speed sensor (expressed in units of SAMPLING_TIME)
#define DEF_LED 			1000 //sampling factor of led in default mode
#define LOG_LED 			500 //sampling factor of led in log mode
#define MTP_LED 			250 //sampling factor of led in mtp mode
#define ERR_LED 			10000 //sampling factor of led in error mode

//OUTPUT DATA RATE
#define ACC_ODR			3333 //ODR of accelerometer (sps)
#define GYRO_ODR		3333 //ODR of gyrometer (sps)
#define MAG_ODR			200 //ODR of magnetometer (sps)

//GAINS & CONVERSION
#define SPEED_SCALE		1.0e-3F //speed scale, now cm/s to m/s
#define DIST_SCALE		0.25F //distance scale, now units of 0.25m to m
#define ACC_SCALE		(1.0e-3F*9.806F) //acceleration scale, now mG to m/s^2
#define GYRO_SCALE		(1.0e-3F*PI/180.0F) //gyrometer scale, now mdps to rad/s
#define MAG_SCALE		0.1F //magnetometer scale, now mG to uT
#define GPSSPEED_SCALE	0.5144F //GPS speed scale, now knots to m/s
#define GAIN_RIDERTRQ	0.141F //gain of rider torque (Nm/(mV/V), 5V supply) - from calibration
#define OFFSET_RIDERTRQ -(324.11*GAIN_RIDERTRQ) //offset of rider torque (mV/V), actually not strickly necessary, since a zero procedure is performed in the setup() - from calibration
#define GAIN_STEERPOS	50.9F/180.0F*PI //gain of steer position - from calibration
#define OFFSET_STEERPOS -29.7F/180.0F*PI //offset of steer position - from calibration
#define GAIN_STEERVEL	(2.0F*8000.0F/60.0F*2.0F*PI) //gain of steer velocity - from ESCON Studio
#define OFFSET_STEERVEL (-8000.0F/60.0F*2.0F*PI) //offset of steer velocity - from ESCON Studio
#define GAIN_ACTCURR	2*MAX_REFCUR //gain of actual motor current - from ESCON Studio
#define OFFSET_ACTCURR	-MAX_REFCUR //offset of actual motor current - from ESCON Studio
#define GAIN_VOLTAGE	3.3F*1.027F*160.0F/10.0F //gain of voltage - from voltage divider resistors (10k and 150k) and correction factor
#define OFFSET_VOLTAGE	0.0F //offset of voltage - no offset w/ voltage divider
#define GAIN_FORKDISP	-152.935F //gain of front fork displacement
#define OFFSET_FORKDISP 0.107F //offset of front fork displacement
#define GYROX_OFFSET    +0.0059F/GYRO_SCALE //offset of gyro x
#define GYROY_OFFSET    -0.0066F/GYRO_SCALE //offset of gyro y
#define GYROZ_OFFSET    -0.0080F/GYRO_SCALE //offset of gyro z

//LIMITS
#define MAX_REFCUR		controlParams.maxCurrent //max reference current (according to ESCON studio and Simulink)
#define MAX_REFTHROTTLE 1.0F //max throttle value (according to Simulink)
#define MIN_VOLTAGE		18 //min battery voltage (undervoltage) (V)
#define MAX_VOLTAGE		35 //max battery voltage (overvoltage) (V)

//....................................MACROS....................................

//CONVERSIONS
#define CONVERT_RIDERTRQ_TO_NM(X)		(GAIN_RIDERTRQ * X / (powf(2, ADC_RES) - 1) * 3.3F / 5.0F * 1.0e3 + OFFSET_RIDERTRQ) //macro for conversion of rider torque to Nm
#define CONVERT_STEERPOS_TO_RAD(X)		(GAIN_STEERPOS * X / (powf(2, ADC_RES) - 1) + OFFSET_STEERPOS) //macro for conversion of steer position to rad
#define CONVERT_STEERVEL_TO_RADPS(X)	((GAIN_STEERVEL * X / (powf(2, ADC_RES) - 1) + OFFSET_STEERVEL)/STEERVEL_RATIO) //macro for conversion of steer velocity to rad/s
#define CONVERT_ACTCURR_TO_A(X)			(GAIN_ACTCURR * X / (powf(2, ADC_RES) - 1) + OFFSET_ACTCURR) //macro for conversion of actual motor current to A
#define CONVERT_CURRENT_TO_PWM(X)		(PWM_MIN * (powf(2, PWM_RES) - 1) + abs((PWM_MAX - PWM_MIN) * X / MAX_REFCUR * (powf(2, PWM_RES) - 1))) // convert the motor current to PWM value
#define CONVERT_CURRENT_TO_DAC(X)		abs(X / MAX_REFCUR * (powf(2, DAC_RES) - 1)) //convert the motor current to DAC value
#define CONVERT_TRHOTTLE_TO_DAC(X)  	abs(X / MAX_REFTHROTTLE * (powf(2, DAC_RES) - 1)) //convert the throttle to DAC value
#define CONVERT_VOLTAGE_TO_V(X)			(GAIN_VOLTAGE * X / (powf(2, ADC_RES) - 1) + OFFSET_VOLTAGE) //macro for conversion of battery voltage to V
#define CONVERT_FORKDISP_TO_MM(X)		(GAIN_FORKDISP * X / (powf(2, ADC_RES) - 1) + OFFSET_FORKDISP) //macro for conversion of front fork displacement to mm


//ENABLES
#define MTR_EN_STATE	HIGH //digital pin state for motor enable
#define RELAY_EN_STATE	HIGH //digital pin state for relay enable
#define MTR_ENABLE		digitalWriteFast(MTR_EN_PIN, MTR_EN_STATE), delay(100) //macro for motor enable
#define RELAY_ENABLE	digitalWriteFast(RELAY_EN_PIN, RELAY_EN_STATE), delay(500) //macro for relay enable
#define LEDON			digitalWriteFast(LED_BUILTIN, HIGH)
#define LEDOFF			digitalWriteFast(LED_BUILTIN, LOW)

//POWER MANAGEMENT
#define POWER_OFF		SNVS_LPCR |= (1<<6) //turn off MCU

//...................................USER PARAMS.................................
#define CPU_FREQ			600e6 //CPU frequency (Hz)
#define MTR_CTRL_MODE		1 //motor control mode (0=PWM or 1=DAC)
#define CW					LOW //digital pin state for clockwise torque
#define NUM_ZERO_SAMPLES	500 //samples used to do zero of sensors
#define STEERVEL_RATIO		(controlParams.beltRatio*controlParams.gearRatio) //speed ratio of steer velocity
#define FULLEXT_FORKDISP	0 //fork displacement at full extended suspension
#define NAN_VAL				0xffc00000 //nan value
#define YINCL_MCUBOX		1.3426 //inclination of MCU box (rad) - now 76.928deg
const float imu_rotMat[3][3] = { {0, cosf(YINCL_MCUBOX), sinf(YINCL_MCUBOX)}, 
								  {1, 0, 0},  
								  {0, sinf(YINCL_MCUBOX), -cosf(YINCL_MCUBOX)} }; //rotation matrix for IMU frame to SAE frame, now Rz(90deg)*Rx(180deg)
const float mag_rotMat[3][3] = { {cosf(YINCL_MCUBOX), 0, sinf(YINCL_MCUBOX)},
								  {0, -1, 0}, 
								  {sinf(YINCL_MCUBOX), 0, -cosf(YINCL_MCUBOX)} }; //rotation matrix for MAG frame to SAE frame, now Rx(180deg)

#endif
