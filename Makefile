
#---------------------------------------------------------------------------------
# MAKEFILE FOR COMPILATIONN OF SBBMICRO IN LINUX
#---------------------------------------------------------------------------------
# AUTHOR: STEFANO LOVATO
# YEAR: 2022

#---------------------------------------------------------------------------------
#USER SETTINGS
#---------------------------------------------------------------------------------

#Name and code
NAME			:= main.cpp
SRC				:= ./src

#Board
BOARD			:= teensy41
BOARD_OPTIONS	:= speed=600,usb=mtpserial,opt=o3std,keys=en-us

#Directories
ARDUINO_FOLDER	:= /usr/share/arduino
BUILD_PATH		:= ./.build
CACHE_PATH		:= ./.cache

#---------------------------------------------------------------------------------
#USUALLY EDITING BELOW THIS LINE NOT NECESSARY
#---------------------------------------------------------------------------------

#Tools (be careful to change this)
TEENSY_TOOLS	:= ./hardware/tools-linux
BUILDER			:= arduino-builder
POSTCOMPILER	:= $(TEENSY_TOOLS)/teensy_post_compile
REBOOT			:= $(TEENSY_TOOLS)/teensy_reboot

#Builder options (be careful to change this)
HARDWARE		:= -hardware ./hardware
TOOLS			:= -tools $(TEENSY_TOOLS) -tools $(ARDUINO_FOLDER)/tools-builder
FQBN			:= -fqbn=teensy:avr:$(BOARD):$(BOARD_OPTIONS)
LIBRARIES		:= -libraries ./ -libraries ./include/ -libraries ./lib/
FLAGS			:= #-verbose

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------

#Default Make
all: build upload

#Build the code
build: directories
	@$(BUILDER) -compile $(FLAGS) -build-path $(BUILD_PATH) -build-cache $(CACHE_PATH) $(HARDWARE) $(TOOLS) $(LIBRARIES) $(FQBN) $(SRC)/$(NAME)

#Dump preferances
dumpprefs:
	@$(BUILDER) -dump-prefs -build-path $(BUILD_PATH) -build-cache $(CACHE_PATH) $(HARDWARE) $(TOOLS) $(LIBRARIES) $(FQBN) $(SRC)/$(NAME)

#Upload the code
upload:
	$(POSTCOMPILER) -file=$(NAME) -path=$(BUILD_PATH) -tools=$(TEENSY_TOOLS) -board teensy:avr:$(BOARD)
	$(REBOOT)

#Make documentation
doc: cleandoc
	@doxygen

#Clean documentation
cleandoc:
	@$(RM) -rf docs

#Remake
remake: clean all

#Rebuild
rebuild: clean build

#Clean build
clean:
	@$(RM) -rf $(BUILD_PATH)
	@$(RM) -rf $(CACHE_PATH)

#Clean all
cleanall: clean cleandoc

#Make the Directories
directories:
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(CACHE_PATH)

#Non-File Targets
.PHONY: all build upload remake clean doc cleandoc directories