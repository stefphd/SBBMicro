/*! \file main.cpp
	\brief Main file of the low-level code for the controller.
	\details Main file of the low-level code for the controller. This contains the definition for main function, which is the
	entry-point function of the code. Note that this is different from the standard Arduino workflow, which makes use of the setup() and
	loop() function with the main() written in the core code (actually, the main function defined in this file overrides that
	in the core code).
	\see mainfun
*/

//include
#include <include.h>

#undef main //remove Arduino main function - maybe not necessary (?)

/*! @defgroup mainfun Entry-point function
	\brief Entry-point function of the code.
	\details This contains the definition for main function, which is the
	entry-point function of the code. Note that this is different from the standard Arduino workflow, which makes use of the setup() and
	loop() function with the main() written in the core code (actually, the main function defined in this file overrides that
	in the core code).
    \see main.cpp
    @{
*/

/*! \brief Entry-point function.
	\details Definition for main function, which is the entry-point function of the code.
	The function implementation is structured as follows

	```
	int main() {

		//initializations here

		while(1) { //infinite loop, running forever
			//loop here
		}

		return 0;
	}
	```

	\return The exit status (0 in this case).
    \see main.cpp
*/
int main() {

	//set the pins
	set_GPIO();

	//led on
	LEDON;

	//set CPU freq
	set_arm_clock(CPU_FREQ);

	//set RTC provider
	setSyncProvider(getTime);

	//set callback when swiching off
	delay(200);
	set_arm_power_button_callback(&turnoff_callback);

    //check mtp - after set_arm_power_button_callback, before enabling other relay etc
    if (check_mtp()) do_mtp(); //if true 

	//begin IO buses
	start_IObus();

	//set input-output (sensors etc)
	set_IObus();

	//enable relay
	RELAY_ENABLE;

	//check battery voltage
	check_voltage();

	//do zero of sensors
	do_zeros();

	//debug if necessary (otherwise do nothing)
	start_debug();

	//start_logger if necessary (otherwise do nothing)
	start_logger();

	//enable steer motor
	MTR_ENABLE;

	//main delay before starting
	delay(200);

	//led off
	LEDOFF;

	//begin control loop - to be called just before starting loop
	ctrl.begin();
	sampling_timer = micros() - SAMPLING_TIME; //to be sure that the control loop starts immediately at the first loop

	//flush serials
	serial_flush();

	while(1) {
		if ((micros() - sampling_timer) >= SAMPLING_TIME) {
		timing.dt_cycle = micros() - sampling_timer; //cycle time (should be equal to SAMPLING_TIME)
		sampling_timer = micros(); //update timer
		
		//get sensor readings
		get_sensors();

		//do control loop
		do_control();

		//do debug stuff if necessary (otherwise do nothing)
		do_debug();

		//check if errors 
		check_error();

		//set drivers
		set_driver();

		//update duty cycle
		timing.duty_cycle = micros() - sampling_timer; //duty cycle (i.e. time to do stuff), should be < SAMPLING_TIME, better < SAMPLING_TIME/2 to avoid large delay

		//other secondary stuff below

		//do logging stuff if necessary (otherwise do nothing)
		do_logger();
		
		//do led stuff
		do_led();

	}

	yield(); //maybe not necessary

	}

	return 0;

}

/*! @} */