#include "ATmega32_RegisterMap.h"
#include "ADC_Interface.h"
#include "Bit_Math.h"

void ADC_Init(void)
{
#if   ADC_V_REF   ==   AVCC
	SET_BIT(ADMUX,REFS0_BIT);
	CLEAR_BIT(ADMUX,REFS1_BIT);
#elif ADC_V_REF   ==   AREF_PIN
	CLEAR_BIT(ADMUX,REFS0_BIT);
	CLEAR_BIT(ADMUX,REFS1_BIT);
#elif ADC_V_REF   ==   _2V56
	SET_BIT(ADMUX,REFS0_BIT);
	SET_BIT(ADMUX,REFS1_BIT);
#endif

	/* To select right adjustment */
	//CLEAR_BIT(ADMUX,ADLAR_BIT);

	/* To select an ADC channel */
	ADMUX = (ADMUX & 0b11100000) | ADC_CHANNEL;

	/* To select the ADC frequency */
	ADCSRA = (ADCSRA & 0b11111000) | ADC_PRESCALER;

	/* To enable ADC circuit */
	SET_BIT(ADCSRA,ADEN_BIT);

	/*To select ADC Auto Trigger Source
	SET_BIT(ADCSRA,ADATE_BIT);
	ADCSRA = (ADCSRA & 0b11111000) | Auto_Trigger_Source;
}*/
	//SET_BIT(ADCSRA,ADCSRA_ADPS0_Bit);//F_CPU/128
	//SET_BIT(ADCSRA,ADCSRA_ADPS1_Bit);
	//SET_BIT(ADCSRA,ADCSRA_ADPS2_Bit);
}

int16 ADC_Read(void) {
	/* To start conversion */
		SET_BIT(ADCSRA,ADSC_BIT);
		while(IS_BIT_CLEARED(ADCSRA,ADIF_BIT));
		return ADC_VALUE;
}
/*
  To start conversion
	int16 temp = 0;
	//ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL & 0x1F);
	SET_BIT(ADCSRA,ADSC_BIT);    //single mode
	while(IS_BIT_CLEARED(ADCSRA,ADIF_BIT)); // Wait for conversion to complete
	SET_BIT(ADCSRA,ADIF_BIT);//clear the flag
		temp = ADC_VALUE;
		temp |= (ADCH_Reg << 8);
		return temp;
	//return ADC_VALUE;   //ADC result is available in ADCL and ADCH
*/
