/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : LCD DRIVER                       */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/

/*********************************************************************************************************************************/

/***************************************************/
/*              Library Directives                 */
/***************************************************/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "../../LIB/Registers.h"

/***************************************************/
/*                 DIO Directives                  */
/***************************************************/
#include "../../MCAL/DIO/DIO_INT.h"

/***************************************************/
/*                 7Seg Directives                 */
/***************************************************/
#include"LCD_INT.h"
#include"LCD_PRIV.h"

/***************************************************/
/*          8 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   8000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <avr\delay.h>
/*********************************************************************************************************************************/

extern void LCD_voidSend_Command (u8 copy_u8Command)
{
	/***********************************/
	/*      Set PORT A & D output      */
	/***********************************/
//	DIO_voidSetPortDirection (LCD_Data_PORT,DIO_OUTPUT);
//	DIO_voidSetPortDirection (LCD_CNT_PORT,DIO_OUTPUT);


	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RS,DIO_LOW);
	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RW,DIO_LOW);
	DIO_voidSetPortValue(LCD_Data_PORT,copy_u8Command);


	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_LOW);
}


extern void LCD_voidIntialization (void)
{
	/* Wait more than 30 ms */
	//_delay_ms(35);

	/***********************************/
	/*      Set PORT A & D output      */
	/***********************************/
	DIO_voidSetPinDirection(LCD_CNT_PORT,LCD_u8RS,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CNT_PORT, LCD_u8RW, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CNT_PORT, LCD_u8EN, DIO_OUTPUT);
	DIO_voidSetPortDirection (LCD_Data_PORT,0b11111111);


	/***********************************/
	/*           Function Set          */
	/***********************************/
	LCD_voidSend_Command(0b00111100);//0->1

	/* Wait more than 30 us */
	_delay_ms(1);

	/***********************************/
	/*     Display off/on control      */
	/***********************************/
	LCD_voidSend_Command(0b00001111);

	/* Wait more than 39 us */
	_delay_ms(1);

	/***********************************/
	/*         Display Clear           */
	/***********************************/
	LCD_voidSend_Command(0b00000001);

	/* Wait more than 1.39 us */
	_delay_ms(1);

	/***********************************/
	/*         Display Clear           */
	/***********************************/

	//LCD_voidSend_Command(0x06);
	/* Wait more than 1.39 ms */
	//_delay_ms(20);


}

extern void LCD_voidSend_Data (u8 copy_u8data)
{
	DIO_voidSetPinValue(LCD_CNT_PORT, LCD_u8RW, DIO_LOW);
	DIO_voidSetPinValue(LCD_CNT_PORT, LCD_u8RS, DIO_HIGH);

	DIO_voidSetPortValue(LCD_Data_PORT,copy_u8data);
	DIO_voidSetPinValue(LCD_CNT_PORT, LCD_u8EN, DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CNT_PORT, LCD_u8EN, DIO_LOW);
}

void LCD_voidSend_String (char *copy_ptrString)
{
	while ( *copy_ptrString > 0 )
	{
		LCD_voidSend_Data (*copy_ptrString++);
	}
}


extern void LCD_voidSend_4bitCommand (u8 copy_u8Command)
{
		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RS,DIO_LOW);
		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RW,DIO_LOW);

		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN4,GET_BIT(copy_u8Command,4));
		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN5,GET_BIT(copy_u8Command,5));
		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN6,GET_BIT(copy_u8Command,6));
		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN7,GET_BIT(copy_u8Command,7));

		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_HIGH);
		_delay_ms(2);
		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_LOW);
		/*///////////////////////////////////////////////////////////////////////////////////*/
		_delay_us(200);
		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RS,DIO_LOW);
		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RW,DIO_LOW);

		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN4,GET_BIT(copy_u8Command,0));
		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN5,GET_BIT(copy_u8Command,1));
		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN6,GET_BIT(copy_u8Command,2));
		DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN7,GET_BIT(copy_u8Command,3));

		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_HIGH);
		_delay_ms(2);
		DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_LOW);
}

extern void LCD_4bitIntialization (void)
{
	DIO_voidSetPinDirection(LCD_CNT_PORT,LCD_u8RS,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CNT_PORT, LCD_u8RW, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CNT_PORT, LCD_u8EN, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_PORT,DIO_PIN4,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_PORT,DIO_PIN5,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_PORT,DIO_PIN6,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_PORT,DIO_PIN7,DIO_OUTPUT);

	_delay_ms(20);

		LCD_voidSend_4bitCommand(0x33);
		LCD_voidSend_4bitCommand(0x32);	/* Send for 4 bit initialization of LCD  */
		LCD_voidSend_4bitCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
		LCD_voidSend_4bitCommand(0x0c);	/* Display on cursor off */
		LCD_voidSend_4bitCommand(0x06);	/* Increment cursor (shift cursor to right) */
		LCD_voidSend_4bitCommand(0x01);	/* Clear display screen */
}


extern void LCD_voidSend_4bitData (u8 copy_u8data)
{
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN4,GET_BIT(copy_u8data,4));
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN5,GET_BIT(copy_u8data,5));
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN6,GET_BIT(copy_u8data,6));
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN7,GET_BIT(copy_u8data,7));
	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RS,DIO_HIGH);
	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_LOW);
	_delay_us(200);
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN4,GET_BIT(copy_u8data,0));
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN5,GET_BIT(copy_u8data,1));
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN6,GET_BIT(copy_u8data,2));
	DIO_voidSetPinValue(LCD_Data_PORT,DIO_PIN7,GET_BIT(copy_u8data,3));
	//DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RS,DIO_HIGH);
	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8EN,DIO_LOW);
}


void LCD_voidSend_4bitString (char *copy_ptrString)
{
	while ( *copy_ptrString > 0 )
	{
		LCD_voidSend_4bitData (*copy_ptrString++);
	}
}

extern void LCD_void4bitDisplayNumber(u32 x)
{
	u32 y = 1;
	if (x == 0)
	{
		LCD_voidSend_4bitData('0');
	}
	if (x < 0) {
		LCD_voidSend_4bitData('-');
		x *= -1;
	}
	while (x != 0) {
		y = ((y * 10) + (x % 10));
		x = (x / 10);
	}
	while (y != 1) {
		LCD_voidSend_4bitData((y % 10) + 48);
		y = (y / 10);
	}
}


void LCD_voidGoToPos(u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	LCD_voidSend_Command(0b10000000);
		if(Copy_u8RowNum==1)
		{
			if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
			{LCD_voidSend_Command(127+Copy_u8ColNum);}
		}
		else if (Copy_u8RowNum==2)
		{
			if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
			{LCD_voidSend_Command(191+Copy_u8ColNum);}
		}
}
void LCD_void4bitGoToPos(u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	LCD_voidSend_4bitCommand(0b10000000);
			if(Copy_u8RowNum==1)
			{
				if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
				{LCD_voidSend_4bitCommand(127+Copy_u8ColNum);}
			}
			else if (Copy_u8RowNum==2)
			{
				if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
				{LCD_voidSend_4bitCommand(191+Copy_u8ColNum);}
			}
}
