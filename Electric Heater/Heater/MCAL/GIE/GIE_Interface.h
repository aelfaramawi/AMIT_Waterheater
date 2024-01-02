
#ifndef MCAL_GIE_GIE_INTERFACE_H_
#define MCAL_GIE_GIE_INTERFACE_H_

#define INT0_VECT        __vector_1
#define INT1_VECT        __vector_2
#define INT2_VECT        __vector_3
#define TIMER2_COMPA_vect	__vector_4
#define TIMER1_CAPT_VCET __vector_6
#define TIMER0_COMP_VECT __vector_10
#define TIMER0_OVF_VECT  __vector_11

#define ISR(VECT) void VECT(void)__attribute__((signal));\
				  void VECT(void)

void GIE_Enable(void);
void GIE_Disable(void);

#endif /* MCAL_GIE_GIE_INTERFACE_H_ */
