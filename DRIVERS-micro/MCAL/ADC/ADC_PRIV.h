/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : ADC DRIVER   			        */
/*   DATE        : 22 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

/****************************************************************************/
/** !comment : Please choose the Voltage Mode				    			*/
/** 		  Voltage_MODE can be : 										*/
/*					    			AREF Internal vref turned off  			*/
/*						    		AVCC with external capacitor 			*/
/*							    	Internal with 2.56volt					*/
/****************************************************************************/
/* The enum is a named constant or list of constants and it 				*/
/* will take place in memory after initialize it							*/
/****************************************************************************/
typedef enum
{
		AREFpin=0b00000000,
		AVCC5v=0b01000000,
		Internal2_56v=0b11000000,

}VoltageRef;

/****************************************************************************/
/** !comment : Please choose the Adjutment Mode				    			*/
/** 		  Adjutment_MODE can be : 										*/
/*					    			RightAdjutment  						*/
/*						    		LeftAdjustment 							*/
/*	it affect the Adjustment of the conversion result weither left or right	*/
/****************************************************************************/
/* The enum is a named constant or list of constants and it 				*/
/* will take place in memory after initialize it							*/
/****************************************************************************/
typedef enum
{
	RightAdjutment=0b00000000,
	LeftAdjustment=0b00100000

}AdjustFormat;

/****************************************************************************/
/** !comment : Please choose the Channel NUMBER				    			*/
/** 		  Channel_NUM can be : 											*/
/*					    			ADCCH0 to ADCCH9  						*/
/*	To choose the Channel will be activated for the AD Conversion			*/
/****************************************************************************/
/* The enum is a named constant or list of constants and it 				*/
/* will take place in memory after initialize it							*/
/****************************************************************************/
typedef enum
{
	ADCCH0=0b00000000,
	ADCCH1=0b00000001,
	ADCCH2=0b00000010,
	ADCCH3=0b00000011,
	ADCCH4=0b00000100,
	ADCCH5=0b00000101,
	ADCCH6=0b00000110,
	ADCCH7=0b00000111

}ADCChannels;

/****************************************************************************/
/** !comment : Please choose the Interrupt Mode				    			*/
/** 		  INTERRUPT_MODE can be : 										*/
/*					    			Enable or Disable  						*/
/*	To Enable or disable the interrupt that related to the ADC peripheral	*/
/****************************************************************************/
/* The enum is a named constant or list of constants and it 				*/
/* will take place in memory after initialize it							*/
/****************************************************************************/
typedef enum
{
	Disable=0b00000000,
	Enable=0b00001000

}InterruptState;

/****************************************************************************/
/** !comment : Please choose the Pre-Scales Mode				   			*/
/** 		  Prescales_MODE can be : 										*/
/*			ADPS2			ADPS1			ADPS0			Division Factor */
/*			  0	      |	      0	      | 	  0	     | 	    		2 		*/
/*			  0	      |	      0	      | 	  1	     | 	    		2 		*/
/*			  0	      |	      1	      | 	  0	     | 	    		4 		*/
/*			  0	      |	      1	      | 	  1	     | 	    		8 		*/
/*			  1	      |	      0	      | 	  0	     | 	    	    16 		*/
/*			  1	      |	      0	      | 	  1	     | 	    		32 		*/
/*			  1	      |	      1	      | 	  0	     | 	    		64 		*/
/*			  1	      |	      1	      | 	  1	     | 	    		128 	*/
/****************************************************************************/
/* The enum is a named constant or list of constants and it 				*/
/* will take place in memory after initialize it							*/
/****************************************************************************/
typedef enum
{
	DivBy2=0b00000000,
//	DivBy2=0b00000001,
	DivBy4=0b00000010,
	DivBy8=0b00000011,
	DivBy16=0b00000100,
	DivBy32=0b00000101,
	DivBy64=0b00000110,
	DivBy128=0b00000111

}Prescales;


/****************************************************************************/
/* The Structure to choose a combination between all the enums that we  	*/
/* we created Earlier in the configuration file								*/
/****************************************************************************/
typedef struct
{
	/*the Member that configure the Reference voltage */
	VoltageRef VoltRef;
	/*the Member that configure the Result Adjust Format */
	AdjustFormat AdjResFormat;
	/*The Member that contain the ADC Channel*/
	ADCChannels ADCCH;
	/*The Member that contain the ADC Interrupt state*/
	InterruptState INTState;
	/*The Member that contain the ADC Prescale Division factor*/
	Prescales PreDivFactor;

}ADCconfig;



#endif /* MCAL_ADC_ADC_PRIV_H_ */
