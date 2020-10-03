/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SPI DRIVER   			        */
/*   DATE        : 01 MAR 2020                      */
/*   VERSION     : V01                              */
/****************************************************/
/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


#define Slave
/**********************************************************************/
/* Function: SPI_voidinitialization									  */
/* I/P Parameters: It takes no thing.								  */
/* Returns:it returns nothing.										  */
/* Desc:This Function initialize the SPI.			  	              */
/**********************************************************************/
extern void SPI_voidinitialization(void);
/**********************************************************************/
/* Function: SPI_voidTranceiver										  */
/* I/P Parameters: It takes u8 var. data to be sent					  */
/* Returns:it returns u8 var. data to be received					  */
/* Desc:This Function transmit. and receive using SPI.			      */
/**********************************************************************/
extern u8 SPI_voidTranceiver(u8 data);



#endif /* MCAL_SPI_SPI_INT_H_ */
