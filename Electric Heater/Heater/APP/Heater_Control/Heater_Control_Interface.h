
#ifndef HEATER_CONTROL_INTERFACE_H_
#define HEATER_CONTROL_INTERFACE_H_

#include "Timer_Interface.h"
#include "GIE_Interface.h"
#include "Ext_Int_Interface.h"
#include "EEPROM.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "Button_Interface.h"
#include "Led_Interface.h"
#include "LM35_Interface.h"
#include "SevenSeg_Interface.h"
#include "CeramicHeater_Interface.h"
#include "Peltier_Interface.h"
#include "Timer_Interface.h"


#define Temp_Min              35
#define Temp_Max              75
#define Temp_Step             5
#define TEMP_SETTING_TIMEOUT  5000
#define TEMP_READCOUNT        10

#define EEPROM_SP_Address		 0

#define PRESSED HIGH
#define RELEASED LOW

void Heater_Control_Init(void);
void Temp_Sensing(void);
void Heating_Cooling_Control(void);
//void Display_Control(void);
void UP_BUTTON(void);
void DOWN_BUTTON(void);
void Read_WaterTemperature(void);
//void Blink_SetPointTemperature(void);
//void Stop_WaterHeater_Operation(void);

#endif /* HEATER_CONTROL_INTERFACE_H_ */
