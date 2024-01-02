
#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include <util/delay.h>
#include "DIO_Interface.h"

#define LED0_PORT DIO_PORTC
#define LED1_PORT DIO_PORTC
#define LED2_PORT DIO_PORTD

#define LED0_PIN PIN2
#define LED1_PIN PIN7
#define LED2_PIN PIN6

typedef enum
{
	LED0,
	LED1,
	LED2
}LedType;

void Led_Init(LedType led);
void Led_On(LedType led);
void Led_Off(LedType led);
void Led_Toggle(LedType led);
void Led_Blink();

#endif /* HAL_LED_LED_INTERFACE_H_ */
