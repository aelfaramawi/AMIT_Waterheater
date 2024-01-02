################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GIE/GIE_program.c 

OBJS += \
./MCAL/GIE/GIE_program.o 

C_DEPS += \
./MCAL/GIE/GIE_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GIE/%.o: ../MCAL/GIE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded_Workspace\LEARN\MCAL\DIO" -I"D:\Embedded_Workspace\LEARN\MCAL\GIE" -I"D:\Embedded_Workspace\LEARN\MCAL\EXT_INT" -I"D:\Embedded_Workspace\LEARN\HAL\LM35" -I"D:\Embedded_Workspace\LEARN\common" -I"D:\Embedded_Workspace\LEARN\HAL\Lcd" -I"D:\Embedded_Workspace\LEARN\MCAL\ADC" -I"D:\Embedded_Workspace\LEARN\HAL" -I"D:\Embedded_Workspace\LEARN\HAL\SevenSeg" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


