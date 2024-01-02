/*
 * Peltier_Program.c
 *
 *  Created on: Nov 2, 2023
 *      Author: elash
 */

#include "Peltier_Interface.h"
#include "Relay_Interface.h"

void Peltier_Init(void)
{
	Dio_SetPinDirection(DIO_PORTC,PIN3,OUTPUT); //same as RELAY_2
	Peltier_SetMode(PELTIER_UNDEFINED_MODE);
}

void Peltier_SetMode(Peltier_ModeType PeltierMode)
{
	switch(PeltierMode)
	{
		case (PELTIER_ON_MODE):
		{
			Relay2_switchON();
			break;
		}
		case (PELTIER_OFF_MODE):
		{
			Relay2_switchOFF();
			break;
		}
		case (PELTIER_UNDEFINED_MODE):
		{
			break;
		}
		default: {}
	}

}
