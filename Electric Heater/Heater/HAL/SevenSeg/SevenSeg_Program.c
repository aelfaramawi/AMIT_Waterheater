#include "DIO_Interface.h"
#include "ATmega32_RegisterMap.h"
#include "SevenSeg_Interface.h"
#include "Bit_Math.h"
#include "util/delay.h"

void SevenSeg_Init(void)
{
	//Dio_SetPortDirection(SEVENSEG_DISPLAY_PORT, 0xF << SEVENSEG_DISPLAY_SHIFT);
	Dio_SetPinDirection(SEVENSEG_DISPLAY_PORT, PIN7, OUTPUT);//D
	Dio_SetPinDirection(SEVENSEG_DISPLAY_PORT, PIN6, OUTPUT);//C
	Dio_SetPinDirection(SEVENSEG_DISPLAY_PORT, PIN5, OUTPUT);//B
	Dio_SetPinDirection(SEVENSEG_DISPLAY_PORT, PIN4, OUTPUT);//A

	Dio_SetPinDirection(SEVENSEG2_EN_PORT, SEVENSEG1_EN_PIN, OUTPUT);

	Dio_SetPinDirection(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, OUTPUT);

}

void SevenSeg_EN_1(void){
	Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, HIGH);
}

void SevenSeg_EN_2(void){
	Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, HIGH);
}

void SevenSeg_Dis_1(void){
	Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, LOW);
	}

void SevenSeg_Dis_2(void){
	Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, LOW);
	}


void SevenSeg_Display(uint8 num)
{

	if (num<100)
	{
	Dio_WritePin(SEVENSEG_DISPLAY_PORT,PIN7,GET_BIT(num,3)); //D
	Dio_WritePin(SEVENSEG_DISPLAY_PORT,PIN6,GET_BIT(num,2)); //C
	Dio_WritePin(SEVENSEG_DISPLAY_PORT,PIN5,GET_BIT(num,1)); //B
	Dio_WritePin(SEVENSEG_DISPLAY_PORT,PIN4,GET_BIT(num,0)); //A
	}
}

void SevenSeg(uint8 num)
{
	uint8 units = num % 10;
	uint8 tens = num / 10;
	uint16 counter;
	SevenSeg_Dis_1();
	SevenSeg_Dis_2();

	for(counter =0; counter<20; counter++)
	{
		//Dio_WritePort(SEVENSEG_DISPLAY_PORT, units << SEVENSEG_DISPLAY_SHIFT);

		SevenSeg_EN_1();
		SevenSeg_Display(tens);
		_delay_ms(1);
		SevenSeg_Dis_1();

		//Dio_WritePort(SEVENSEG_DISPLAY_PORT, tens << SEVENSEG_DISPLAY_SHIFT);
		SevenSeg_EN_2();
		SevenSeg_Display(units);
		_delay_ms(1);
		SevenSeg_Dis_2();


	}
}

