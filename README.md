# SBBMicro

Source code for the self-balancing-bike microcontroller unit. 🚀️

Author: Stefano Lovato, 2022

## Dependencies

* arduino-builder (>=1.6.1), also provided with Arduino IDE
* teeny_loader_cli (>=2.2, Linux only), also provided with teensyduino. For Windows x64 pre-compiled binaries in XX are used
* MATLAB/Simulink with Embedeed Coder Toolbox (>=2021a), for control algorithm code generation only.

No other dependecies are necessary: all used libraries are already included in `/lib`.

Additional utilities (only recommended):

* teensyduino: not stricktly necessary for compilation b/c core code for teensy MCU is alredy included in `/hardware`
* Visual Studio Code with C/C++ IntelliSense (ms-vscode) for code completation only (not for compilation)

## Code generation

Code generation of the control algorithm is performed via MATLAB/Simulink with the Embedeed Coder Toolbox. Code generation can be lauch with MATLAB using

```
gencode
```

## Building

Compilation is performed using the arduino-builder, while uploading using the teensy_loader_cli. Shell scripts provide simple usage depending on the operative system:

* Linux:

  ```
  ./build_linux.sh
  ```

  or

  ```
  bash build_linux.sh
  ```

  Tested with Arch-Linux x64. Sometimes it is necessary to delete manually the folders `.build` and `.cache`.
* Windows: **TODO**

  Tested with Windows 10 x64.
* MacOS: **TODO**

## Known issues

* Uploading in Linux only possible by entering in program mode in Teensy MCU (press program button)
* Undefined identifiers found by Visual Studio Code, however this is only a C/C++ IntelliSense issue (compilation works fine)
