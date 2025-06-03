# Installation of the pre-requisites

## Windows

### Arduino builder

Arduino builder is shipped with this repository. No installation should be necessary, although you may use your own version of arduino builder.

### Visual Studio Code

To install *Visual Studio Code*:

1. Download the installer from [here](https://code.visualstudio.com/)
2. Run the installer `VSCodeUserSetup-x64-X.X.X.exe` (where `X.X.X` is the software version)
3. Follow the installation steps

You may also install the `C/C++` extension for *Visual Studio Code* for code completation.

### Make and Doxygen

For installation of *Make* and *Doxygen* you may employ *Chocolatey*, which is a package manager for Windows. First download and install *Chocolatey* by following the this [installation guide](https://chocolatey.org/install#individual). Basically, you need to run in the powershell (with administrative privileges) the following command

```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

To install *Make* and *Doxygen* just run in the command promp or powershell (with administrative privileges)

```powershell
choco install make doxygen.install
```

and follow the installation steps (basically, type `Y` when required).
Finally, add the installation directory (default is `C:\Program Files\doxygen\bin`) to the environment variable `PATH`.
To check the installation, just use in the command prompt (you need to open a new terminal)

```bash
doxygen -v
```

```bash
make -v
```

\note Alternatively, for *Doxigen* you may also download the installer from [here](https://www.doxygen.nl/download.html) and install the software. After, you need to add the installation directory to the environment variable `PATH`.

\note For *make* other installation process may exist.

### KiCAD

Download and install *KiCAD* from [here](https://www.kicad.org/download/windows/).

## Linux

Depending on your Linux distrubution, you can easily install the pre-requisites using your package manager: **you are using Linux, so you are supposed to know this stuff!** 

## MacOS

Not implemented yet.

## Embedded Coder Toolbox (MATLAB)

For installing the *Embedded Coder Toolbox* in MATLAB
0. Install MATLAB (if not installed)
1. Go to `Add-Ons > Get Add Ons` and look for the *Embedded Coder*
2. Click on *Embedded Coder* and install

Other (possibly necessary) MATLAB toolboxes may be installed in a simular way.