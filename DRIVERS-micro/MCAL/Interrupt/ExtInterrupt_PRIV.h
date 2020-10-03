/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : External Interrupt DRIVER        */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_INTERRUPT_EXTINTERRUPT_PRIV_H_
#define MCAL_INTERRUPT_EXTINTERRUPT_PRIV_H_

/****************************************************************/
/** !comment : Please Enter the Sense Mode						*/
/** 		   SENSE_MODE can be : 								*/
/*					    			FALLING 					*/
/*						    		RISING 						*/
/*							    	LOW_LEVEL					*/
/*								    IOC ( Interrupt On Change ) */
/****************************************************************/
/* For EXTI2 can be FALLING or RISING and nothing else          */
/****************************************************************/

#define EXTI0_SENSE_MODE		FALLING
#define EXTI1_SENSE_MODE		IOC
#define EXTI2_SENSE_MODE		RISING

/****************************************************************/
/** !comment : Sense Mode Definition					   		*/
/****************************************************************/
#define IOC			1
#define FALLING		4
#define RISING		7
#define LOW_LEVEL	10

/****************************************************************/
/** !comment : External Interrupt Definition					*/
/****************************************************************/
#define EXTINT0 0
#define EXTINT1 1
#define EXTINT2 2

#define NULL ((char *)0)

#endif /* MCAL_INTERRUPT_EXTINTERRUPT_PRIV_H_ */
