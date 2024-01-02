
#include "Heater_Control_Interface.h"
#include <util/delay.h>

volatile uint8 setTemperature = 40;
static uint8 currentTemperature ;


static boolean BUTTON_flag = FALSE;
static boolean LM_flag = FALSE;
static boolean TempDisplay_Flag = FALSE;
static boolean LED_Blink_Flag = FALSE;

void Heater_Control_Init()
{
    SevenSeg_Init();
    ADC_Init();
    EEPROM_Init();
    Peltier_Init();
    Ceramic_Heater_Init();
    Led_Init(LED1);
    GIE_Enable();
    Timer0_Init(NoClkSrc,0,TRUE);
	Timer0_SetCallBack(Read_WaterTemperature);
    // External interrupt initialization
    Ext_Int_Init(EXT_INT0);
    Ext_Int_Enable(EXT_INT0);
    Ext_Int_SetCallBack(EXT_INT0, UP_BUTTON);

    Ext_Int_Init(EXT_INT1);
    Ext_Int_Enable(EXT_INT1);
    Ext_Int_SetCallBack(EXT_INT1, DOWN_BUTTON);
}

void UP_BUTTON(void)
{
	BUTTON_flag = TRUE;
	LM_flag = FALSE;
	setTemperature += Temp_Step;
	if (setTemperature > Temp_Max) {
		setTemperature = Temp_Max;
	}
	SevenSeg(setTemperature);
	EEPROM_WriteByte(0 ,setTemperature );
	_delay_ms(100);
	BUTTON_flag = FALSE;
	LM_flag = TRUE;

}

void DOWN_BUTTON(void)
{
	BUTTON_flag = TRUE;
	LM_flag = FALSE;
	setTemperature -= Temp_Step;
	if (setTemperature < Temp_Min) {
		setTemperature = Temp_Min;
	}
	SevenSeg(setTemperature);
	EEPROM_WriteByte(0 ,setTemperature );
	_delay_ms(100);
	BUTTON_flag = FALSE;
	LM_flag = TRUE;

}


void Temp_Sensing(void)
{
    LM35_Read();
}

void Heating_Cooling_Control(void)
{
	TempDisplay_Flag = TRUE;
	currentTemperature = LM35_Read();
	// Timer2_Stop();
	Timer0_Start(No_Prescaler);
	if (currentTemperature < setTemperature) {
		Ceramic_Heater_SetMode(HEATER_ON_MODE);
		Peltier_SetMode(PELTIER_OFF_MODE);
		Led_Toggle(LED1);
		LED_Blink_Flag = TRUE;

	} else if (currentTemperature > setTemperature) {
		Ceramic_Heater_SetMode(HEATER_OFF_MODE);
		Peltier_SetMode(PELTIER_ON_MODE);
		Led_On(LED1);
		LED_Blink_Flag = FALSE;
	} else {
		Ceramic_Heater_SetMode(HEATER_OFF_MODE);
		Peltier_SetMode(PELTIER_OFF_MODE);
		Led_Off(LED1);
		LED_Blink_Flag = FALSE;
	}

}


void Read_WaterTemperature(void)
{
	static uint8 prevTemp = 0;

	/* Check to display temperature to avoid many writings and blinkings on SSD */
	if( (currentTemperature != prevTemp && LM_flag == TRUE) || TempDisplay_Flag == TRUE)
	{
		/* SSD Display */
		SevenSeg(LM35_Read());

		TempDisplay_Flag = FALSE;
	}
	prevTemp = currentTemperature;
}
