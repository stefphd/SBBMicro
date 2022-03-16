
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

/*! \file userfun.h
	\brief Definitions of user functions.
	\details File to defined the user-defined functions, except for those related to the logging, debugging, and mtp-mode.
	Function prototypes are in prototypes.h.
	\see userfun prototypes.h
*/

/*
void set_buses(void) starts the IO buses
*/
void start_IObus(void) {
	USED_SPI.begin(); //start sensor SPI
	//start imu, mag, and dac
	imu.begin();
	mag.begin();
	dac.begin();
	//start speed-sensor UART
	UART_SPEEDSENS.begin(BAUD_SPEEDSENS);
	speedSensor.begin(UART_SPEEDSENS);
	//CCM_CSCDR1 = 105450240; //UART_CLK_SEL bit set to 0 - to use baudrate of serial above 6e6 Mbit/s, see https://forum.pjrc.com/threads/67150-Teensy4-1-MAX-baud-rate
	//start gps UART
	UART_GPS.begin(BAUD_GPS_DEF);
	UART_GPS.addMemoryForRead(GPSserial_extra_buffer, sizeof(GPSserial_extra_buffer));
	/*delay(66);
	gps.sendCommand(PMTK_SET_BAUD_57600), delay(66);
	UART_GPS.end(), delay(66);
	UART_GPS.begin(BAUD_GPS);*/
	//start sbus
	//sbus.Begin(); //TODO sbus
}

/*
void set_IObus(void) sets the IO (sensors, ADC, DAC, etc.)
*/
void set_IObus(void) {
	//enable sensors
	imu.ACC_Enable();
	imu.GYRO_Enable();
	mag.Enable();
	gps.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY);

	//set sensor rates
	imu.GYRO_SetOutputDataRate(GYRO_ODR);
	imu.ACC_SetOutputDataRate(ACC_ODR);
	mag.SetODR(MAG_ODR);
	gps.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ); 

	//set adc
	adc->adc0->setAveraging(ADC_AVERAGE); // set number of averages
	adc->adc0->setResolution(ADC_RES); // set bits of resolution
	adc->adc0->setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED); // change the conversion speed
	adc->adc0->setSamplingSpeed(ADC_SAMPLING_SPEED::HIGH_SPEED); // change the sampling speed
	adc->adc1->setAveraging(ADC_AVERAGE); // set number of averages
	adc->adc1->setResolution(ADC_RES); // set bits of resolution
	adc->adc1->setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED); // change the conversion speed
	adc->adc1->setSamplingSpeed(ADC_SAMPLING_SPEED::HIGH_SPEED); // change the sampling speed

	//set pwm
#if MTR_CTRL_MODE==0
	analogWriteResolution(PWM_RES);
	analogWriteFrequency(PWM_PIN, PWM_FREQ);
	analogWrite(PWM_PIN, CONVERT_CURRENT_TO_PWM(0));
#endif
	//set dac
	dac.analogWrite(DAC_MTR_CH, CONVERT_CURRENT_TO_DAC(0));
	dac.analogWrite(DAC_THROTTLE_CH, 0);
}

/*
void do_zeros(void) does the zero of sensor with offset (like torsiometer and gyro)
*/
void do_zeros(void) {
	//inits
	uint16_t c = 0; //counter	
	riderTorque_raw.riderTorque_offset = 0;
	actCurr_raw.actCurr_offset = 0;
	steer_raw.steerVel_offset = 0;
	//cycle with SAMPLING_TIME
	while (c < NUM_ZERO_SAMPLES) { //do NUM_ZERO_SAMPLES cycles
		if ((micros() - sampling_timer) >= SAMPLING_TIME) {
			sampling_timer = micros(); //update timer
			//gyro
			//...
			//torsiometer
			riderTorque_raw.riderTorque_offset += CONVERT_RIDERTRQ_TO_NM(float(analogRead(RIDER_TRQ)));
			//actual motor current
			actCurr_raw.actCurr_offset += CONVERT_ACTCURR_TO_A(float(analogRead(ACT_CURR)));
			//motor speed
			steer_raw.steerVel_offset += CONVERT_STEERVEL_TO_RADPS(float(analogRead(STEER_SPEED)));
			//fork displacement
			//forkDisp_raw.forkDisp_offset += CONVERT_FORKDISP_TO_MM(float(analogRead(FORK_DISP)));

			//increase the counter
			c++; 

		}
	}
	//compute averages
	riderTorque_raw.riderTorque_offset = riderTorque_raw.riderTorque_offset / float(NUM_ZERO_SAMPLES);
	actCurr_raw.actCurr_offset		   = actCurr_raw.actCurr_offset / float(NUM_ZERO_SAMPLES);
	steer_raw.steerVel_offset		   = steer_raw.steerVel_offset / float(NUM_ZERO_SAMPLES);
	voltage_raw.batVolt_offset		   = 0;
	forkDisp_raw.forkDisp_offset	   = FULLEXT_FORKDISP; // forkDisp_raw.forkDisp_offset / float(NUM_ZERO_SAMPLES);
	imuData_raw.gyros_offset[0]		   = GYROX_OFFSET;
	imuData_raw.gyros_offset[1]		   = GYROY_OFFSET;
	imuData_raw.gyros_offset[2]		   = GYROZ_OFFSET;
}

