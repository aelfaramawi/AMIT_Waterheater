/*
 * LM35_Interface.h
 *
 *  Created on: Dec 10, 2023
 *      Author: a.elfaramawi
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

#include "Std_Types.h"

void LM35_Init(void);
int16 LM35_Read(void);

#endif /* HAL_LM35_LM35_INTERFACE_H_ */
