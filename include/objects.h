//variable & object file
//written by SL

#ifndef __OBJECTS_H__
#define __OBJECTS_H__

//namespaces
namespace LedMode {
	constexpr int8_t DEF = 0;
	constexpr int8_t LOG = 1;
	constexpr int8_t MTP = 2;
	constexpr int8_t ERR = 3;
}

//type def
struct ImuData_T { //raw acc (g), gyro (mdeg/s), and mag (mG) data
	int32_t accs_mg[3], gyros_mdps[3], mags_mG[3]; //imu and mag readings
	float gyros_offset[3]; //gyro offset (for zero)
};
struct Speed_T { //raw and filtered speed
	int16_t speed; //speed
	uint16_t dist; //distance
};
struct GPSData_T { //raw lat (deg), long (deg), speed (knots), fix
	boolean fix = 0;
	float lat, lon, speed;
};
struct RiderTorque_T { //raw steer torque and offset
	uint16_t riderTorque; //adc val (bit)
	float riderTorque_offset; //offset (for zero)
};
struct Steer_T { //raw steer torque and offset
	uint16_t steerPos; //adc val (bit)
	uint16_t steerVel; //adc val (bit)
	float steerVel_offset; //offset (for zero)
};
struct ForkDisp_T { //raw front fork displacement
	uint16_t forkDisp;
	float forkDisp_offset; //offset (for zero)
};
struct ActCurr_T { //raw actual motor current and offset
	uint16_t actCurr; //adc val (bit)
	float actCurr_offset; //offset (for zero)
};
struct Voltage_T {
	uint16_t batVolt; //battery voltage (bit)
	float batVolt_offset; //offset (for zero)
};
struct Counter_T {
	uint16_t speedSensor = 0, mag = 0, imu = 0, debug = 0, log = 0, LED = 0; //counter for lower sampling rate
};
struct Timing_T {
	uint32_t dt_cycle, duty_cycle, dt_debug, dt_logger; //time differences
};
struct debut_rx_T { //debug received packet
	float curr_ref;
	float throttle_ref;
};
struct Channel_T { //controller channels
  uint16_t ch0, ch1, ch2, ch3; //should be: ch0 speed ref, ch1 roll ref, ch2,ch3 logic channels
};

//global variables
uint32_t sampling_timer = 0; //timer
Timing_T timing; //timings
Counter_T counters; //counters for lower sampling rate
ImuData_T imuData_raw; //acc, gyro, and mag data and gyro offset
Speed_T speed_raw; //raw and filtered speed
GPSData_T gpsData_raw; //lat, long, speed, fix
RiderTorque_T riderTorque_raw; //raw steer torque and offset
ActCurr_T actCurr_raw; //raw actual motor current and offset
Steer_T steer_raw; //raw steer position and velocity and offset
ForkDisp_T forkDisp_raw; //raw front fork displacement
Voltage_T voltage_raw; //raw battery voltage
Channel_T channel_raw; //raw channels
uint8_t GPSserial_extra_buffer[GPS_EXTBUFSIZE];
uint32_t nanVal = NAN_VAL;
int8_t LEDmode = LedMode::DEF; //LED mode
boolean LEDstate = false; //state of LED
                             
//global objects
ISM330DHCXSensor imu(&USED_SPI, CS_IMU, SPISPEED_IMU); //imu object
LIS3MDLSensor mag(&USED_SPI, CS_MAG, SPISPEED_MAG); //mag object
ADC *adc = new ADC(); // adc object
Adafruit_GPS gps(&UART_GPS);
MCP492X dac(&USED_SPI, SPISPEED_DAC, CS_DAC); //dac object
ControlClass ctrl; //control loop object
SerialTransfer speedSensor; //SerialTransfer object for speed sensor
//SbusRx sbus(&UART_SBUS); //TODO sbus object for remote controller
#endif
