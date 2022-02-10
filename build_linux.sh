#!/bin/sh

#############################################################################
# Shell script for compiling and uploading files to arduino-like board
# Linux version
# Created by SL, 02-20-2022
#############################################################################

NAME="main.cpp"
SRC="./src"
BOARD_FQBN="teensy:avr:teensy41"
BOARD_ID="TEENSY41"
BOARD_OPTIONS="speed=600,usb=mtpserial,opt=o3std,keys=en-us"

HARDWARE="-hardware ./hardware"
TOOLS="-tools ./hardware/tools-linux -tools /usr/share/arduino/tools-builder"
BUILD_PATH=".build"
BUILD_CACHE=".cache"
FQBN=-fqbn=$BOARD_FQBN:$BOARD_OPTIONS
LIBRARIES="-libraries ./ -libraries ./include/ -libraries ./lib/"
FLAGS="-verbose"

BUILDER="arduino-builder"
UPL_CLI="teensy_loader_cli"

TARGET_HEX=$BUILD_PATH/$NAME.hex

###################################################
# CREATING DIRECTORIES
###################################################

echo Creating necessary directories if not existing...
mkdir -p $BUILD_PATH
mkdir -p $BUILD_CACHE
echo

###################################################
# COMPILING CODE
###################################################

echo Compiling $NAME for $BOARD_FQBN with options $BOARD_OPTIONS
echo Build path is $BUILD_PATH
echo Cache path is $BUILD_CACHE
echo Library paths are $LIBRARIES
$BUILDER -dump-prefs -build-path $BUILD_PATH -build-cache $BUILD_CACHE $HARDWARE $TOOLS $LIBRARIES $FQBN $SRC/$NAME
$BUILDER -compile $FLAGS -build-path $BUILD_PATH -build-cache $BUILD_CACHE $HARDWARE $TOOLS $LIBRARIES $FQBN $SRC/$NAME
echo Target hex file $TARGET_HEX generated
echo

###################################################
# UPLOADING CODE
###################################################

echo Uploading target hex $TARGET_HEX for board $BOARD_ID
$UPL_CLI --mcu=$BOARD_ID -v $TARGET_HEX
echo