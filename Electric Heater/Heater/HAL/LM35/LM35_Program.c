/*
 * LM35_Program.c
 *
 *  Created on: Dec 10, 2023
 *      Author: a.elfaramawi
 */
#include "DIO_Interface.h"
#include "LM35_Interface.h"
#include "ADC_Interface.h"
#include "ATmega32_RegisterMap.h"
#include "SevenSeg_Interface.h"
#include <util/delay.h>


void LM35_Init(void)
{
	//ADC_Init();
	//Dio_SetPinDirection(DIO_PORTA, PIN0, INPUT);
}


int16 LM35_Read(void)
{
	int16 temp = 0;
		temp = (ADC_Read()/4);

		return temp;
}
