
# Hardware

The following figure shows the hardware scheme of the controller unit. The hardware is divided in two separated boxes:
* low-voltage (LV) box: contains the micro-controller unit (MCU) and the sensors
* high-voltage (HV) box: contains (mainly) the motor drivers

![Hardware scheme](hw-scheme.svg)

## Low-voltage box

The hardwares contained in the LV box are:
* Teensy 4.1 MCU, which deals with control loop execution, sensor reading, driver setting, relay enabling, and communincation with a remote controller. This also uses the internal voltage regulator to convert 5V to 3.3V.
* IMU ISM330DHCX, which measures accelerations (in mg) and angular velocities (in mdeg/s)
* Magnetometer (MAG) LIS3MDL, which measures the magnetic field in mG
* Ultimate GPS from Adafruit
* Teensy 4.0 MCU, which reads the rotary encoder for the bicycle speed measurement
* Reveiver Archer M+, which communicates with the remote controller
* Amplifier module MecoStrain 2038, which reads the full-bridge strain gauges for the rider's torque measurement
  
The base voltage level, used for digital signals, is 3.3V. In addition, two other voltage levels are present; 5V (used to power the Teensy 4.1 micro-controller) and 12V (used for the rotary encoder and the amplifier module).

## High-voltage box

The HV box contains the following hardwares:
* Steer motor driver
* Brake motor driver A4988
* 2 voltage regulator which convert the 24V (nominal) to 5V and 12V necessary for the low-voltage box
* The main relay of the system, which is controlled by the MCU and powers the 12V voltage regulator, the brake motor driver, and the steer motor driver. Note that the 5V voltage regulator is powered directly from the battery (and not from the relay)

## Connections

\todo Describe the hardware in details: pins used and type (pull-up/pull-down), buses used

### LV schematics

![Low-voltage schematics](lv-schematics.svg)

### HV schematics

\todo add high voltage schematics

