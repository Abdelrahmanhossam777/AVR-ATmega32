/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : ADC DRIVER   			        */
/*   DATE        : 22 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_ADC_ADC_CONF_H_
#define MCAL_ADC_ADC_CONF_H_

ADCconfig ConfiurationTEMP =
{
	/*AVCC with external capacitor*/
	AVCC5v,
	/*The right Adjustment mode for the conversion result*/
	RightAdjutment,
	/* Channel Number 0 For ADC */
	ADCCH0,
	/* Disable the ADC Interrupt */
	Disable,
	/* Prescaler 16 */
	DivBy16

};
ADCconfig ConfiurationTEMP2 =
{
	/*AVCC with external capacitor*/
	AVCC5v,
	/*The right Adjustment mode for the conversion result*/
	RightAdjutment,
	/* Channel Number 0 For ADC */
	ADCCH1,
	/* Disable the ADC Interrupt */
	Disable,
	/* Prescaler 16 */
	DivBy16

};

ADCconfig ConfiurationLDR =
{
	/*AVCC with external capacitor*/
	AVCC5v,
	/*The right Adjustment mode for the conversion result*/
	RightAdjutment,
	/* Channel Number 0 For ADC */
	ADCCH1,
	/* Disable the ADC Interrupt */
	Disable,
	/* Prescaler 16 */
	DivBy16

};


#endif /* MCAL_ADC_ADC_CONF_H_ */