/*
void set_GPIO(void) sets the GPIO pins
*/
void set_GPIO(void) {
	pinMode(MTR_EN_PIN, OUTPUT);
	pinMode(MTR_DIR_PIN, OUTPUT);
	pinMode(RELAY_EN_PIN, OUTPUT);
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(ONOFF_STATE_PIN, INPUT_PULLUP);
	digitalWriteFast(MTR_EN_PIN, !MTR_EN_STATE);
	digitalWriteFast(MTR_DIR_PIN, CW);
	digitalWriteFast(RELAY_EN_PIN, !RELAY_EN_STATE);
}

/*
void get_sensors(void) gets the sensor readings
*/
void get_sensors(void) {
	//imu
	if (counters.imu == 0) {
		imu.ACC_GetAxes(imuData_raw.accs_mg);
		imu.GYRO_GetAxes(imuData_raw.gyros_mdps);
		counters.imu = IMU_SAMPLING_FAC - 1;
	}
	else counters.imu--;

	//mag
	if (counters.mag == 0) {
		mag.GetAxes(imuData_raw.mags_mG);
		counters.mag = MAG_SAMPLING_FAC - 1;
	}
	else counters.mag--;

	//speed
	if (counters.speedSensor == 0) {
		if (speedSensor.available()) speedSensor.rxObj(speed_raw);
		counters.speedSensor = SPEED_SAMPLING_FAC - 1;
	}
	else counters.speedSensor--;

	//gps
	gps.read();
	if (gps.newNMEAreceived()) {
		gps.parse(gps.lastNMEA());
		gpsData_raw.fix = gps.fix;
		if (gpsData_raw.fix) {
			gpsData_raw.lat = gps.latitudeDegrees;
			gpsData_raw.lon = gps.longitudeDegrees;
			gpsData_raw.speed = gps.speed*GPSSPEED_SCALE;
			if (gps.lat == 'S') gpsData_raw.lat *= -1;
			if (gps.lon == 'W') gpsData_raw.lon *= -1;
		}
		else {
			gps.lat = NAN;
			gps.lon = NAN;
			gps.speed = NAN;
		}
	}

	//analogs
	actCurr_raw.actCurr = analogRead(ACT_CURR);
	riderTorque_raw.riderTorque = analogRead(RIDER_TRQ);
	steer_raw.steerPos = analogRead(STEER_POS);
	steer_raw.steerVel = analogRead(STEER_SPEED);
	voltage_raw.batVolt = analogRead(VOLTAGE);
	forkDisp_raw.forkDisp = analogRead(FORK_DISP);

	//sbus TODO
	/*
	if (sbus.Read()) {
		remote_ctrl.ch0 = sbus_rx.ch(0);
		remote_ctrl.ch1 = sbus_rx.ch(1);
		blabla other channels for enable brake etc...
	}
	*/
}

/*
void do_control(void) sets the control input structure for next step and perform control update cycle
*/
void do_control(void) {
	//set speed
	ctrl.controlModel_U.speed = SPEED_SCALE*float(speed_raw.speed);
	ctrl.controlModel_U.dist = DIST_SCALE * float(speed_raw.dist);
	//set the threee components of accs, gyros, mags
	for (int i = 0; i < 3; i++) {
		ctrl.controlModel_U.accs[i] = float(imuData_raw.accs_mg[0] * imu_rotMat[i][0] + 
											imuData_raw.accs_mg[1] * imu_rotMat[i][1] + 
											imuData_raw.accs_mg[2] * imu_rotMat[i][2]) * ACC_SCALE;
		ctrl.controlModel_U.gyros[i] = ((float(imuData_raw.gyros_mdps[0]) - imuData_raw.gyros_offset[0]) * imu_rotMat[i][0] + 
										(float(imuData_raw.gyros_mdps[1]) - imuData_raw.gyros_offset[1]) * imu_rotMat[i][1] + 
										(float(imuData_raw.gyros_mdps[2]) - imuData_raw.gyros_offset[2]) * imu_rotMat[i][2] ) * GYRO_SCALE; //may have also offset
		ctrl.controlModel_U.mags[i]  = float(imuData_raw.mags_mG[0] * mag_rotMat[i][0] + 
											 imuData_raw.mags_mG[1] * mag_rotMat[i][1] +
											 imuData_raw.mags_mG[2] * mag_rotMat[i][2]) * MAG_SCALE;
	}
	//set gps
	ctrl.controlModel_U.gps[0] = gpsData_raw.lat;
	ctrl.controlModel_U.gps[1] = gpsData_raw.lon;
	ctrl.controlModel_U.gps[2] = gpsData_raw.speed;
	//set steer position and speed
	ctrl.controlModel_U.steer[0] = 0;
	ctrl.controlModel_U.steer[1] = 0;
	//set front fork displacement
	ctrl.controlModel_U.forkdisp = CONVERT_FORKDISP_TO_MM(float(forkDisp_raw.forkDisp)) - forkDisp_raw.forkDisp_offset;
	//set rider torque
	ctrl.controlModel_U.torque = CONVERT_RIDERTRQ_TO_NM(float(riderTorque_raw.riderTorque)) - riderTorque_raw.riderTorque_offset;
	//set steer position and velocity
	ctrl.controlModel_U.steer[0] = CONVERT_STEERPOS_TO_RAD(float(steer_raw.steerPos));
	ctrl.controlModel_U.steer[1] = CONVERT_STEERVEL_TO_RADPS(float(steer_raw.steerVel)) - steer_raw.steerVel_offset;
	//set actual motor current
	ctrl.controlModel_U.curr = CONVERT_ACTCURR_TO_A(float(actCurr_raw.actCurr)) - actCurr_raw.actCurr_offset;
	//set battery voltage
	ctrl.controlModel_U.voltage = CONVERT_VOLTAGE_TO_V(float(voltage_raw.batVolt)) - voltage_raw.batVolt_offset;
	//CPU temp
	ctrl.controlModel_U.CPUTemp = tempmonGetTemp();
	//set remote control (2 channels) sbus TODO
	/*
	ctrl.controlModel_U.ch0 = CONVERT_CH0_FOR_CONTROL(remote_ctrl.ch0);
	ctrl.controlModel_U.ch1 = CONVERT_CH1_FOR_CONTROL(remote_ctrl.ch1);
	*/
	//update control
	ctrl.update();
}

