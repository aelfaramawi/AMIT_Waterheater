/*
 * Peltier_Interface.h
 *
 *  Created on: Nov 2, 2023
 *      Author: elash
 */

#ifndef HAL_PELTIER_PELTIER_INTERFACE_H_
#define HAL_PELTIER_PELTIER_INTERFACE_H_

// PELTIER connected to RELAY_2

typedef enum
{
	PELTIER_OFF_MODE = 0,
	PELTIER_ON_MODE,
	PELTIER_UNDEFINED_MODE
}Peltier_ModeType;

void Peltier_Init(void);
void Peltier_SetMode(Peltier_ModeType PeltierMode);


#endif /* HAL_PELTIER_PELTIER_INTERFACE_H_ */
