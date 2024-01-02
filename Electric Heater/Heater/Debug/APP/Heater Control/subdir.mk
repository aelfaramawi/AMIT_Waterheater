################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Heater\ Control/HeaterControl_Program.c 

OBJS += \
./APP/Heater\ Control/HeaterControl_Program.o 

C_DEPS += \
./APP/Heater\ Control/HeaterControl_Program.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Heater\ Control/HeaterControl_Program.o: ../APP/Heater\ Control/HeaterControl_Program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded_Workspace\LEARN\APP" -I"D:\Embedded_Workspace\LEARN\MCAL\TIMER" -I"D:\Embedded_Workspace\LEARN\APP\Heater Control" -I"D:\Embedded_Workspace\LEARN\APP\State Machine" -I"D:\Embedded_Workspace\LEARN\MCAL\EEPROM" -I"D:\Embedded_Workspace\LEARN\HAL\Relay" -I"D:\Embedded_Workspace\LEARN\HAL\Peltier" -I"D:\Embedded_Workspace\LEARN\HAL\Ceramic Heater" -I"D:\Embedded_Workspace\LEARN\MCAL\DIO" -I"D:\Embedded_Workspace\LEARN\MCAL\Timer1" -I"D:\Embedded_Workspace\LEARN\MCAL\TIMER0" -I"D:\Embedded_Workspace\LEARN\HAL\Led" -I"D:\Embedded_Workspace\LEARN\HAL\Button" -I"D:\Embedded_Workspace\LEARN\MCAL\GIE" -I"D:\Embedded_Workspace\LEARN\MCAL\EXT_INT" -I"D:\Embedded_Workspace\LEARN\HAL\LM35" -I"D:\Embedded_Workspace\LEARN\common" -I"D:\Embedded_Workspace\LEARN\HAL\Lcd" -I"D:\Embedded_Workspace\LEARN\MCAL\ADC" -I"D:\Embedded_Workspace\LEARN\HAL" -I"D:\Embedded_Workspace\LEARN\HAL\SevenSeg" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"APP/Heater Control/HeaterControl_Program.d" -MT"APP/Heater\ Control/HeaterControl_Program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


