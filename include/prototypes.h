//function prototypes
//written by SL

#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

// prototypes for functions.h
void start_IObus(void);
void set_IObus(void);
void do_zeros(void);
void set_GPIO(void);
void get_sensors(void);
void do_control(void);
void check_error(void);
void set_driver(void);
void turnoff_callback(void);
boolean check_voltage(void);
time_t getTime();
void do_led();
void serial_flush();

//prototypes for logger.h
void start_logger(void);
void log_closer(void);
void do_logger(void);

//prototypes for sbbmtp.h
bool check_mtp(void);
void do_mtp(void);

//prototypes for debug.h
void start_debug(void);
void do_debug(void);


#endif