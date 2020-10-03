/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : KB DRIVER                        */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_KBD_INT_H_
#define HAL_KBD_INT_H_

/*********************************************************************************************************************************/

/**********************************************************************/
/* Function: KBD_voidInitialization									  */
/* I/P Parameters: It takes nothing.								  */
/* Returns:it returns nothing.										  */
/* Desc:This Function initialize the keypad. 			              */
/**********************************************************************/
extern void KBD_voidInitialization (void);

/**********************************************************************/
/* Function: KBD_u8GetKeyPressed									  */
/* I/P Parameters: It takes nothing.								  */
/* Returns:it returns u8.											  */
/* Desc:This Function returns the key which is pressed.               */
/**********************************************************************/
extern u8 KBD_u8GetKeyPressed(void);

/*********************************************************************************************************************************/

/* End of the file guard */
#endif /* HAL_KBD_INT_H_ */