void check_error(void) {
	//check error is also performed in the control loop, so only low-level checks are performed in the code, such as....
	//Instead, steering limits etc. are checked in the control loop (see simulink model)
	//save error state in ctrl.controlModel_U to change error state inside the control loop
	/*
	Legenda:
	1: running mode (all ok and doing task)
	0: stopping mode (task finisched)
	-1: ...
	-2: ...
	errors of etc....
	Idea in Simulink model: if ctrl.controlModel_U.error_state_in is different from 1 and error_state in Simuink is 1, then error_state = ctrl.controlModel_U.error_state_out
	otherwise either ctrl.controlModel_U.error_state_in=1 and error_state=1 (all is ok), or ctrl.controlModel_U.error_state_in=1 but error_state!=0 (error occured)
	*/
  
}

//set drivers
void set_driver(void) {
	//set motor driver
#if MTR_CTRL_MODE==0
	analogWrite(PWM_PIN, constrain(CONVERT_CURRENT_TO_PWM(ctrl.controlModel_Y.curr_ref), PWM_MIN*(powf(2, PWM_RES) - 1), PWM_MAX*(powf(2, PWM_RES) - 1))); 
#else
	dac.analogWrite(DAC_MTR_CH, constrain(CONVERT_CURRENT_TO_DAC(ctrl.controlModel_Y.curr_ref), 0, pow(2, DAC_RES) - 1)); 
#endif
	digitalWriteFast(MTR_DIR_PIN, (ctrl.controlModel_Y.curr_ref >= 0) ? CW : !CW);

  //set throttle signal
  dac.analogWrite(DAC_THROTTLE_CH, constrain(CONVERT_TRHOTTLE_TO_DAC(ctrl.controlModel_Y.throttle_ref), 0, pow(2, DAC_RES) - 1)); 
  
	//set other stuff below
}

//turn off callback
void turnoff_callback(void) {
	uint32_t timer_turnoff = millis();
	LEDON;
	log_closer();
	while ((millis() - timer_turnoff) < 500) {}; //wait
	LEDOFF;
}

//check battery voltag
boolean check_voltage(void) {
	voltage_raw.batVolt = analogRead(VOLTAGE);
	float volts = CONVERT_VOLTAGE_TO_V(float(voltage_raw.batVolt)) - voltage_raw.batVolt_offset;
	if ((volts > MAX_VOLTAGE) | (volts < MIN_VOLTAGE)) {
		delay(1000);
		POWER_OFF;
		return false;
	}
	return true;
}

//return internal RTC time
time_t getTime() {
	return Teensy3Clock.get();
}

//do led stuff
void do_led() {
	if (counters.LED == 0) {
		uint16_t ledfac = DEF_LED;
      	switch (LEDmode) {
      	case LedMode::LOG:
        	ledfac = LOG_LED;
        	break;
      	case LedMode::MTP:
        	ledfac = MTP_LED;
        	break;
      	case LedMode::ERR:
        	ledfac = ERR_LED;
        	break;
      	default:
        	ledfac = DEF_LED;
        	break;    
		}                    
		LEDstate = !LEDstate;
		if (LEDstate) LEDON;
		else LEDOFF;
		//reset counter
		counters.LED = ledfac - 1;
	}
	else counters.LED--;  
}

void serial_flush(void) {
	UART_SPEEDSENS.flush(); //speed sensor
	UART_GPS.flush(); //gps
	//UART_SBUS.flush(); //TODO sbus
}

#endif
