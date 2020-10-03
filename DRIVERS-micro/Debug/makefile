################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WatchDogTimer/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SevenSegmant2/subdir.mk
-include HAL/SevenSegmant/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include APP/timer/subdir.mk
-include APP/LCD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DRIVERS-micro2.lss \

FLASH_IMAGE += \
DRIVERS-micro2.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: DRIVERS-micro2.elf secondary-outputs

# Tool invocations
DRIVERS-micro2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DRIVERS-micro2.map -mmcu=atmega32 -o "DRIVERS-micro2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DRIVERS-micro2.lss: DRIVERS-micro2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DRIVERS-micro2.elf  >"DRIVERS-micro2.lss"
	@echo 'Finished building: $@'
	@echo ' '

DRIVERS-micro2.hex: DRIVERS-micro2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DRIVERS-micro2.elf  "DRIVERS-micro2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DRIVERS-micro2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DRIVERS-micro2.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: DRIVERS-micro2.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:DRIVERS-micro2.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DRIVERS-micro2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
