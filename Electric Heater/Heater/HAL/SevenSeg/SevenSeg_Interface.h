
#ifndef HAL_SEVENSEG_SEVENSEG_INTERFACE_H_
#define HAL_SEVENSEG_SEVENSEG_INTERFACE_H_

#include "Std_Types.h"

#define SEVENSEG_DISPLAY_PORT DIO_PORTA
#define SEVENSEG_DISPLAY_SHIFT 4

#define SEVENSEG1_EN_PORT DIO_PORTB
#define SEVENSEG1_EN_PIN PIN0

#define SEVENSEG2_EN_PORT DIO_PORTB
#define SEVENSEG2_EN_PIN PIN1

void SevenSeg_Init(void);
void SevenSeg_Display(uint8 num);
void SevenSeg(uint8 num);
void SevenSeg_EN_1(void);
void SevenSeg_EN_2(void);
void SevenSeg_Dis_1(void);
void SevenSeg_Dis_2(void);

#endif /* HAL_SEVENSEG_SEVENSEG_INTERFACE_H_ */
