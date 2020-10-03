/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : UART DRIVER      			    */
/*   DATE        : 11 MAR 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef MCAL_UART_UART_CONF_H_
#define MCAL_UART_UART_CONF_H_


#define HIGH 1
#define LOW 0
/* The User will enter the Frequency (Crystal Value)manually*/
#define FOCS 8000000

/* Enter the used BaudRate */
#define BaudRate 9600

//================================================================================================

/*
 * UCSRnA Register Configuration
 */

// to double the Speed of the UART
#define U2X LOW
//to enable the multiprocessor Communication Mode
#define MPCM LOW

//===================================================================================================
/*
 *Set Configuration of Register UCSRnB
 */

//enable Receive mode
#define RXEN HIGH
//enable Transmit mode
#define TXEN HIGH
//the remaining Configuration of the data bits plus UCSZ1:0 in UCSRnC
#define UCSZ2 LOW

//======================================================================================================

/*
 *Set Configuration of Register UCSRnC
 */

 //To Select between URSEL (HIGH) or UBRRH (LOW)
#define URSEL HIGH
//to select UART Mode HIGH for Synchronous mode or LOW for ASynchronous
#define UMSEL LOW
// to select the parity mode UPM1:UPM0
/* 0 0 : Disabled
 * 0 1 : reserved
 * 1 0 : Even Parity
 * 1 1 : odd parity
 */
#define UPM1 LOW
#define UPM0 LOW
// to configure the stop bits HIGH for 2-bits || LOW for just 1-bit
#define USBS LOW
// to select number of data bits UCSZ2(from UCSRnB) : UCSZ1 : UCSZ0
/*
 	0 0 0 : 5-bit
	0 0 1 : 6-bit
	0 1 0 : 7-bit
	0 1 1 : 8-bit
	1 0 0 : Reserved
	1 0 1 : Reserved
	1 1 0 : Reserved
	1 1 1 : 9-bit
 */
#define UCSZ1 HIGH
#define UCSZ0 HIGH



#endif /* MCAL_UART_UART_CONF_H_ */
