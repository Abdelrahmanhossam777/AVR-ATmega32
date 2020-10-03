/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : ADC DRIVER   			        */
/*   DATE        : 22 FEB 2020                      */
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
/*           		ADC Directives 	               */
/***************************************************/
#include "ADC_INT.h"
#include "ADC_PRIV.h"
#include "ADC_CONF.h"

/***************************************************/
/*          8 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   8000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <util/delay.h>
/*********************************************************************************************************************************/


static void ADC_voidStartConversion(void);
static u16 ADC_u16ConversionResult = 0;
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/******************************************************************************/
/*                           Function: ADC_voidInit                           */
/*                          I/P Parameters: no thing                          */
/*                        Returns:it returns no thing                         */
/*             Desc:This Function to Initialize the ADC peripheral.           */
/******************************************************************************/
extern void ADC_voidInitTEMP()
{
	/*a pointer to point to the structure that contains the configuration*/

		ADCconfig * ptr = &ConfiurationTEMP;
		/*Configuration of ADMUX Register*/
		ADMUX |= ptr->VoltRef;
		ADMUX |= ptr->AdjResFormat;
		ADMUX |= ptr->ADCCH;


		/*Configuration of ADCSRA Register*/
		//ADCSRA |= 0b10000000;
		/*Enable ADc Peripheral*/
		SET_BIT(ADCSRA,7);
		ADCSRA  |=  ptr->INTState;
		ADCSRA  |=  ptr->PreDivFactor;
		ADCSRA  |= ptr-> INTState;
		if(ptr->INTState==Enable)
		{
			SREG |= (1<<7);
		}

		/* stil need to enable the interrupt of the ADC
		if(ptr->INTState==Enable)
		{
			ADCSRA &= 0b00001000;
		}
		 if(ptr->INTState==Disable)
		{
			ADCSRA &= 0b11110111;
		}

		*/
}


extern void ADC_voidInitTEMP2()
{
	/*a pointer to point to the structure that contains the configuration*/

		ADCconfig * ptr = &ConfiurationTEMP2;
		/*Configuration of ADMUX Register*/
		ADMUX |= ptr->VoltRef;
		ADMUX |= ptr->AdjResFormat;
		ADMUX |= ptr->ADCCH;


		/*Configuration of ADCSRA Register*/
		//ADCSRA |= 0b10000000;
		/*Enable ADc Peripheral*/
		SET_BIT(ADCSRA,7);
		ADCSRA  |=  ptr->INTState;
		ADCSRA  |=  ptr->PreDivFactor;
		ADCSRA  |= ptr-> INTState;
		if(ptr->INTState==Enable)
		{
			SREG |= (1<<7);
		}

		/* stil need to enable the interrupt of the ADC
		if(ptr->INTState==Enable)
		{
			ADCSRA &= 0b00001000;
		}
		 if(ptr->INTState==Disable)
		{
			ADCSRA &= 0b11110111;
		}

		*/
}
extern void ADC_voidInitLDR()
{
	/*a pointer to point to the structure that contains the configuration*/

		ADCconfig * ptr = &ConfiurationLDR;
		/*Configuration of ADMUX Register*/
		ADMUX |= ptr->VoltRef;
		ADMUX |= ptr->AdjResFormat;
		ADMUX |= ptr->ADCCH;


		/*Configuration of ADCSRA Register*/
		//ADCSRA |= 0b10000000;
		/*Enable ADc Peripheral*/
		SET_BIT(ADCSRA,7);
		ADCSRA  |=  ptr->INTState;
		ADCSRA  |=  ptr->PreDivFactor;
		ADCSRA  |= ptr-> INTState;
		if(ptr->INTState==Enable)
		{
			SREG |= (1<<7);
		}

		/* still need to enable the interrupt of the ADC
		if(ptr->INTState==Enable)
		{
			ADCSRA &= 0b00001000;
		}
		 if(ptr->INTState==Disable)
		{
			ADCSRA &= 0b11110111;
		}

		*/
}


/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/******************************************************************************/
/*                           Function: ADC_voidInit                           */
/*                    I/P Parameters: ADC Channel Number                      */
/*                           Returns:it returns u16                           */
/*             		 Desc:This Function to Get a Raw of Data.                 */
/******************************************************************************/
extern u16 ADC_u16GetRawData(ADCChannels ADCCHIndex)
{
	/*Local variable to save the Raw data of the ADC conversion result*/
		u16 LOC_u16ADCResult=(u16)0x0000;

		/*pointer to the Configuration structure*/
		ADCconfig * ptr = &ConfiurationTEMP;

		/*
		 *
		 * Selecting the ADC Channel
		 *
		 */

		CLR_BIT(ADCSRA,7);


		/*first zeros the ADC channel bits*/
		ADMUX &=0b11100000;
		/*second select the channel according*/
		ADMUX |= (ADCCHIndex);


		SET_BIT(ADCSRA,7);

		/*set ADC to start Conversion*/
		ADC_voidStartConversion();
		/*Polling on the ADC Interrupt Flag to know if conversion complete or not yet*/
		while ( GET_BIT(ADCSRA,4)==0);

		/*Clear Interrupt flag By writing Logical one to it */
		ADCSRA |= (1<<4);

		if(ptr->AdjResFormat==LeftAdjustment)
		{
			/*
			 * According to the data sheet P:215 you have to read ADCL first before ADCH
			 */


			LOC_u16ADCResult =(u16) ADCL;
			LOC_u16ADCResult = (u16) ( (ADCH << 8)  |  LOC_u16ADCResult );
		}
			else if(ptr->AdjResFormat==RightAdjutment)
			{
				/*
				 * According to the data sheet P:215 you have to read ADCL first before ADCH
				 */

				LOC_u16ADCResult = (u16) ADCL;
				LOC_u16ADCResult = (u16) ( (ADCH << 8) | (LOC_u16ADCResult) );
			}
			else
			{

			}

			return LOC_u16ADCResult;

}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/******************************************************************************/
/*                   Function: ADC_u16GetInterruptConvRes                     */
/*                          I/P Parameters: no thing                          */
/*                     	     Returns:it returns u16                           */
/*             Desc:This Function to get the interrupt conversion res.        */
/******************************************************************************/
extern u16 ADC_u16GetInterruptConvRes(void)
{
	return ADC_u16ConversionResult;
}
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
static void ADC_voidStartConversion(void)
{
	ADCSRA  |=  (1<<6);
}
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
void __vector_16 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_16(void)
{
	ADCconfig * ptr = &ConfiurationTEMP;


	if(ptr->AdjResFormat==LeftAdjustment)
		{
		ADC_u16ConversionResult =(u16) ADCH;
		ADC_u16ConversionResult = (u16) ((ADC_u16ConversionResult << 8)  |  (ADCL));
		ADC_u16ConversionResult = (u16) (ADC_u16ConversionResult >> 6);
		}
		else if(ptr->AdjResFormat==RightAdjutment)
		{
			ADC_u16ConversionResult = (u16) ADCH;
			ADC_u16ConversionResult = (u16) (ADC_u16ConversionResult << 8) | (ADCL);
		}

}
