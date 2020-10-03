################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SevenSegmant2/Segmant_PROG2.c 

OBJS += \
./HAL/SevenSegmant2/Segmant_PROG2.o 

C_DEPS += \
./HAL/SevenSegmant2/Segmant_PROG2.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SevenSegmant2/%.o: ../HAL/SevenSegmant2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


