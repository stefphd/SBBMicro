
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
	iostatus.imu = imu.begin() == ISM330DHCX_OK;
	iostatus.mag = mag.begin() == LIS3MDL_STATUS_OK;
	dac.begin(); iostatus.dac = true;
	
	//start speed-sensor UART
	UART_SPEEDSENS.begin(BAUD_SPEEDSENS); iostatus.speedsens = (bool) UART_SPEEDSENS;
	speedSensor.begin(UART_SPEEDSENS);
	//CCM_CSCDR1 = 105450240; //UART_CLK_SEL bit set to 0 - to use baudrate of serial above 6e6 Mbit/s, see https://forum.pjrc.com/threads/67150-Teensy4-1-MAX-baud-rate
	//start gps UART
	UART_GPS.begin(BAUD_GPS_DEF); iostatus.gps = (bool) UART_GPS;
	UART_GPS.addMemoryForRead(GPSserial_extra_buffer, sizeof(GPSserial_extra_buffer));
	/*delay(66);
	gps.sendCommand(PMTK_SET_BAUD_57600), delay(66);
	UART_GPS.end(), delay(66);
	UART_GPS.begin(BAUD_GPS);*/
	//start sbus
	iostatus.sbus = sbus.Begin(); //This inclues begin of the #UART_SBUS
}

/*
void set_IObus(void) sets the IO (sensors, ADC, DAC, etc.)
*/
void set_IObus(void) {
	//enable sensors
	iostatus.accen = imu.ACC_Enable() == ISM330DHCX_OK;
	iostatus.gyroen = imu.GYRO_Enable() == ISM330DHCX_OK;
	iostatus.magen = mag.Enable() == LIS3MDL_STATUS_OK;
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
	pinMode(BR_SLEEP_PIN, OUTPUT);
	digitalWriteFast(MTR_EN_PIN, !MTR_EN_STATE);
	digitalWriteFast(MTR_DIR_PIN, CW);
	digitalWriteFast(RELAY_EN_PIN, !RELAY_EN_STATE);
	digitalWriteFast(BR_SLEEP_PIN, !BR_SLEEP_STATE);
}

/*
void start_brake_stepper(void) starts the stepper motor
*/
void start_brake_stepper(void) {
	TS4::begin(); //begin the teensy stepper library
	brakeMotor.setMaxSpeed(CONVERT_BRLEV_TO_STEPS(MAX_BR_SPEED));
	brakeMotor.setAcceleration(CONVERT_BRLEV_TO_STEPS(MAX_BR_ACC));
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
			gps.lat = 0;
			gps.lon = 0;
			gps.speed = 0;
		}
	}

	//analogs
	actCurr_raw.actCurr = analogRead(ACT_CURR);
	riderTorque_raw.riderTorque = analogRead(RIDER_TRQ);
	steer_raw.steerPos = analogRead(STEER_POS);
	steer_raw.steerVel = analogRead(STEER_SPEED);
	voltage_raw.batVolt = analogRead(VOLTAGE);
	forkDisp_raw.forkDisp = analogRead(FORK_DISP);

	//sbus
	if (sbus.Read()) {
		if (check_sbus()) { //success!!!
			sbus.ch(remote_raw.ch, NUM_CH_SBUS*sizeof(int16_t)); //read channels
			remote_raw.missing_frame = 0; //reset missing frame
		} else remote_raw.missing_frame++; //increment missing frame
	} else remote_raw.missing_frame++; //increment missing frame
	if (remote_raw.missing_frame >= MAX_MISSING_SBUS) { //set zero values to 
		remote_raw.missing_frame = MAX_MISSING_SBUS; //set to #MAX_MISSING_SBUS to avoid overflow
		for (uint8_t i = 0; i < NUM_CH_SBUS; ++i) remote_raw.ch[i] = ZERO_SBUS; //set channel to zero
	}
}

/*
bool check_sbus(void) check for SBUS errors
*/
bool check_sbus(void)  {
	if (sbus.lost_frame()) { return false; }
	if (sbus.failsafe()) { return false; }
	for (uint8_t i = 0; i < NUM_CH_SBUS; ++i) {
		if ((sbus.ch(i) < MIN_SBUS) || (sbus.ch(i) > MAX_SBUS)) { return false; } //return false as soon as an unfeasible value is found
	}
	return true; //all checks ok
}

/*
void set_ctrl_input(void) sets the control input structure
*/
void set_ctrl_input(void) {
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
	ctrl.controlModel_U.ref_inputs[0] = CONVERT_CHANNEL_TO_FLOAT(remote_raw.ch[SBUS_ROLL_CH-1], MIN_REF_INPUT, MAX_REF_INPUT);
	ctrl.controlModel_U.ref_inputs[1] = CONVERT_CHANNEL_TO_FLOAT(remote_raw.ch[SBUS_THROTTLE_CH-1], MIN_REF_INPUT, MAX_REF_INPUT);
}

