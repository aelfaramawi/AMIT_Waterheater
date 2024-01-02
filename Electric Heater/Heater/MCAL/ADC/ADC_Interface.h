
#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "Std_Types.h"

//Voltage Reference Selection
#define AVCC			1
#define AREF_PIN		2
#define _2V56			3

//ADC_CHANNEL
#define ADC0            0
#define ADC1            1
#define ADC2            2
#define ADC3            3
#define ADC4            4
#define ADC5            5
#define ADC6            6
#define ADC7            7

//ADC_PRESCALER
#define _2_DIVISION_FACTOR    1
#define _4_DIVISION_FACTOR    2
#define _8_DIVISION_FACTOR    3
#define _16_DIVISION_FACTOR   4
#define _32_DIVISION_FACTOR   5
#define _64_DIVISION_FACTOR   6
#define _128_DIVISION_FACTOR  7

//ADC Auto Trigger Source
#define  Free_Running_mode  			  	0
#define  Analog Comparator  			  	1
#define  External_Interrupt_Request_0  	  	2
#define  Counter0_Compare Match     	 	3
#define  Counter0_Overflow           		4
#define  Counter1_Compare_Match B    		5
#define  Counter1_Overflow  		  		6
#define  Counter1_Capture_Event	  			7

#define ADC_V_REF	_2V56   /* SELECT AREF MODE: AVCC, AREF_PIN,_2V56 */

#define ADC_CHANNEL	 ADC0	/* SELECT ADC_CHANNEL: ADC0 -> ADC7 */

#define ADC_PRESCALER      _64_DIVISION_FACTOR 	/* SELECT ADC_PRESCALER: _2_DIVISION_FACTOR -> _128_DIVISION_FACTOR */

/* #define Auto_Trigger_Source		 Free_Running_mode	//SELECT ADC Auto Trigger Source   */

void ADC_Init(void);
int16  ADC_Read(void);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
