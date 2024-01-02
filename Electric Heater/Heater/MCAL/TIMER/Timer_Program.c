/*
 * Timer_Program.c
 *
 *  Created on: Nov 1, 2023
 *      Author: elash
 */

#include "Timer_Interface.h"
#include "Bit_Math.h"

static void (*Timer0_CallBack_Ptr)(void) = NULL;
static void (*Timer2_CallBack_Ptr)(void) = NULL;


/*************  TIMER 0 FUNCTIONS	*************/
void Timer0_Init(Timer_PrescalerType prescaler, uint8 Value, boolean InterruptEnable)
{

	#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
	{
		CLEAR_BIT(TCCR0,TCCR0_WGM01_Bit);
		CLEAR_BIT(TCCR0,TCCR0_WGM00_Bit);

		TCNT0 = Value;
		Timer0_Start(prescaler);

		if(InterruptEnable == TRUE)
		{
			SET_BIT(TIMSK, TIMSK_TOIE0_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			CLEAR_BIT(TIMSK, TIMSK_TOIE0_Bit);
		}
		else
		{
		}

	}
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
	{
		SET_BIT(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
		CLEAR_BIT(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);


		TIMER0_OCR0_R = Value;
		Timer0_Start(prescaler);

		if(InterruptEnable == TRUE)
		{
			SET_BIT(TIMER_TIMSK_R, TIMSK_OCIE0_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			CLEAR_BIT(TIMER_TIMSK_R, TIMSK_OCIE0_Bit);
		}
		else
		{
		}

	}
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_FAST_PWM)
	{
		SetBit(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
		SET_BIT(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);

		// Non inverted mode
		CLEAR_BIT(TIMER0_TCCR0_R,TCCR0_COM00_Bit);
		SET_BIT(TIMER0_TCCR0_R,TCCR0_COM01_Bit);
	}
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT)
	{
		CLEAR_BIT(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
		SET_BIT(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);
	}
	#else
		#error "You shall define timer operation mode in Timer_Cfg.h"
	#endif
}

#if( (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)  ||  (TIMER0_OPERATION_MODE == TIMER_MODE_CTC) )
void Timer0_Start(Timer_PrescalerType prescaler)
{
	if (prescaler == No_Prescaler)
	{
		SET_BIT(TCCR0, TCCR0_CS00_Bit);
		CLEAR_BIT(TCCR0, TCCR0_CS01_Bit);
		CLEAR_BIT(TCCR0, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_8)
	{
		CLEAR_BIT(TCCR0, TCCR0_CS00_Bit);
		SET_BIT(TCCR0, TCCR0_CS01_Bit);
		CLEAR_BIT(TCCR0, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_64)
	{
		SET_BIT(TCCR0, TCCR0_CS00_Bit);
		SET_BIT(TCCR0, TCCR0_CS01_Bit);
		CLEAR_BIT(TCCR0, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_256)
	{
		CLEAR_BIT(TCCR0, TCCR0_CS00_Bit);
		CLEAR_BIT(TCCR0, TCCR0_CS01_Bit);
		SET_BIT(TCCR0, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_1024)
	{
		SET_BIT(TCCR0, TCCR0_CS00_Bit);
		CLEAR_BIT(TCCR0, TCCR0_CS01_Bit);
		SET_BIT(TCCR0, TCCR0_CS02_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		CLEAR_BIT(TCCR0, TCCR0_CS00_Bit);
		SET_BIT(TCCR0, TCCR0_CS01_Bit);
		SET_BIT(TCCR0, TCCR0_CS02_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		SET_BIT(TCCR0, TCCR0_CS00_Bit);
		SET_BIT(TCCR0, TCCR0_CS01_Bit);
		SET_BIT(TCCR0, TCCR0_CS02_Bit);
	}
	else
	{
	}

}

void Timer0_Stop (void)
{
	CLEAR_BIT(TCCR0, TCCR0_CS00_Bit);
	CLEAR_BIT(TCCR0, TCCR0_CS01_Bit);
	CLEAR_BIT(TCCR0, TCCR0_CS02_Bit);
}



#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
void Timer0_SetPreload(uint8 preloadValue)
{
	TCNT0 = preloadValue;
}

void __vector_11(void)
{
	static uint16 ovfCounter = 0;
	ovfCounter++;

	if(Timer0_CallBack_Ptr != NULL && ovfCounter == TIMER0_FINAL_OVFCOUNT)  /* 100 ms is passed */
	{
		(*Timer0_CallBack_Ptr)();
		ovfCounter = 0;
	}
	else
	{}

}


#elif( (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
void Timer0_SetCompareValue(uint8 compareValue)
{
	TIMER0_OCR0_R = compareValue;
}
#endif


uint8 Timer0_GetPreload(void)
{
	return TCNT0;
}

void Timer0_EnableInterrupt(void)
{
	#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
	SET_BIT(TIMSK, TIMSK_TOIE0_Bit);
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
	SET_BIT(TIMSK, TIMSK_OCIE0_Bit);
	#endif
}

void Timer0_DisableInterrupt(void)
{
	#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
	CLEAR_BIT(TIMSK, TIMSK_TOIE0_Bit);
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
	CLEAR_BIT(TIMSK, TIMSK_OCIE0_Bit);
	#endif
}



void Timer0_SetCallBack ( void(*Ptr2Func)(void) )
{
	Timer0_CallBack_Ptr = Ptr2Func;
}


#endif


#if( (TIMER0_OPERATION_MODE == TIMER_MODE_FAST_PWM)  ||  (TIMER0_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT) )
void Timer0_PWM(uint16 freq, uint8 dutyCycle)
{
	uint16 result =0;
	result = (dutyCycle * TIMER0_TOP)/100;
	TIMER0_OCR0_R = result;

	/*	Check for frequency then choose prescaler	*/
	SET_BIT(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
	CLEAR_BIT(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
	CLEAR_BIT(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
}
#endif


/*************  TIMER 2 FUNCTIONS	*************/


void Timer2_Init(Timer_PrescalerType prescaler, uint16 Value, boolean InterruptEnable)
{

	#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
	{
		CLEAR_BIT(TCCR2,TCCR2_WGM21_Bit);
		CLEAR_BIT(TCCR2,TCCR2_WGM20_Bit);

		TCNT2 = Value;
		Timer2_Start(prescaler);

		if(InterruptEnable == TRUE)
		{
			SET_BIT(TIMSK, TIMSK_TOIE2_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			CLEAR_BIT(TIMSK, TIMSK_TOIE2_Bit);
		}
		else
		{
		}

	}
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_CTC)
	{
		SET_BIT(TCCR2,TCCR2_WGM21_Bit);
		CLEAR_BIT(TCCR2,TCCR2_WGM20_Bit);

		OCR2 = Value;
		Timer2_Start(prescaler);

		if(InterruptEnable == TRUE)
		{
			SET_BIT(TIMSK, TIMSK_OCIE2_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			CLEAR_BIT(TIMSK, TIMSK_OCIE2_Bit);
		}
		else
		{
		}
	}
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_FAST_PWM)
	{
		SET_BIT(TIMER2_TCCR2_R,TCCR2_WGM21_Bit);
		SET_BIT(TIMER2_TCCR2_R,TCCR2_WGM20_Bit);

		// Non inverted mode
		CLEAR_BIT(TIMER2_TCCR2_R,TCCR2_COM20_Bit);
		SET_BIT(TIMER2_TCCR2_R,TCCR2_COM21_Bit);
	}
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT)
	{
		CLEAR_BIT(TIMER2_TCCR2_R,TCCR2_WGM21_Bit);
		SET_BIT(TIMER2_TCCR2_R,TCCR2_WGM20_Bit);
	}
	#else
		#error "You shall define timer operation mode in Timer_Cfg.h"
	#endif


}

#if( (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)  ||  (TIMER2_OPERATION_MODE == TIMER_MODE_CTC) )
void Timer2_Start(Timer_PrescalerType prescaler)
{
	if (prescaler == No_Prescaler)
	{
		SET_BIT(TCCR2, TCCR2_CS20_Bit);
		CLEAR_BIT(TCCR2, TCCR2_CS21_Bit);
		CLEAR_BIT(TCCR2, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_8)
	{
		CLEAR_BIT(TCCR2, TCCR2_CS20_Bit);
		SET_BIT(TCCR2, TCCR2_CS21_Bit);
		CLEAR_BIT(TCCR2, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_64)
	{
		SET_BIT(TCCR2, TCCR2_CS20_Bit);
		SET_BIT(TCCR2, TCCR2_CS21_Bit);
		CLEAR_BIT(TCCR2, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_256)
	{
		CLEAR_BIT(TCCR2, TCCR2_CS20_Bit);
		CLEAR_BIT(TCCR2, TCCR2_CS21_Bit);
		SET_BIT(TCCR2, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_1024)
	{
		SET_BIT(TCCR2, TCCR2_CS20_Bit);
		CLEAR_BIT(TCCR2, TCCR2_CS21_Bit);
		SET_BIT(TCCR2, TCCR2_CS22_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		CLEAR_BIT(TCCR2, TCCR2_CS20_Bit);
		SET_BIT(TCCR2, TCCR2_CS21_Bit);
		SET_BIT(TCCR2, TCCR2_CS22_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		SET_BIT(TCCR2, TCCR2_CS20_Bit);
		SET_BIT(TCCR2, TCCR2_CS21_Bit);
		SET_BIT(TCCR2, TCCR2_CS22_Bit);
	}
	else
	{
	}

}

void Timer2_Stop (void)
{
	CLEAR_BIT(TCCR2, TCCR2_CS20_Bit);
	CLEAR_BIT(TCCR2, TCCR2_CS21_Bit);
	CLEAR_BIT(TCCR2, TCCR2_CS22_Bit);
}



#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
void Timer2_SetPreload(uint8 preloadValue)
{
	TCNT2 = preloadValue;
}

void __vector_5(void)
{
	static uint16 ovfCounter = 0;
	ovfCounter++;

	if(Timer2_CallBack_Ptr != NULL && ovfCounter == TIMER2_FINAL_OVFCOUNT)  /* 1000 ms is passed */
	{
		(*Timer2_CallBack_Ptr)();
		ovfCounter = 0;
	}
	else
	{}

}





#elif( (TIMER2_OPERATION_MODE == TIMER_MODE_CTC))

void Timer2_SetCompareValue(uint8 compareValue)
{
	OCR2 = compareValue;
}
#endif


uint8 Timer2_GetPreload(void)
{
	return TCNT2;
}

void Timer2_EnableInterrupt(void)
{
	#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
	SET_BIT(TIMSK, TIMSK_TOIE2_Bit);
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_CTC)
	SET_BIT(TIMSK, TIMSK_OCIE2_Bit);
	#endif
}

void Timer2_DisableInterrupt(void)
{
	#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
	CLEAR_BIT(TIMSK, TIMSK_TOIE2_Bit);
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_CTC)
	CLEAR_BIT(TIMSK, TIMSK_OCIE2_Bit);
	#endif
}



void Timer2_SetCallBack ( void(*Ptr2Func)(void) )
{
	Timer2_CallBack_Ptr = Ptr2Func;
}



#endif



#if( (TIMER2_OPERATION_MODE == TIMER_MODE_FAST_PWM)  ||  (TIMER2_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT) )
void Timer2_PWM(uint16 freq, uint8 dutyCycle)
{
	uint16 result =0;
	result = (dutyCycle * TIMER2_TOP)/100;
	TIMER2_OCR2_R = result;

	/*	Check for frequency then choose prescaler	*/
	SET_BIT(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
	CLEAR_BIT(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
	CLEAR_BIT(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
}
#endif

