
#ifndef MCAL_ATMEGA32_REGISTERMAP_H_
#define MCAL_ATMEGA32_REGISTERMAP_H_

#include "Std_Types.h"

/**********************    DIO     **********************/
#define PORTA     (*((volatile uint8* const)0x3B))
#define DDRA      (*((volatile uint8* const)0x3A))
#define PINA      (*((volatile uint8* const)0x39))

#define PORTB     (*((volatile uint8* const)0x38))
#define DDRB      (*((volatile uint8* const)0x37))
#define PINB      (*((volatile uint8* const)0x36))

#define PORTC     (*((volatile uint8* const)0x35))
#define DDRC      (*((volatile uint8* const)0x34))
#define PINC      (*((volatile uint8* const)0x33))

#define PORTD     (*((volatile uint8* const)0x32))
#define DDRD      (*((volatile uint8* const)0x31))
#define PIND      (*((volatile uint8* const)0x30))

/**********************  Interrupt  **********************/
#define SREG      (*((volatile uint8* const)0x5F))

/* SREG BITS */
#define I_BIT     7

#define MCUCR 	  (*((volatile uint8* const)0x55))
#define MCUCSR    (*((volatile uint8* const)0x54))
#define GICR  	  (*((volatile uint8* const)0x5B))

/* MCUCR BITS */
#define ISC00_BIT 0
#define ISC01_BIT 1
#define ISC10_BIT 2
#define ISC11_BIT 3

/* MCUCSR BITS */
#define ISC2_BIT  6

/* GICR BITS */
#define INT0_BIT  6
#define INT1_BIT  7
#define INT2_BIT  5

/**********************  ADC  **********************/
#define ADMUX			(*((volatile uint8* const)0x27))
#define ADCSRA			(*((volatile uint8* const)0x26))
#define ADC_VALUE		(*((volatile uint16* const)0x24)) //LOW+HIGH
#define ADCH_Reg        (*(volatile uint8 *)0x25)
#define SFIOR			(*((volatile uint16* const)0x50))

/* ADMUX BITS */
#define REFS1_BIT			7
#define REFS0_BIT			6
#define ADLAR_BIT			5

/* ADSRA bits */
#define ADEN_BIT			7
#define ADSC_BIT			6
#define ADATE_BIT			5
#define ADIF_BIT			4
#define ADCSRA_ADPS0_Bit    0
#define ADCSRA_ADPS1_Bit    1
#define ADCSRA_ADPS2_Bit    2

/**********************  Timer0  **********************/
#define TCCR0     (*((volatile uint8* const)0x53))
#define TIMSK     (*((volatile uint8* const)0x59))
#define TCNT0     (*((volatile uint8* const)0x52))
#define OCR0      (*((volatile uint8* const)0x5C))

/* TCCR0 BITS */
#define WGM00_BIT          6		// Timer/Counter Mode
#define WGM01_BIT          3

#define CS02_BIT           2		// Clock Select
#define CS01_BIT           1
#define CS00_BIT           0

/* TIMSK BITS */
#define OCIE0_BIT          1        // Match Interrupt Enable
#define TOIE0_BIT          0		// Overflow Interrupt Enable


/**********************  Timer1  **********************/
#define TCCR1A     (*((volatile uint8* const)0x4F))
#define TCCR1B     (*((volatile uint8* const)0x4E))
#define OCR1A      (*((volatile uint16* const)0x4A))
#define OCR1B      (*((volatile uint16* const)0x48))
#define ICR1       (*((volatile uint16* const)0x46))

/* TCCR1A BITS */
#define WGM10_BIT          0
#define WGM11_BIT          1

/* TCCR1B BITS */
#define CS10_BIT           0
#define CS11_BIT           1
#define CS12_BIT           2
#define WGM12_BIT          3
#define WGM13_BIT          4
#define ICES1_BIT          6   /* ICU trigger select (0 is falling, 1 is rising) */

/* TIMSK BITS */
#define TICIE1_BIT         5   /* ICU interrupt Enable/Disable */

/**********************Timer_2*************************/
#define TCCR2 *((volatile uint8*)0x45)
#define TCNT2 *((volatile uint8*)0x44)
#define OCR2  *((volatile uint8*)0x43)

/**********************  Watchdog  **********************/


#define WDTCR    (*((volatile uint8* const)0x41))

#define WDTOE_BIT 4  /* watch dog Turn OFF Enable */
#define WDE_BIT   3  /* Watch Dog Enable */
#define WDP2_BIT  2  /* prescaler 2 */
#define WDP1_BIT  1  /* prescaler 1 */
#define WDP0_BIT  0  /* prescaler 0 */



#define UCSRB      (*((volatile uint8* const)0x2A))
#define UCSRA      (*((volatile uint8* const)0x2B))
#define UCSRC      (*((volatile uint8* const)0x40))
#define UBRRH      (*((volatile uint8* const)0x40))
#define UBRRL      (*((volatile uint8* const)0x29))
#define UDR        (*((volatile uint8* const)0x2C))

/*********************EEPROM*****************************/
#define EEARL      (*((volatile uint8* const)0x3E))		//EEPROM Address Register
#define EEARH      (*((volatile uint8* const)0x3F))		//         ""
#define EEDR       (*((volatile uint8* const)0x3D))		//EEPROM Data Register
#define EECR       (*((volatile uint8* const)0x3C))		//EEPROM Control Register

#define EERE_Bit 	0
#define EEWE_Bit 	1
#define EEMWE_Bit   2
#define EERIE_Bit 	3

/***********UCSRB BITS************/
#define TXB8           0
#define RXB8           1
#define UCSZ2          2
#define TXEN           3     //
#define RXEN           4     //
#define UDRIE          5
#define TXCIE          6
#define RXCIE          7

/***********UCSRA BITS************/
#define MPCM           0
#define U2X            1
#define PE             2
#define DOR            3
#define FE             4
#define UDRE           5
#define TXC            6
#define RXC            7			//

/***********UCSRC BITS************/
#define URSEL            7
#define UCSZ0            1


////////////////////////////////////

#define TWSR     (*((volatile uint8* const)0x21))
#define TWDR     (*((volatile uint8* const)0x23))
#define TWCR     (*((volatile uint8* const)0x56))
#define TWBR     (*((volatile uint8* const)0x20))
#define TWAR     (*((volatile uint8* const)0x22))

#define TWINT           0
#define TWSTA            1
#define TWEN             2
#define TWSTO            3
#define TWEA            4

#endif /* MCAL_ATMEGA32_REGISTERMAP_H_ */
