/*
 * main.c
 *
 *  Created on: Dec 29, 2023
 *      Author: a.elfaramawi
 */

#include "Heater_Control_Interface.h"

int main(void)
{
	Heater_Control_Init();


    while (1)
    {
    	Temp_Sensing();
    	Heating_Cooling_Control();

    }

}


