/*
 * CeramicHeater_Interface.h
 *
 *  Created on: Nov 2, 2023
 *      Author: elash
 */

#ifndef HAL_CERAMIC_HEATER_CERAMICHEATER_INTERFACE_H_
#define HAL_CERAMIC_HEATER_CERAMICHEATER_INTERFACE_H_

// HEATER connected to RELAY_1

typedef enum
{
	HEATER_OFF_MODE = 0,
	HEATER_ON_MODE,
	HEATER_UNDEFINED_MODE
}Heater_ModeType;

void Ceramic_Heater_Init(void);
void Ceramic_Heater_SetMode(Heater_ModeType HeaterMode);


#endif /* HAL_CERAMIC_HEATER_CERAMICHEATER_INTERFACE_H_ */
