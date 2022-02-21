#############################################################################
# Makefile for compiling and uploading *.ino files to arduino-like board
# Created by SL, 02-20-2022
#############################################################################

NAME			:= empty.ino
BOARD_FQBN		:= teensy:avr:teensy41
BOARD_ID		:= TEENSY41
BOARD_OPTIONS	:= speed=600,usb=serial,opt=o2std,keys=en-us

HARDWARE		:= -hardware /usr/share/arduino/hardware
TOOLS			:= -tools /usr/share/arduino/hardware/tools \
				-tools /usr/share/arduino/tools-builder
BUILD_PATH		:= .build
BUILD_CACHE		:= .cache
FQBN			:= -fqbn=$(BOARD_FQBN):$(BOARD_OPTIONS)
LIBRARIES		:= -libraries /lib -libraries /genlib
FLAGS			:= -compile

TARGET_HEX		:= $(BUILD_PATH)/$(NAME).hex

BUILDER			:= arduino-builder
UPL_CLI			:= teensy_loader_cli

##############################################################################
# COMPILING
##############################################################################

compiling:
	###################################################
	# CREATING DIRECTORIES
	###################################################
	
	@echo Creating necessary directories if not existing...
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(BUILD_CACHE)
	@echo
	
	###################################################
	# COMPILING CODE
	###################################################
	
	
	@echo Compiling $(NAME) for $(BOARD_FQBN) with options $(BOARD_OPTIONS)
	@echo Build path is $(BUILD_PATH)
	@echo Cache path is $(BUILD_CACHE) 
	@echo Library paths are $(LIBRARIES)
	$(BUILDER) $(FLAGS) -build-path $(BUILD_PATH) -build-cache $(BUILD_CACHE) $(HARDWARE) $(TOOLS) $(LIBRARIES) $(FQBN) $(NAME)
	@echo Target hex file $(TARGET_HEX) generated
	@echo
	
	###################################################
	# UPLOADING CODE
	###################################################
	
	@echo Uploading target hex $(TARGET_HEX) for board $(BOARD_ID)
	$(UPL_CLI) --mcu=$(BOARD_ID) -v $(TARGET_HEX)
	@echo
	

