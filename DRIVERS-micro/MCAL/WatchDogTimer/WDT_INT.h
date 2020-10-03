/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : WDT DRIVER   			        */
/*   DATE        : 01 MAR 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_WATCHDOGTIMER_WDT_INT_H_
#define MCAL_WATCHDOGTIMER_WDT_INT_H_


#define WDTOE_bit 4
#define WDE_bit 3

typedef enum
{
	T16_3ms,
	T32_5ms,
	T65ms,
	T130ms,
	T260ms,
	T520ms,
	T1s,
	T2s,


}WDT_TimeOut;

/******************************************************************************/
/*                           Function: WDT_vidInit                            */
/*                       I/P Parameters: Enum TimeOut                         */
/*                        Returns:it returns no thing                         */
/*             Desc:This Function to Initialize the WDT peripheral.           */
/******************************************************************************/
extern void WDT_vidInit(WDT_TimeOut TimeOut);
/******************************************************************************/
/*                         Function: WDT_vidRefresh                           */
/*                     	   I/P Parameters: No thing                           */
/*                        Returns:it returns no thing                         */
/*                Desc:This Function to Refresh the WDT peripheral.           */
/******************************************************************************/
extern void WDT_vidRefresh(void);
/******************************************************************************/
/*                          Function: WDT_vidTurnOff                          */
/*                          I/P Parameters: no thing                          */
/*                        Returns:it returns no thing                         */
/*             Desc:This Function to Turn off the WDT peripheral.             */
/******************************************************************************/
extern void WDT_vidTurnOff(void);


#endif /* MCAL_WATCHDOGTIMER_WDT_INT_H_ */
