
#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

#include "DIO_Interface.h"

#define BUTTON_SCHEME ACTIVE_HIGH

#define BTN0_PORT DIO_PORTD
#define BTN0_PIN  PIN2

#define BTN1_PORT DIO_PORTD
#define BTN1_PIN PIN3

#define BTN2_PORT DIO_PORTB
#define BTN2_PIN PIN2

/***********************/

#if (BUTTON_SCHEME == ACTIVE_HIGH)

#define PRESSED HIGH
#define RELEASED LOW

#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0

#else

#define PRESSED LOW
#define RELEASED HIGH

#endif

#define BTN0 0
#define BTN1 1
#define BTN2 2

void Button_Init(uint8 btn);
Dio_PinStateType Button_GetState(uint8 btn);


#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
