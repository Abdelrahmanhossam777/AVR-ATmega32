/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : UART DRIVER      			    */
/*   DATE        : 11 MAR 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

extern void UART_Init (void);
extern void UART_TransmitData (u8 UART_DataToBeSent);
extern u8 UART_RecieveData(void);
//extern u8 UART_u8GetReceivedFlag(void);
//extern void UART_voidClrReceivedFlag(void);
//extern void UART_TransmitDataFrames(u8 UART_Frames[]);
extern void UART_voidPrintf(u8 Copy_u8PrintedData[]);


#endif /* MCAL_UART_UART_INT_H_ */
