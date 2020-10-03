/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SPI DRIVER   			        */
/*   DATE        : 01 MAR 2020                      */
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
#include "../DIO/DIO_INT.h"

/***************************************************/
/*           	  SPI Directives 	               */
/***************************************************/
#include "SPI_INT.h"

/***************************************************/
/*          8 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   8000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <util/delay.h>
/*********************************************************************************************************************************/

/**********************************************************************/
/* Function: SPI_voidinitialization									  */
/* I/P Parameters: It takes no thing.								  */
/* Returns:it returns nothing.										  */
/* Desc:This Function initialize the SPI.			  	              */
/**********************************************************************/
extern void SPI_voidinitialization(void)
{
#ifdef Master

	/*Define Slave Select pin as output*/
	DIO_voidSetPinDirection (DIO_PORTB,DIO_PIN4,DIO_OUTPUT);
	/*Define MOSI pin as output*/
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);
	/*Define MISO pin as input*/
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);
	/*Define Clock pin as output*/
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);

	/*Set master/slave bit to one to initialize as a master */
	SET_BIT(SPCR,4);

#endif

#ifdef Slave

	/*Define Slave Select pin as Input*/
		DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_INPUT);
		/*Define MOSI pin as input*/
		DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_INPUT);
		/*Define MISO pin as DIO_OUTPUT*/
		DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);
		/*Define Clock pin as input*/
		DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_INPUT);

		/*Set master/slave bit to one to initialize as a master */
		CLR_BIT(SPCR,4);
#endif
SET_BIT(SPCR,6);
CLR_BIT(SPCR,5);
CLR_BIT(SPCR,3);


}
/**********************************************************************/
/* Function: SPI_voidTranceiver										  */
/* I/P Parameters: It takes u8 var. data to be sent					  */
/* Returns:it returns u8 var. data to be received					  */
/* Desc:This Function transmit. and receive using SPI.			      */
/**********************************************************************/
extern u8 SPI_voidTranceiver(u8 data)
{
#ifdef Master
	/*Select the slave By pull down the SS pin */
	CLR_BIT(PORTB_REG,4);
#endif

	SPDR=data;

	while (GET_BIT(SPSR,7)==0);
#ifdef Slave
	/*Select the slave By pull down the SS pin */
	SET_BIT(PORTB_REG,4);
#endif

	return SPDR;
}
