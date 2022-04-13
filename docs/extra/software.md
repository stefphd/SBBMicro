# Software

The software documentation is divided in modules, in particular:
* Entry-point function: describes the documentation for the entry-point function, i.e. main()
* Configurations: contains general configurations, mainly using the *Define* directive. This module is in turn divided in sub-modules:
  * Bus settings: configuration parameters for buses (e.g. SPI, UART, etc.)
  * Pin settings: configuration parameters for pin used
  * Constants: factors and constants
  * Macro: definition of macros used
  * User parametets: general user-defined parameters
* Variables: declaration of the variables and objects
* User functions: general user functions used in main(). These deals with sensor reading, control loop execution, driver setting, and error checking
* Data logging: functions for data logging
* MTP: functions for the MTP mode
* Debugging: functions for debugging and signal straming to and from PC

## Basic code

\todo Basic code description (i.e. the user functions)

## Data logging

\todo Sescribe data logging

## MTP mode

MTP mode allows to recognize the microcontroller as an MTP device (see e.g. [https://en.wikipedia.org/wiki/Media_Transfer_Protocol](https://en.wikipedia.org/wiki/Media_Transfer_Protocol)), in order to be capable of getting log files (with extension `*.sbb`) from the internal SD memory.
To enter in MTP mode, it is sufficient to keep the on/off button pressed for at least 3s when turning on. To get the MTP mode working in the PC side:

* Windows: no additional operation is usually necessary, the microcontroller should be automatically recognized as an MTP device
* Linux: install *gMTP* (from [https://gmtp.sourceforge.io/downloads.htmls](https://gmtp.sourceforge.io/downloads.htmls)), which is a MTP client for UNIX and UNIX like systems (this should include the *libmtp* library)

## Debugging

\todo Describe signal streaming and debugging to and from PC