/*
void do_control(void) performs control update cycle
*/
void do_control(void) {
	
	//tests
	#ifdef IMP_TEST
	enable_new = get_selector();
	if (enable_old != enable_new) {
		if (enable_new) test_start = millis();
	}
	enable_old = enable_new;
	test_timer = millis() - test_start;
	ctrl.controlModel_Y.curr_ref = 0;
	if (enable_new != 0 && (test_timer <= IMP_DUR)) {
		ctrl.controlModel_Y.curr_ref = 0.5F*IMP_AMP*(1.0F - cosf(2*PI*float(test_timer)/float(IMP_DUR)))*float(enable_new);
	} 
	return;
	#endif

	#ifdef SWEEP_TEST
	enable_new = get_enable();
	if (enable_old != enable_new) {
		if (enable_new) test_start = millis();
	}
	enable_old = enable_new;
	test_timer = millis() - test_start;
	if (enable_new) {
		if (test_timer <= TEST_DURATION) {
			float freq = 0.0F + float(test_timer)/float(TEST_DURATION) * (10.0F-0.0F);
			float ampl = 2.0F;
			ctrl.controlModel_Y.curr_ref = ampl*sinf(2.0F*PI*freq*float(test_timer)/1000.0F/2.0F);
		} else ctrl.controlModel_Y.curr_ref = 0, remote_raw.ch[SBUS_EN_CH-1] = TRESHOLD_LOGIC_SBUS/2;
	} else ctrl.controlModel_Y.curr_ref = 0, remote_raw.ch[SBUS_EN_CH-1] = TRESHOLD_LOGIC_SBUS/2;
	return;
	#endif

	#ifdef SIN_TEST
	enable_new = get_enable();
	if (enable_old != enable_new) {
		if (enable_new) test_start = millis();
	}
	enable_old = enable_new;
	test_timer = millis() - test_start;
	if (enable_new) {
		const float freq = 0.5F;
		if (test_timer <= (2*SIN_WAVE*freq*1000.0F)) ctrl.controlModel_Y.curr_ref = 4.0F*sinf(2.0F*PI*freq*float(test_timer)/1000.0F);
	} else ctrl.controlModel_Y.curr_ref = 0;
	return;
	#endif

	//update control
	ctrl.update(); //this performs the control loop

}

void update_tet(uint32_t t0) {
	timing.tet = micros() - t0; //duty cycle (i.e. time to do stuff), should be < SAMPLING_TIME, better < SAMPLING_TIME/2 to avoid large delay
	if (timing.tet > timing.max_tet) timing.max_tet = timing.tet;
	if (timing.tet < timing.min_tet) timing.min_tet = timing.tet;
}

void check_error(void) {
	//check error is also performed in the control loop, so only low-level checks are performed in the code, such as....
	//Instead, steering limits etc. are checked in the control loop (see simulink model)
	//save error state in ctrl.controlModel_U to change error state inside the control loop
}

//get selector
int8_t get_selector(void) {
	if (remote_raw.ch[SBUS_SEL_CH-1] >= TRESHOLD_POS_SBUS) {
		return +1;
	}
	if (remote_raw.ch[SBUS_SEL_CH-1] <= TRESHOLD_NEG_SBUS) {
		return -1;
	}
	return 0;
}

//get enable status
bool get_enable(void) {
	return ((remote_raw.ch[SBUS_EN_CH-1] >= TRESHOLD_LOGIC_SBUS) && (ctrl.controlModel_Y.error_state_out < 1) && (ctrl.controlModel_U.error_state_in < 1)); //enable from remote control and check errors
}

//set drivers
void set_driver(void) {
	bool enable = get_enable();

	// override control throttle_ref
	//ctrl.controlModel_Y.throttle_ref =  CONVERT_CHANNEL_TO_FLOAT(remote_raw.ch[SBUS_THR_OR-1], MIN_REF_INPUT, MAX_REF_INPUT);

	//set motor driver
#if MTR_CTRL_MODE==0
	analogWrite(PWM_PIN, constrain(CONVERT_CURRENT_TO_PWM(ctrl.controlModel_Y.curr_ref), PWM_MIN*(powf(2, PWM_RES) - 1), PWM_MAX*(powf(2, PWM_RES) - 1))); 
#else
	dac.analogWrite(DAC_MTR_CH, constrain(CONVERT_CURRENT_TO_DAC(ctrl.controlModel_Y.curr_ref), 0, pow(2, DAC_RES) - 1)); 
#endif
	digitalWriteFast(MTR_DIR_PIN, (ctrl.controlModel_Y.curr_ref >= 0) ? CW : !CW);
	digitalWriteFast(MTR_EN_PIN, (enable) ? MTR_EN_STATE : !MTR_EN_STATE);

#if EN_LONG_CTRL==1
	//set throttle signal
	dac.analogWrite(DAC_THROTTLE_CH, (ctrl.controlModel_Y.throttle_ref >= 0 && enable) ? 
									 constrain(CONVERT_TRHOTTLE_TO_DAC(ctrl.controlModel_Y.throttle_ref), 0, pow(2, DAC_RES) - 1) :
									 CONVERT_TRHOTTLE_TO_DAC(0)); 
	
	//set brake stepper motor
	int32_t brake_motor_position = (ctrl.controlModel_Y.throttle_ref <= 0) ? 
									 constrain(CONVERT_TRHOTTLE_TO_STEPS(-ctrl.controlModel_Y.throttle_ref),0,CONVERT_BRLEV_TO_STEPS(MAX_BR_DISP)) :
									 CONVERT_TRHOTTLE_TO_STEPS(0);
	if (remote_raw.ch[SBUS_BR_CH-1] >= TRESHOLD_LOGIC_SBUS) brake_motor_position = CONVERT_BRLEV_TO_STEPS(MAX_BR_DISP);
	bool is_brake_motor_arrived = brakeMotor.getPosition() == brake_motor_position;
	if (is_brake_motor_arrived) BR_DISABLE;
	if (!brakeMotor.isMoving && !is_brake_motor_arrived){ 
		BR_ENABLE;
		brakeMotor.moveAbsAsync(brake_motor_position);							 
	}
#endif
	

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
			case LedMode::MTPWAIT:
				ledfac = MTPWAIT_LED;
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

void set_ctrl_param(void) {
	//controlParams.propGainSpeed = .2;
	//controlParams.intTimeSpeed = 0.5;
	//controlParams.derTimeSpeed = 0.1;
}

#endif
