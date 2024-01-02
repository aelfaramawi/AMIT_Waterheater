
#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "Std_Types.h"

#define LCD_RS_PORT DIO_PORTB
#define LCD_RS_PIN  PIN1

#define LCD_RW_PORT DIO_PORTB
#define LCD_RW_PIN  PIN2

#define LCD_EN_PORT DIO_PORTB
#define LCD_EN_PIN  PIN3
//
#define MODE_4_BIT 							       0
#define MODE_8_BIT 							       1

#define LCD_8_BIT_MODE_COMMAND 					0x38	//PORTB

#if LCD_MODE == MODE_4_BIT
	#define LCD_4_BIT_MODE_COMMAND_1            0x33	//PINC
	#define LCD_4_BIT_MODE_COMMAND_2            0x32	//PORTD
	#define LCD_4_BIT_MODE_COMMAND_3            0x28	//ACSR
#endif

#define LCD_DISPLAY_ON_COMMAND 					0x0C    // 0000 1100
#define LCD_CLEAR_COMMAND						0x01	// 0000 0001

#define LCD_MODE MODE_4_BIT

#define LCD_DISPLAY_PORT DIO_PORTA

#if LCD_MODE == MODE_4_BIT
	#define LCD_DISPLAY_SHIFT   4
#endif

void Lcd_Init(void);
void Lcd_DisplayString(uint8* string);
void Lcd_Clear(void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
