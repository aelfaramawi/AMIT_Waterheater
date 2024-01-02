/*
 * Relay_Interface.h
 *
 *  Created on: Nov 2, 2023
 *      Author: elash
 */

#ifndef HAL_RELAY_RELAY_INTERFACE_H_
#define HAL_RELAY_RELAY_INTERFACE_H_

#include "DIO_Interface.h"

void Relay_Init(void);
void Relay1_switchON(void);
void Relay1_switchOFF(void);
void Relay2_switchON(void);
void Relay2_switchOFF(void);


#endif /* HAL_RELAY_RELAY_INTERFACE_H_ */
