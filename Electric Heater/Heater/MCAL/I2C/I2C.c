/*
 * I2C.c
 *
 *  Created on: Jan 15, 2018
 *      Author: Mohamed
 */
#include "I2C.h"

void I2C_Init()
{
	TWBR = 0x02;
	TWCR = (1<<TWEN);
	TWSR = 0x00;
	TWAR = 0b00000010;
}

void I2C_Start()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(IS_BIT_CLEARED(TWCR,TWINT));
}

void I2C_Stop()
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2C_Write(uint8 data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(IS_BIT_CLEARED(TWCR,TWINT));
}

uint8 I2C_Read_ACK()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(IS_BIT_CLEARED(TWCR,TWINT));
	return TWDR;
}

uint8 I2C_Read_NO_ACK()
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(IS_BIT_CLEARED(TWCR,TWINT));
	return TWDR;
}

uint8 I2C_Status()
{
	uint8 status;
	status = (TWSR & 0xF8);
	return status;
}
