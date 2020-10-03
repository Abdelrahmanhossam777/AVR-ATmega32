/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : KB DRIVER                        */
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
#include"KBD_INT.h"
#include"KDB_PRIV.h"

/***************************************************/
/*          8 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   8000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <util/delay.h>


/*********************************************************************************************************************************/
/*Global Array to define the Keypad rows connected to which micro pins */
u8 KBD_u8Rows[KBD_ROW_NUM] = {DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN3};

/*Global Array to define the Keypad Columns connected to which micro pins */
u8 KBD_u8Cols[KBD_COL_NUM] = {DIO_PIN4, DIO_PIN5, DIO_PIN6};

/*Global Array to define what each key in the key pad refers to */
u8 KBD_u8Keys[KBD_ROW_NUM][KBD_COL_NUM] = {
	                                    	{ '1', '2', '3'},
				                        	{ '4', '5', '6'},
				                        	{ '7', '8', '9'},
											{ '@', '0', '*'}
                                          };
/*********************************************************************************************************************************/
/* Initialization to set the keypad pins and ports */
extern void KBD_voidInitialization (void)
{
	/* This instruction is to set half of pins to be input ant the other half to be output */
	DIO_voidSetPortDirection(KBD_PORT_HW, 0b11110000 );
	/* This instruction is to out high on the pins which are o/p and to switch the pull up resistors on for the i/p pins  */
	DIO_voidSetPortValue(KBD_PORT_HW ,0b01111111);
}


extern u8 KBD_u8GetKeyPressed(void)
{
	/* Local Variable to detect the Row index */
	u8 Local_u8RowIndex;
	/* Local Variable to detect the Column index */
	u8 Local_u8ColumnIndex;
	/* To save the value which confirms if the key is pressed or not */
	u8 Local_u8val;

	while (1)
	{

		/* The first for loop is to check on each column individually to set it as 0 */
		for (u8 i=0 ; i < KBD_COL_NUM ; i++)
			{
					/* activate only one column, then read all rows  */
					CLR_BIT( KBD_PORT, KBD_u8Cols[i] );
					/* Store the column index which is the counter of the for loop */
					Local_u8ColumnIndex=i;

					/* The second for loop is to check on each row to cofirm if it is the one or not */
					for(u8 j=0; j<KBD_ROW_NUM; j++)
					{
						/* Get the value of the row to check if it is pressed or not */
						Local_u8val = GET_BIT( KBD_PIN, KBD_u8Rows[j] );
						/*This delay is to fix The bouncing Effect  */
						_delay_ms(20);
						/* Get the value again to make sure it is right after avoiding The Debouncing Effect  */
						Local_u8val = GET_BIT( KBD_PIN, KBD_u8Rows[j] );
						/* Store the row index which is the counter of the for loop */
						Local_u8RowIndex = j;

						/* Check if the key is pressed or not by getting the pin value of the row */
						if (Local_u8val==KBD_KEY_PRESSED)
						{
							/* Return a value from the global array  */
							return KBD_u8Keys[Local_u8RowIndex][Local_u8ColumnIndex];
						}
					}

					/* Deactivate the column again, to activate another column in the next iteration  */
					SET_BIT( KBD_PORT, KBD_u8Cols[i] );
			}
	}
}

/*********************************************************************************************************************************/
