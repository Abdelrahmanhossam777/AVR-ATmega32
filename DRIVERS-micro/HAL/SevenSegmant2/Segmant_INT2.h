/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : 7Segmant                         */
/*   DATE        : 2 FEB 2020                       */
/*   VERSION     : V02                              */
/****************************************************/

/* File Guard */
#ifndef HAL_SEVENSEGMANT_SEGMANT_INT_H_
#define HAL_SEVENSEGMANT_SEGMANT_INT_H_



/******************************************************************************/
/*                Function: SevenSegmant_voidIntialization                    */
/*                I/P Parameters: u8 copy_u8SegmantType                       */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Intialize the Seven Segmant                   */
/******************************************************************************/
extern void SevenSegmant_voidIntialization (u8 copy_u8SegmantType);


/******************************************************************************/
/*                  Function: SevenSegmant_voidDisplayNum                     */
/*     	 I/P Parameters: u8 copy_u8SegmantType & u8 copy_u8Number             */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Display on the Seven Segmant                  */
/******************************************************************************/
extern void SevenSegmant_voidDisplayNum (u8 copy_u8SegmantType,u32 copy_u8Number);

#endif /* HAL_SEVENSEGMANT_SEGMANT_INT_H_ */
