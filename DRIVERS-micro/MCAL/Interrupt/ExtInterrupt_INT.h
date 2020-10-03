/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : External Interrupt DRIVER        */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_INTERRUPT_EXTINTERRUPT_INT_H_
#define MCAL_INTERRUPT_EXTINTERRUPT_INT_H_


/******************************************************************************/
/* 			   Call Back Pointers for External Interrupt Handling 			  */
/******************************************************************************/
	extern void (*volatile EXTINT0_Functionp)(void);
	extern void (*volatile EXTINT1_Functionp)(void);
	extern void (*volatile EXTINT2_Functionp)(void);

/******************************************************************************/
/*                         Function: EXT_voidEnable                           */
/*                        I/P Parameters: copy_IntNum                         */
/*                        Returns:it returns no thing                         */
/*                    Desc:This Function to Enable the INT.                   */
/******************************************************************************/
void EXT_voidEnable( u8 copy_EXTINT_NUM );

/******************************************************************************/
/*                         Function: EXT_voidEnable                           */
/*                      I/P Parameters: copy_EXTINT_NUM                       */
/*                        Returns:it returns no thing                         */
/*                    Desc:This Function to Enable the INT.                   */
/******************************************************************************/
void EXT_voidDisable( u8 copy_EXTINT_NUM );


#endif /* MCAL_INTERRUPT_EXTINTERRUPT_INT_H_ */
