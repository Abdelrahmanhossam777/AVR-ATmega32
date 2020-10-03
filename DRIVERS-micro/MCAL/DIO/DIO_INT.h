/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DIO DRIVER                       */
/*   DATE        : 2 FEB 2020                       */
/*   VERSION     : V02                              */
/****************************************************/
#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

/**************************************************/
/* Description : Definitions for DIO HIGH and LOW */
/**************************************************/
#define DIO_HIGH            1
#define DIO_LOW             0

/***************************************************/
/* Description : INPUT OUTPUT Definitions          */
/***************************************************/
#define   DIO_OUTPUT   1
#define   DIO_INPUT    0

/**************************************/
/*           Avilable Groups          */
/**************************************/
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

/**************************************/
/*        Avilable Pins Number        */
/**************************************/
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

/******************************************************************************/
/*                 Function: DIO_voidSetPinDirection                          */
/*         I/P Parameters: Port Number , Pin Number & Pin Direction           */
/*                 Returns:it returns no thing                                */
/*      Desc:This Function Set the direction of the pin input or output       */
/******************************************************************************/
extern void DIO_voidSetPinDirection (u8 copy_u8PortNum, u8 copy_u8PinNum, u8 copy_u8PinDirection);


/******************************************************************************/
/*                    Function: DIO_voidSetPinValue                           */
/*           I/P Parameters: Port Number , Pin Number & Pin Value             */
/*                    Returns:it returns no thing                             */
/*         Desc:This Function Set the direction of the pin High or Low        */
/******************************************************************************/
extern void DIO_voidSetPinValue (u8 copy_u8PortNum, u8 copy_u8PinNum, u8 copy_u8PinValue);


/******************************************************************************/
/*                    Function: DIO_voidGetPinValue                           */
/*                 I/P Parameters: Port Number , Pin Number                   */
/*                     Returns:it returns U8 Pin Value                        */
/*                   Desc:This Function Get The Pin Value                     */
/******************************************************************************/
extern u8 DIO_u8GetPinValue (u8 copy_u8PortNum, u8 copy_u8PinNum);

/******************************************************************************/
/*                 Function: DIO_voidSetPinDirection                          */
/*               I/P Parameters: Port Number & Port Direction                 */
/*                     Returns:it returns no thing                            */
/*      Desc:This Function Set the direction of the port input or output      */
/******************************************************************************/
extern void DIO_voidSetPortDirection (u8 copy_u8PortNum , u8 copy_u8PortDirection );

/******************************************************************************/
/*                 Function: DIO_voidSetPinDirection                          */
/*               I/P Parameters: Port Number & Port Direction                 */
/*                     Returns:it returns no thing                            */
/*        Desc:This Function Set the value of the port input or output        */
/******************************************************************************/
extern void DIO_voidSetPortValue (u8 copy_u8PortNum , u8 copy_u8PortValue );




#endif /* MCAL_DIO_DIO_INT_H_ */
