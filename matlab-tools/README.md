# MATLAB tools

Last edit: 29th September 2022

This folder contains MATLAB tools usefull for code generation and other stuff.

List of files contained in this folder:

* `gencode`: MATLAB function to generate the code from a Simulink model. Simple example usage:

```MATLAB
gencode()
```

  Type `gencode --help` for help.

* `check_toolbox`: MATLAB function to check for the toolboxes used by the code generation and inform the user for missing toolboxes. Simple example usage:

```MATLAB
check_toolbox()
```

  Type `check_toolbox --help` for help.

* `make`: use make commands from within MATLAB. Type `make help` for the help.
