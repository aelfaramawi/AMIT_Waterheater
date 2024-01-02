
#ifndef MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define MCAL_EXT_INT_EXT_INT_INTERFACE_H_

#include "Std_Types.h"

#define EXT_INT0 	0
#define EXT_INT1 	1
#define EXT_INT2	2

//External interrupts sense control:
#define FALLING_EDGE	 1
#define RISING_EDGE		 2
#define LOW_LEVEL        3
#define LOGICAL_CHANGE   4

//Select External interrupts sense control:

#define EXT_INT0_SENSE_CONTROL RISING_EDGE
#define EXT_INT1_SENSE_CONTROL RISING_EDGE
#define EXT_INT2_SENSE_CONTROL RISING_EDGE

void Ext_Int_Init(uint8 interruptChannel);
void Ext_Int_Enable(uint8 interruptChannel);
void Ext_Int_Disable(uint8 interruptChannel);
void Ext_Int_SetCallBack(uint8 interruptChannel, void (*interruptAction)(void));


#endif /* MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
