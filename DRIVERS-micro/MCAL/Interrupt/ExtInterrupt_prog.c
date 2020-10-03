/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : External Interrupt DRIVER        */
/*   DATE        : 19 FEB 2020                      */
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
#include "ExtInterrupt_INT.h"
#include "ExtInterrupt_PRIV.h"
/***************************************************/
/*          8 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   8000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <util/delay.h>
/*********************************************************************************************************************************/

/***************************************************************************/
/*						  		Callback Functions					       */
/***************************************************************************/
void (*volatile EXTINT0_Functionp)(void)=NULL;
void (*volatile EXTINT1_Functionp)(void)=NULL;
void (*volatile EXTINT2_Functionp)(void)=NULL;

/***************************************************************************/
/*						  AVR External Interrupt ISRs					   */
/***************************************************************************/

/***********************************************************/
/* 					   ISR For EXTI0					   */
/***********************************************************/
/** Linker Problem solved */
/*void __vector_1(void) __attribute__(( signal , used ));
void __vector_1(void)*/
void __vector_1 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_1	 (void)
{
//      if (EXTINT0_Functionp != NULL)
//	  {
//		EXTINT0_Functionp();
//	  }
	//DressMachine();
	//inthandler ();
	handler();
}

/***********************************************************/
/* 					   ISR For EXTI1					   */
/***********************************************************/
/** Linker Problem solved */
/*void __vector_2(void) __attribute__(( signal , used ));
void __vector_2(void)*/
//void __vector_2 (void)  __attribute__((signal,__INTR_ATTRS));
//void __vector_2	 (void)
//{
////     if (EXTINT1_Functionp != NULL)
////	 {
////		EXTINT1_Functionp();
////     }
//	//spitrans();
//	inthandler();
//}

/***********************************************************/
/* 					   ISR For EXTI2					   */
/***********************************************************/
/** Linker Problem solved */
/*void __vector_3(void) __attribute__(( signal , used ));
void __vector_3(void)*/
void __vector_3 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_3	 (void)
{
    // if (EXTINT2_Functionp != NULL)
	 //{
		//EXTINT2_Functionp();
	//login();
	//spitrans();
}


/******************************************************************************/
/*                         Function: EXT_voidEnable                           */
/*                     I/P Parameters: copy_EXTINT_NUM                        */
/*                        Returns:it returns no thing                         */
/*                    Desc:This Function to Enable the INT.                   */
/******************************************************************************/
void EXT_voidEnable( u8 copy_EXTINT_NUM  )
{
	u8 copy_Sense;
	SET_BIT(SREG,7);
	/* Switching on the interrupts to enable the targeted one */
	switch (copy_EXTINT_NUM)
	{
/**************************************************************************************************************************/
		case EXTINT0 :
							/* Disable INT0 */
							CLR_BIT(GICR,6);
							/* Getting The Sense Mood of INT0 */
							 copy_Sense = EXTI0_SENSE_MODE ;
							/* Switch on the sense mood to configure it */
							switch (copy_Sense)
							{
								case IOC :
											  SET_BIT(MCUCR , 0);
											  CLR_BIT(MCUCR , 1);
											  break;
								case RISING :
											  SET_BIT(MCUCR , 0);
											  SET_BIT(MCUCR , 1);
											  break;
								case FALLING :
									          CLR_BIT(MCUCR , 0);
									          SET_BIT(MCUCR , 1);
											  break;
								case LOW_LEVEL :
							                  CLR_BIT(MCUCR , 0);
							                  CLR_BIT(MCUCR , 1);
					     			          break;
							}
							/* Enable INT0 */
							SET_BIT(GICR,6);
							break;
/**************************************************************************************************************************/
		case EXTINT1 :
						/* Disable INT1 */
						CLR_BIT(GICR,7);
						/* Getting The Sense Mood of INT1 */
						copy_Sense = EXTI1_SENSE_MODE ;
						/* Switch on the sense mood to configure it */
						switch (copy_Sense)
						{
							case IOC :
										  SET_BIT(MCUCR , 2);
										  CLR_BIT(MCUCR , 3);
										  break;
							case RISING :
										  SET_BIT(MCUCR , 2);
										  SET_BIT(MCUCR , 3);
										  break;
							case FALLING :
										  CLR_BIT(MCUCR , 2);
										  SET_BIT(MCUCR , 3);
										  break;
							case LOW_LEVEL :
										  CLR_BIT(MCUCR , 2);
										  CLR_BIT(MCUCR , 3);
										  break;
						}
						/* Enable INT1 */
						SET_BIT(GICR,7);
						break;
/**************************************************************************************************************************/
		case EXTINT2 :
						/* Disable INT1 */
						CLR_BIT(GICR,5);
						/* Getting The Sense Mood of INT1 */
						copy_Sense = EXTI2_SENSE_MODE ;
						/* Switch on the sense mood to configure it */
						switch (copy_Sense)
						{
							case RISING :
								           SET_BIT(MCUCSR , 6);
					   					   break;
							case FALLING :
										   CLR_BIT(MCUCSR , 6);
					    				   break;
						}
						/* Enable INT1 */
						SET_BIT(GICR,5);
						break;
	}

}
/******************************************************************************/
/*                         Function: EXT_voidEnable                           */
/*                      I/P Parameters: copy_EXTINT_NUM                       */
/*                        Returns:it returns no thing                         */
/*                    Desc:This Function to Enable the INT.                   */
/******************************************************************************/
void EXT_voidDisable( u8 copy_EXTINT_NUM )
	{
		switch (copy_EXTINT_NUM)
			{
				case EXTINT0 : CLR_BIT(GICR,6);  break;
				case EXTINT1 : CLR_BIT(GICR,7);  break;
				case EXTINT2 : CLR_BIT(GICR,5);  break;
			}
	}

