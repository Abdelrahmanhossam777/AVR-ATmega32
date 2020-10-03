/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : 7Segmant                         */
/*   DATE        : 2 FEB 2020                       */
/*   VERSION     : V02                              */
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
#include "..\..\MCAL\DIO\DIO_INT.h"

/***************************************************/
/*                 7Seg Directives                 */
/***************************************************/
#include "Segmant_INT2.h"
#include "Segmant_PRIV2.h"

/* Following This Table For Common Cathode */
/***********************************************/
/* Decimal | Dot | g | f | e | d | c | b | a | */
/*    0    |  0  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    1    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 0 | */
/*    2    |  0  | 1 | 0 | 1 | 1 | 0 | 1 | 1 | */
/*    3    |  0  | 1 | 0 | 0 | 1 | 1 | 1 | 1 | */
/*    4    |  0  | 1 | 1 | 0 | 0 | 1 | 1 | 0 | */
/*    5    |  0  | 1 | 1 | 0 | 1 | 1 | 0 | 1 | */
/*    6    |  0  | 1 | 1 | 1 | 1 | 1 | 0 | 1 | */
/*    7    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 1 | */
/*    8    |  0  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    9    |  0  | 1 | 1 | 0 | 1 | 1 | 1 | 1 | */
/***********************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/* Following This Table For Common Anode */
/***********************************************/
/* Decimal | Dot | g | f | e | d | c | b | a | */
/*    0    |  0  | 1 | 0 | 0 | 0 | 0 | 0 | 0 | */
/*    1    |  0  | 1 | 1 | 1 | 1 | 0 | 0 | 1 | */
/*    2    |  0  | 0 | 1 | 0 | 0 | 1 | 0 | 0 | */
/*    3    |  0  | 0 | 1 | 1 | 0 | 0 | 0 | 0 | */
/*    4    |  0  | 0 | 0 | 1 | 1 | 0 | 0 | 1 | */
/*    5    |  0  | 0 | 0 | 1 | 0 | 0 | 1 | 0 | */
/*    6    |  0  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | */
/*    7    |  0  | 1 | 1 | 1 | 1 | 0 | 0 | 0 | */
/*    8    |  0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | */
/*    9    |  0  | 0 | 0 | 1 | 0 | 0 | 0 | 0 | */
/***********************************************/


/******************************************************************************/
/*                Function: SevenSegmant_voidIntialization                    */
/*                I/P Parameters: u8 copy_u8SegmantType                       */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Intialize the Seven Segmant                   */
/******************************************************************************/
extern void SevenSegmant_voidIntialization (u8 copy_u8SegmantType)
{
	/* Setting the port to output */
	DIO_voidSetPortDirection(SevenSegmant_Port ,0xFF);
	/* turning all the segmants on based on the typr of the Seven Segmant */
	if (copy_u8SegmantType == SevenSegmant_Cathode)
	{
		//DIO_voidSetPortValue(SevenSegmant_Port,0b00111111);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
	}

	else if (copy_u8SegmantType == SevenSegmant_Anode)
	{
		//DIO_voidSetPortValue(SevenSegmant_Port,0b01000000);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
		DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
	}


}

/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/
/******************************************************************************/
/*                  Function: SevenSegmant_voidDisplayNum                     */
/*     	 I/P Parameters: u8 copy_u8SegmantType & u8 copy_u8Number             */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Display on the Seven Segmant                  */
/******************************************************************************/
extern void SevenSegmant_voidDisplayNum (u8 copy_u8SegmantType,u32 copy_u8Number)
{
	if (copy_u8SegmantType == SevenSegmant_Cathode)
	{
		switch (copy_u8Number)
		{
		  case 0 :
			  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b00111111);
			  	        DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);

			  	  break;
		  case 1 :
			  	  DIO_voidSetPortValue(SevenSegmant_Port,0b00000110);
			  	  	  	DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
			   	  break;
		  case 2 :
			  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b01011011);
			  	  	    DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
			  	  break;
		  case 3 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b01001111);
		  	  	  	    DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
		  	  	  break;
		  case 4 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b01100110);
		  	  	        DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
		  	  	  break;
		  case 5 :
		  	  	  DIO_voidSetPortValue(SevenSegmant_Port,0b01101101);
		  	  	  	  	DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
		  	  	  break;
		  case 6 :
		  	  	  DIO_voidSetPortValue(SevenSegmant_Port,0b01111101);
		  	  	  	    DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
		  	  	  break;
		  case 7 :
		  	  	  DIO_voidSetPortValue(SevenSegmant_Port,0b00000111);
		  	  	  	    DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
		  	  	  break;
		  case 8 :
			  	  DIO_voidSetPortValue(SevenSegmant_Port,0b01111111);
			  	  	    DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
		  	  	  break;
		  case 9 :
		  	  	  DIO_voidSetPortValue(SevenSegmant_Port,0b01101111);
		  	  	  	    DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
		  	  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
		  	  	  break;
		  default:
			  	  break;
		}
	}
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
	else if (copy_u8SegmantType == SevenSegmant_Anode)
	{
		switch (copy_u8Number)
		{
		  case 0 :
			  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b01000000);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
			  	  break;
		  case 1 :
			  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b01111001);
			  	  	    DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
			   	  break;
		  case 2 :
			  	 //DIO_voidSetPortValue(SevenSegmant_Port,0b00100100);
			  	  	  	DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
			  			DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
			  	  break;
		  case 3 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b00110000);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);

		  	  	  break;
		  case 4 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b00011001);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
		  	  	  break;
		  case 5 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b00010010);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
		  	  	  break;
		  case 6 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b00000010);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
		  	  	  break;
		  case 7 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b01111000);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_HIGH);
		  	  	  break;
		  case 8 :
			  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b00000000);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
		  	  	  break;
		  case 9 :
		  	  	  //DIO_voidSetPortValue(SevenSegmant_Port,0b00010000);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN1,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN2,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN4,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN5,DIO_HIGH);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN6,DIO_LOW);
						DIO_voidSetPinValue(SevenSegmant_Port,DIO_PIN7,DIO_LOW);
		  	  	  break;
		  default:
		  		  break;
		}
	}
}
