  /***************************************************************
 *  Source File: EF_PWM.c
 *
 *  Description: PWM driver for ATMEGA32
 *
 **************************************************************/
#include "timer.h"


/*********************************************************************
* Function    : timer0_init(void);
*
* DESCRIPTION : Initializes Timer0 with 1024 prescaler.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing.
***********************************************************************/
void timer0_init(void)
{
	    	/* Disable Timer 0 */
	    	TCCR0 = 0x00;
	    	/* Setting pre scaler */
	    	TCCR0 = (0x01);
	    	/* Initializing the timer with zero */
	    	TCNT0 = 0x00;
				/* Timer overflow interrupt enable*/
				TIMSK |=(1<<0);

	return;
}
