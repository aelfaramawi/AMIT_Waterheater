/*
 * Relay_Program.c
 *
 *  Created on: Nov 2, 2023
 *      Author: elash
 */
#include "DIO_Interface.h"
#include "Relay_Interface.h"


void Relay_Init(void)
{
	//RELAY1
	Dio_SetPinDirection(DIO_PORTA,PIN2,OUTPUT);
	Dio_WritePin(DIO_PORTA,PIN2,LOW);
	//RELAY2
	Dio_SetPinDirection(DIO_PORTC,PIN3,OUTPUT);
	Dio_WritePin(DIO_PORTC,PIN3,LOW);
}

void Relay1_switchON()
{
	Dio_WritePin(DIO_PORTA,PIN2,HIGH);
}
void Relay1_switchOFF()
{
	Dio_WritePin(DIO_PORTA,PIN2,LOW);
}
void Relay2_switchON()
{
	Dio_WritePin(DIO_PORTC,PIN3,HIGH);
}
void Relay2_switchOFF()
{
	Dio_WritePin(DIO_PORTC,PIN3,LOW);
}
