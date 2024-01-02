################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Ceramic\ Heater/CeramicHeater_Program.c 

OBJS += \
./HAL/Ceramic\ Heater/CeramicHeater_Program.o 

C_DEPS += \
./HAL/Ceramic\ Heater/CeramicHeater_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Ceramic\ Heater/CeramicHeater_Program.o: ../HAL/Ceramic\ Heater/CeramicHeater_Program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded_Workspace\LEARN\MCAL\TIMER" -I"D:\Embedded_Workspace\LEARN\MCAL\I2C" -I"D:\Embedded_Workspace\LEARN" -I"D:\Embedded_Workspace\LEARN\APP" -I"D:\Embedded_Workspace\LEARN\APP\Heater_Control" -I"D:\Embedded_Workspace\LEARN\common" -I"D:\Embedded_Workspace\LEARN\HAL" -I"D:\Embedded_Workspace\LEARN\HAL\Button" -I"D:\Embedded_Workspace\LEARN\HAL\Ceramic Heater" -I"D:\Embedded_Workspace\LEARN\HAL\Lcd" -I"D:\Embedded_Workspace\LEARN\HAL\Led" -I"D:\Embedded_Workspace\LEARN\HAL\LM35" -I"D:\Embedded_Workspace\LEARN\HAL\Peltier" -I"D:\Embedded_Workspace\LEARN\HAL\Relay" -I"D:\Embedded_Workspace\LEARN\HAL\SevenSeg" -I"D:\Embedded_Workspace\LEARN\MCAL" -I"D:\Embedded_Workspace\LEARN\MCAL\ADC" -I"D:\Embedded_Workspace\LEARN\MCAL\DIO" -I"D:\Embedded_Workspace\LEARN\MCAL\EEPROM" -I"D:\Embedded_Workspace\LEARN\MCAL\EXT_INT" -I"D:\Embedded_Workspace\LEARN\MCAL\GIE" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/Ceramic Heater/CeramicHeater_Program.d" -MT"HAL/Ceramic\ Heater/CeramicHeater_Program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


