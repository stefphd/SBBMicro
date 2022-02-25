# SBBMicro

Source code for the self-balancing-bike microcontroller unit (Teensy 4.1-based). 🚀️

Author: Stefano Lovato, 2022

## Files

Files:

* `controlModel.slx`: control model implementation in Simulink
* `gencode.m`: MATLAB function for code generation from Simulink model
* `params.sldd`: Simulink parameters used in `controlModel.slx`
* `build_linux.sh`: build shell script for Linux
* `build_win.bat`: build shell script for Windows

Code folders:

* `./include`: contains `.h` files included in source code
* `./src`: contains source `.c` or `.cpp` files, including main file `main.cpp`
* `./lib`: contains a folder for each used library, with file `library.properties` for defining the library properties (mandatory for arduino compiling) and `.h` and `.cpp` files (possibly contained in folder `./src/`)
* `./hardware/teensy/avr/cores`: contains the core code for the Teensy microcontroller

Additional folders:

* `./hardware/teensy-windows`: build tools for Windows
* `./hardware/teensy-linux`: build tools for Linux
* `./.vscode`: contains VS code property file(s)
* `./.build` and `.cache`: hidden folders created only during compilation

## Prerequisites

* *arduino-builder* (>=1.6.1), also provided with Arduino IDE
* *teeny_loader_cli* (>=2.2, Linux only), also provided with teensyduino. For Windows x64 pre-compiled binaries in `./hardware/teeny_loader_cli-win-x64` are used
* *MATLAB/Simulink* with *Embedeed Coder Toolbox* (>=2021a), for control algorithm code generation only

No other dependecies are necessary: all used libraries are already included in `./lib/`.

Additional utilities (only recommended):

* *teensyduino*: not stricktly necessary for compilation b/c core code for teensy MCU is already included in `./hardware/`
* *Visual Studio Code* with *C/C++ (ms-vscode)* for code completation and simpler code building

## Code generation

Code generation of the control algorithm is performed via *MATLAB/Simulink* with the *Embedeed Coder Toolbox*. Code generation can be launch with *MATLAB* using

```MATLAB
gencode()
```

By default `controlModel.slx` is used for code generation, with the parameters defined in `params.sldd`. Different Simulink model can be specified as an input in `gencode("...")`

## Building

Compilation is performed using the *arduino-builder*, while uploading using the *teensy_loader_cli*. Shell scripts provide simple usage depending on the operative system:

* Linux:

  ```bash
  ./build_linux.sh
  ```

  or

  ```bash
  bash build_linux.sh
  ```

  Tested with Arch-Linux x64. Sometimes it is necessary to delete manually the folders `.build` and `.cache`.
* Windows: 

  ```batch
  ./build_win.bat
  ```

  Tested with Windows 10 x64.
* MacOS: not implemented yet

Alternatively, one can use `ctrl+shift+B` to build the code in *Visual Studio Code* with both Linux and Windows (this makes use of `build_linux.sh` or `build_win.sh` depending on the operative system).

## Known issues

* Uploading only possible by entering in program mode in Teensy MCU (press program button)
* Undefined identifiers found by Visual Studio Code, however this is only a C/C++ IntelliSense issue (compilation works fine)

## TODO list

* Make using user-defined C functions in Simulink working when compiling