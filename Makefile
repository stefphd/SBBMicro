
#---------------------------------------------------------------------------------
# MAKEFILE FOR COMPILATIONN OF SBBMICRO IN LINUX
#---------------------------------------------------------------------------------
# AUTHOR: STEFANO LOVATO
# YEAR: 2022

#---------------------------------------------------------------------------------
#USER SETTINGS
#---------------------------------------------------------------------------------

#Operative system (Linux/Windows_NT)
ifneq ($(OS), Windows_NT)
OS := $(shell uname)
endif

ifneq ($(OS),$(filter $(OS),Linux Windows_NT))
$(error OS not supported)
endif

#Name
NAME			:= main.cpp

#Board
BOARD			:= teensy41
BOARD_OPTIONS	:= speed=600,usb=mtpserial,opt=o3std,keys=en-us

#Directories
ifeq ($(OS), Linux)
ARDUINO_FOLDER	:= /usr/share/arduino
TEENSY_TOOLS	:= ./hardware/tools-linux
else ifeq ($(OS), Windows_NT) 
ARDUINO_FOLDER  := C:/Program Files (x86)/Arduino
TEENSY_TOOLS	:= ./hardware/tools-windows
endif
SRC				:= ./src
BUILD_PATH		:= ./.build
CACHE_PATH		:= ./.cache
DOCS_PATH		:= ./docs

#---------------------------------------------------------------------------------
#USUALLY EDITING BELOW THIS LINE NOT NECESSARY
#---------------------------------------------------------------------------------

#Tools (be careful to change this)
BUILDER			:= arduino-builder
POSTCOMPILER	:= $(TEENSY_TOOLS)/teensy_post_compile
REBOOT			:= $(TEENSY_TOOLS)/teensy_reboot

#Builder options (be careful to change this)
HARDWARE		:= -hardware ./hardware
FQBN			:= -fqbn=teensy:avr:$(BOARD):$(BOARD_OPTIONS)
LIBRARIES		:= -libraries ./ -libraries ./include/ -libraries ./lib/
TOOLS			:= -tools "$(TEENSY_TOOLS)" -tools "$(ARDUINO_FOLDER)/tools-builder"
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
ifeq ($(OS), Linux)
	@$(RM) -rf $(DOCS_PATH)
else ifeq ($(OS), Windows_NT)
	@rmdir /S /Q "$(DOCS_PATH)"
endif

#Remake
remake: clean all

#Rebuild
rebuild: clean build

#Clean build
clean:
ifeq ($(OS), Linux)
	@$(RM) -rf $(BUILD_PATH)
	@$(RM) -rf $(CACHE_PATH)
else ifeq ($(OS), Windows_NT)
	@rmdir /S /Q "$(BUILD_PATH)"
	@rmdir /S /Q "$(CACHE_PATH)"
endif

#Clean all
cleanall: clean cleandoc

#Make the Directories
directories:
ifeq ($(OS), Linux)
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(CACHE_PATH)
else ifeq ($(OS), Windows_NT)
	@if not exist "$(BUILD_PATH)" mkdir "$(BUILD_PATH)"
	@if not exist "$(CACHE_PATH)" mkdir "$(CACHE_PATH)"
endif

#Generate the code
gencode:
	@matlab -batch "gencode"

#Non-File Targets
.PHONY: all build upload remake clean doc cleandoc directories gencode