/*
 * CeramicHeater_Program.c
 *
 *  Created on: Nov 2, 2023
 *      Author: elash
 */

#include "CeramicHeater_Interface.h"
#include "Relay_Interface.h"

void Ceramic_Heater_Init(void)
{
	Dio_SetPinDirection(DIO_PORTA,PIN2,OUTPUT); 	// //same as RELAY_2
	Ceramic_Heater_SetMode(HEATER_UNDEFINED_MODE);
}

void Ceramic_Heater_SetMode(Heater_ModeType HeaterMode)
{
	switch(HeaterMode)
	{
		case (HEATER_ON_MODE):
		{
			Relay1_switchON();
			break;
		}
		case (HEATER_OFF_MODE):
		{
			Relay1_switchOFF();
			break;
		}
		case (HEATER_UNDEFINED_MODE):
		{
			break;
		}
		default: {}
	}

}
