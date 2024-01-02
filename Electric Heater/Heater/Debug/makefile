################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include MCAL/EEPROM/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SevenSeg/subdir.mk
-include HAL/Relay/subdir.mk
-include HAL/Peltier/subdir.mk
-include HAL/Led/subdir.mk
-include HAL/Lcd/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/Ceramic\ Heater/subdir.mk
-include HAL/Button/subdir.mk
-include APP/Heater_Control/subdir.mk
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
LEARN.lss \
LEARN.lss \

FLASH_IMAGE += \
LEARN.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: LEARN.elf secondary-outputs

# Tool invocations
LEARN.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LEARN.map -mmcu=atmega32 -o "LEARN.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LEARN.lss: LEARN.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LEARN.elf  >"LEARN.lss"
	@echo 'Finished building: $@'
	@echo ' '

LEARN.hex: LEARN.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LEARN.elf  "LEARN.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LEARN.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LEARN.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LEARN.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
