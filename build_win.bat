:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::Shell script for compiling and uploading files to arduino-like board
::Windows version
::Created by SL, 02-20-2022
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

@echo off

set NAME=main.cpp
set SRC=.\src
set BOARD_FQBN=teensy:avr:teensy41
set BOARD_ID=TEENSY41
set BOARD_OPTIONS=speed=600,usb=mtpserial,opt=o3std,keys=en-us

set ARDUINO_FOLDER=C:\Program Files (x86)\Arduino

set HARDWARE=-hardware .\hardware
set TOOLS=-tools "%ARDUINO_FOLDER%\tools-builder"
set BUILD_PATH=.build
set BUILD_CACHE=.cache
set FQBN=-fqbn=%BOARD_FQBN%:%BOARD_OPTIONS%
set LIBRARIES=-libraries .\ -libraries .\include\ -libraries .\lib\
set FLAGS=-verbose

set BUILDER=arduino-builder
set UPL_CLI=.\hardware\teeny_loader_cli-win-x64\teensy_loader_cli

set TARGET_HEX=%BUILD_PATH%\%NAME%.hex

:::::::::::::::::::::::::::::::::::::::::::::::::::
::CREATING DIRECTORIES
:::::::::::::::::::::::::::::::::::::::::::::::::::

echo Creating necessary directories if not existing...
mkdir %BUILD_PATH%
mkdir %BUILD_CACHE%
echo 

:::::::::::::::::::::::::::::::::::::::::::::::::::
::COMPILING CODE
:::::::::::::::::::::::::::::::::::::::::::::::::::

echo Compiling %NAME% for %BOARD_FQBN% with options %BOARD_OPTIONS%
echo Build path is %BUILD_PATH%
echo Cache path is %BUILD_CACHE%
echo Library paths are %LIBRARIES%
%BUILDER% -dump-prefs -build-path %BUILD_PATH% -build-cache %BUILD_CACHE% %HARDWARE% %TOOLS% %LIBRARIES% %FQBN% %SRC%\%NAME%
%BUILDER% -compile %FLAGS% -build-path %BUILD_PATH% -build-cache %BUILD_CACHE% %HARDWARE% %TOOLS% %LIBRARIES% %FQBN% %SRC%\%NAME%
echo Target hex file %TARGET_HEX% generated
echo

:::::::::::::::::::::::::::::::::::::::::::::::::::
::UPLOADING CODE
:::::::::::::::::::::::::::::::::::::::::::::::::::

echo Uploading target hex %TARGET_HEX% for board %BOARD_ID%
%UPL_CLI% --mcu=%BOARD_ID% -v %TARGET_HEX%
echo