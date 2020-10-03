/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : Timer 0 DRIVER   		        */
/*   DATE        : 29 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_TIMER0_TIMER_INT_H_
#define MCAL_TIMER0_TIMER_INT_H_
/*********************************************************/
/*  Definition of Enable and Disable of the timer modes  */
/*********************************************************/
#define Enable 1
#define Disable 0


/*********************************************************/
/*     Define Which mode you will use the timer for      */
/*********************************************************/
#define OverFlow_Mode Disable
#define CTC_Mode Disable
#define PWM_Mode Enable

/**************************************************************/
/* Timer0/Counter Control Register "TCCR0" Configuration	  */
/**************************************************************/

#define FOC0 0
#define WGM00 1
#define COM01 1
#define COM00 1
#define WGM01 1
#define CS02 0
#define CS01 0
#define CS00 1
/*define number of each bit in the register instead of using magic numbers*/
#define FOC0_bit 7
#define WGM00_bit 6
#define COM01_bit 5
#define COM00_bit 4
#define WGM01_bit 3
#define CS02_bit 2
#define CS01_bit 1
#define CS00_bit 0


//I need to define OC0"b3" as output

/**************************************************************
 * Timer0/Counter Interrupt Mask Register "TIMSK0" Configuration
 **************************************************************/

#define TOIE0 0
#define OCIE0 1

#define TOIE0_bit 0
#define OCIE0_bit 1



/**************************************************************
 * output Compare Register "OCR0" Configuration
 * put the value you want to insert in it in case Compare Match Mode
 **************************************************************/
#if OCIE0 == 1
	#define OCR0_Value 0
#endif




/**************************************************************
 * Timer0/Counter Interrupt Flag Register "TIFR0" Configuration
 **************************************************************/

#define OCF0
#define T0V0
#define OCIE0_bit 1
#define T0IE0_bit 0


/**************************************************************
 * Prototypes of the Global Function
 **************************************************************/

void Timer0_voidInit(void);

#endif /* MCAL_TIMER0_TIMER_INT_H_ */
