#include "Led_Interface.h"
#include "DIO_Interface.h"

void Led_Init(LedType led)
{
	switch(led)
	{
		case LED0:
			Dio_SetPinDirection(LED0_PORT, LED0_PIN, OUTPUT);
			break;
		case LED1:
			Dio_SetPinDirection(LED1_PORT, LED1_PIN, OUTPUT);
			break;
		case LED2:
			Dio_SetPinDirection(LED2_PORT, LED2_PIN, OUTPUT);
			break;
	}
}

void Led_On(LedType led)
{
	switch(led)
	{
		case LED0:
			Dio_WritePin(LED0_PORT, LED0_PIN, HIGH);
			break;
		case LED1:
			Dio_WritePin(LED1_PORT, LED1_PIN, HIGH);
			break;
		case LED2:
			Dio_WritePin(LED2_PORT, LED2_PIN, HIGH);
			break;
		default:
			break;
	}
}

void Led_Off(LedType led)
{
	switch(led)
	{
		case LED0:
			Dio_WritePin(LED0_PORT, LED0_PIN, LOW);
			break;
		case LED1:
			Dio_WritePin(LED1_PORT, LED1_PIN, LOW);
			break;
		case LED2:
			Dio_WritePin(LED2_PORT, LED2_PIN, LOW);
			break;
		default:
			break;
	}
}

void Led_Toggle(LedType led)
{
	switch(led)
	{
		case LED0:
			Dio_TogglePin(LED0_PORT, LED0_PIN);
			break;
		case LED1:
			Dio_TogglePin(LED1_PORT, LED1_PIN);
			break;
		case LED2:
			Dio_TogglePin(LED2_PORT, LED2_PIN);
			break;
		default:
			break;
	}
}

void Led_Blink()
	{
		while(1)
			{
				Led_On(LED1);
				_delay_ms(1000);
				Led_Off(LED1);
				_delay_ms(1000);
			}

	}
