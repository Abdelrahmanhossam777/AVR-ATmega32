/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : WDT DRIVER   			        */
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
#include "..\..\MCAL\DIO\DIO_INT.h"

/***************************************************/
/*           		WDT Directives 	               */
/***************************************************/
#include "WDT_INT.h"

/***************************************************/
/*          8 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   8000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <util/delay.h>
/*********************************************************************************************************************************/


/*To disable the WDT the bit WDTOE should be on before disabling the WDT*/



extern void WDT_vidInit(WDT_TimeOut TimeOut)
{
	WDTCR |= (1<<WDE_bit);
	WDTCR |= TimeOut;

}
extern void WDT_vidRefresh(void)
{

}

extern void WDT_vidTurnOff(void)
{


	/*To diable the WDT
	 * 1st write one to WDTOE and WDE at the same operation
	 * 2nd  after 4 cycles write zero WDE */


	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<WDTOE_bit) | (1<<WDE_bit);
	/* Turn off WDT */
	WDTCR = 0x00;
}
