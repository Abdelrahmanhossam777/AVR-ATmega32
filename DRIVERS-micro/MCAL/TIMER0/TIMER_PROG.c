/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : Timer 0 DRIVER  			        */
/*   DATE        : 29 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/***************************************************/
/*              Library Directives                 */
/***************************************************/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "../../LIB/Registers.h"

/***************************************************/
/*                 DIO Directives                  */
/***************************************************/
#include "..\DIO\DIO_INT.h"

/***************************************************/
/*           EXT Interrupt Directives              */
/***************************************************/
#include "TIMER_INT.h"

/***************************************************/
/*          8 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   8000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <util/delay.h>
/*********************************************************************************************************************************/


/*Private Variables*/
#if ((GI == 1) && (OverFlow_Mode==Enable))
	static u16 Timer0_NumOfOverflows=0;
#endif

#if ((GI == 1) && (CTC_Mode==Enable || PWM_Mode==Enable))
	static u16 Timer0_CTC_Counter=0;
#endif

/*
 * The ISR of the Overflow of Timer0 mode will be enabled
 * if Global interrupt bit is set to high and
 * if the overflow Interrupt enable bit is set to high in TIMSK
 */

#if ((GI == 1) && (OverFlow_Mode==Enable))
	#if TOIE0 == 1
		void __vector_11 (void)  __attribute__((signal,__INTR_ATTRS));
		void __vector_11 (void)
		{
			Timer0_NumOfOverflows++;
			if(Timer0_NumOfOverflows==46)
			{
				Timer0_NumOfOverflows=0;
				toggle_bit(PORTA,0);
			}
		}
	#endif
#endif
/*
 * the ISR of the Capture Match mode will be enabled
 *  if Global interrupt bit is set to high and
 * if the Capture Match Interrupt enable bit is set to high in TIMSK
 */
#if ((GI == 1) && (CTC_Mode==Enable || PWM_Mode ==Enable))
	#if OCIE0 == 1
		void __vector_10 (void)  __attribute__((signal,__INTR_ATTRS));
		void __vector_10 (void)
		{
			Timer0_CTC_Counter++;
			if(1172==Timer0_CTC_Counter)
			{
				 u32 trans=0;
				 DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
				 DIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_HIGH);
				 _delay_ms(20);
				 DIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				 global_u16DigitalTEM = ADC_u16GetRawData(ADCCH0);
				 global_u8AnalogTEM = (global_u16DigitalTEM * 500) / 1023;
				 while (trans==0)
				 {
					 trans = SPI_voidTranceiver(global_u8AnalogTEM);
				 }


			}

		}
	#endif
#endif


void Timer0_voidInit(void)
{

	#if GI == 1
		/*set the Global interrupt bit value*/
		assign_bit(SREG,GI_bit,GI);
	#endif

	/*fill the value of the TCCR0 Register according to the Configuration*/
	TCCR0 |= (FOC0 << FOC0_bit) | (WGM00 << WGM00_bit) | (COM01 << COM01_bit)
			| (COM00 << COM00_bit) | (WGM01 << WGM01_bit) | (CS02 << CS02_bit)
			| (CS01 << CS01_bit) | (CS00 << CS00_bit);

	/*fill the value of the TIMSK0 Register according to the Configuration*/
	#if ((OCIE0 == 1) && (CTC_Mode==Enable || PWM_Mode == Enable))
	OCR0=OCR0_Value;
	TIMSK |= (OCIE0<<OCIE0_bit);

	#endif

	#if ((TOIE0 == 1) && (OverFlow_Mode==Enable))
		TIMSK |= (TOIE0<<TOIE0_bit);
	#endif

}
