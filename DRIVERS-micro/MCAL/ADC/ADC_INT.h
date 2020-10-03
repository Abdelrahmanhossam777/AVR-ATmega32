/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : ADC DRIVER   			        */
/*   DATE        : 22 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_


/******************************************************************************/
/*                           Function: ADC_voidInit                           */
/*                          I/P Parameters: no thing                          */
/*                        Returns:it returns no thing                         */
/*             Desc:This Function to Initialize the ADC peripheral.           */
/******************************************************************************/
extern void ADC_voidInitTEMP();
extern void ADC_voidInitLDR();
/******************************************************************************/
/*                           Function: ADC_voidInit                           */
/*                    I/P Parameters: ADC Channel Number                      */
/*                           Returns:it returns u16                           */
/*             		 Desc:This Function to Get a Raw of Data.                 */
/******************************************************************************/
//extern u16 ADC_u16GetRawData(ADCChannels (ADCCHIndex));
/******************************************************************************/
/*                   Function: ADC_u16GetInterruptConvRes                     */
/*                          I/P Parameters: no thing                          */
/*                     	     Returns:it returns u16                           */
/*             Desc:This Function to get the interrupt conversion res.        */
/******************************************************************************/
extern u16 ADC_u16GetInterruptConvRes(void);



#endif /* MCAL_ADC_ADC_INT_H_ */
