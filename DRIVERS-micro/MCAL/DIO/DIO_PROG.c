/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DIO DRIVER                       */
/*   DATE        : 2 FEB 2020                       */
/*   VERSION     : V02                              */
/****************************************************/


/***************************************************/
/*              Library Directives                 */
/***************************************************/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\Registers.h"

/***************************************************/
/*                 DIO Directives                  */
/***************************************************/
#include "DIO_INT.h"


/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/******************************************************************************/
/*                 Function: DIO_voidSetPinDirection                          */
/*         I/P Parameters: Port Number , Pin Number & Pin Direction           */
/*                 Returns:it returns no thing                                */
/*      Desc:This Function Set the direction of the pin input or output       */
/******************************************************************************/
extern void DIO_voidSetPinDirection (u8 copy_u8PortNum, u8 copy_u8PinNum, u8 copy_u8PinDirection)
{
	/*   Input Validation  */
	if ( ( copy_u8PortNum > DIO_PORTD ) || ( copy_u8PortNum < DIO_PORTA ) || ( copy_u8PinNum > DIO_PIN7 ) || ( copy_u8PinNum < DIO_PIN0 ) )
	{
		/* The Function will terminate if the input is not valid */
	 	return;
	}
	else
	{
		/* switching on the ports to enter the required port to set the pin dir. in this port       */
		/* For all the cases the direction of the pin will be checked and that will help with the   */
		/*  clear bit for input as the bit is set to 0 or set bit for output as the bit is set to 1 */
		switch (copy_u8PortNum)
		{
			case DIO_PORTA :
							if (copy_u8PinDirection == DIO_INPUT)
							{
								CLR_BIT(DDRA_REG,copy_u8PinNum);
							}
							else if (copy_u8PinDirection == DIO_OUTPUT)
							{
								SET_BIT(DDRA_REG,copy_u8PinNum);
							}
							break;
			case DIO_PORTB :
							if (copy_u8PinDirection == DIO_INPUT)
							{
								CLR_BIT(DDRB_REG,copy_u8PinNum);
							}
							else if (copy_u8PinDirection == DIO_OUTPUT)
							{
								SET_BIT(DDRB_REG,copy_u8PinNum);
							}
							break;
			case DIO_PORTC :
							if (copy_u8PinDirection == DIO_INPUT)
							{
								CLR_BIT(DDRC_REG,copy_u8PinNum);
							}
							else if (copy_u8PinDirection == DIO_OUTPUT)
							{
								SET_BIT(DDRC_REG,copy_u8PinNum);
							}
							break;
			case DIO_PORTD :
							if (copy_u8PinDirection == DIO_INPUT)
							{
								CLR_BIT(DDRD_REG,copy_u8PinNum);
							}
							else if (copy_u8PinDirection == DIO_OUTPUT)
							{
								SET_BIT(DDRD_REG,copy_u8PinNum);
							}
							break;
			default:
							break;
		}

	}
}
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/******************************************************************************/
/*                    Function: DIO_voidSetPinValue                           */
/*           I/P Parameters: Port Number , Pin Number & Pin Value             */
/*                    Returns:it returns no thing                             */
/*         Desc:This Function Set the direction of the pin High or Low        */
/******************************************************************************/
extern void DIO_voidSetPinValue (u8 copy_u8PortNum, u8 copy_u8PinNum, u8 copy_u8PinValue)
{

		/*   Input Validation  */
		if ( ( copy_u8PortNum > DIO_PORTD ) || ( copy_u8PortNum < DIO_PORTA ) || ( copy_u8PinNum > DIO_PIN7 ) || ( copy_u8PinNum < DIO_PIN0 ) )
		{
			/* The Function will terminate if the input is not valid */
		 	return;
		}
		else
		{
			/* switching on the ports to enter the required port to set the pin value in this port      */
			/* For all the cases the value of the pin will be checked and that will help with the       */
			/*  clear bit for low as the bit is set to 0 or set bit for high as the bit is set to 1     */
			switch (copy_u8PortNum)
			{
				case DIO_PORTA :
								if (copy_u8PinValue == DIO_LOW)
								{
									CLR_BIT(PORTA_REG,copy_u8PinNum);
								}
								else if (copy_u8PinValue == DIO_HIGH)
								{
									SET_BIT(PORTA_REG,copy_u8PinNum);
								}
								break;
				case DIO_PORTB :
								if (copy_u8PinValue == DIO_LOW)
								{
									CLR_BIT(PORTB_REG,copy_u8PinNum);
								}
								else if (copy_u8PinValue == DIO_HIGH)
								{
									SET_BIT(PORTB_REG,copy_u8PinNum);
								}
								break;
				case DIO_PORTC :
								if (copy_u8PinValue == DIO_LOW)
								{
									CLR_BIT(PORTC_REG,copy_u8PinNum);
								}
								else if (copy_u8PinValue == DIO_HIGH)
								{
									SET_BIT(PORTC_REG,copy_u8PinNum);
								}
								break;
				case DIO_PORTD :
								if (copy_u8PinValue == DIO_LOW)
								{
									CLR_BIT(PORTD_REG,copy_u8PinNum);
								}
								else if (copy_u8PinValue == DIO_HIGH)
								{
									SET_BIT(PORTD_REG,copy_u8PinNum);
								}
								break;
				default:
								break;
			}
		}
}
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/******************************************************************************/
/*                    Function: DIO_voidGetPinValue                           */
/*                 I/P Parameters: Port Number , Pin Number                   */
/*                     Returns:it returns U8 Pin Value                        */
/*                   Desc:This Function Get The Pin Value                     */
/******************************************************************************/
extern u8 DIO_u8GetPinValue (u8 copy_u8PortNum, u8 copy_u8PinNum)
{
	/*   Input Validation  */
	if ( ( copy_u8PortNum > DIO_PORTD ) || ( copy_u8PortNum < DIO_PORTA ) || ( copy_u8PinNum > DIO_PIN7 ) || ( copy_u8PinNum < DIO_PIN0 ) )
	{
			/* The Function will terminate if the input is not valid */
			return 2;
	}
	else
	{

		/* switching on the ports to enter the required port to get the pin value from this port      */
		/* For all the cases the value of the pin will be checked and return it to the callee fuction */
		switch (copy_u8PortNum)
			{
				case DIO_PORTA:
								return GET_BIT(PINA_REG,copy_u8PinNum);
								break;

				case DIO_PORTB:
								return GET_BIT(PINB_REG,copy_u8PinNum);
								break;

				case DIO_PORTC:
								return GET_BIT(PINC_REG,copy_u8PinNum);
								break;

				case DIO_PORTD:
								return GET_BIT(PIND_REG,copy_u8PinNum);
								break;

				default:
								return 2;
								break;
			}
	}
}
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/******************************************************************************/
/*                 Function: DIO_voidSetPortDirection                         */
/*               I/P Parameters: Port Number & Port Direction                 */
/*                     Returns:it returns no thing                            */
/*      	   Desc:This Function Set the direction of the port  		      */
/******************************************************************************/
extern void DIO_voidSetPortDirection (u8 copy_u8PortNum , u8 copy_u8PortDirection )
{
	/*   Input Validation  */
		if ( ( copy_u8PortNum > DIO_PORTD ) || ( copy_u8PortNum < DIO_PORTA ) )
		{
				/* The Function will terminate if the input is not valid */
				return ;
		}
		else
		{
			/* switching on the ports to enter the required port to set the pins dir. in this port      */
			/* For all the cases the value of the pin will be checked and that will help with the       */
			/* clear bit for input as the bit is set to 0 or set bit for output as the bit is set to 1  */
			/* This will happen using a loop to check on each pin individually						    */
			switch(copy_u8PortNum)
			{
				case DIO_PORTA:
								DDRA_REG = copy_u8PortDirection;
								break;
				case DIO_PORTB:
								DDRB_REG = copy_u8PortDirection;
								break;
				case DIO_PORTC:
								DDRC_REG = copy_u8PortDirection;
								break;
				case DIO_PORTD:
								DDRD_REG = copy_u8PortDirection;
								break;

						default:
								break;
					}
		}
}
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/******************************************************************************/
/*                    Function: DIO_voidSetPortValue                          */
/*               I/P Parameters: Port Number & Port Direction                 */
/*                     Returns:it returns no thing                            */
/*      		  Desc:This Function Set the value of the port   		      */
/******************************************************************************/
extern void DIO_voidSetPortValue (u8 copy_u8PortNum , u8 copy_u8PortValue )
{

	/* switching on the ports to enter the required port to set the pins val. in this port      */
	/* For all the cases the value of the pin will be checked and that will help with the       */
	/* clear bit for low as the bit is set to 0 or set bit for high as the bit is set to 1      */
	/* This will happen using a loop to check on each pin individually						    */
	switch(copy_u8PortNum)
		{
			case DIO_PORTA:
							PORTA_REG= copy_u8PortValue;
							break;
			case DIO_PORTB:
							PORTB_REG= copy_u8PortValue;
											break;
			case DIO_PORTC:
							PORTC_REG= copy_u8PortValue;
							break;
			case DIO_PORTD:
							PORTD_REG= copy_u8PortValue;
							break;

				default:
				break;
		}
}

