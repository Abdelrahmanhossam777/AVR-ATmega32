/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : LCD DRIVER                       */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_

/******************************************************************************/
/*                        Function: LCD_Intialization                         */
/*                         I/P Parameters: No Thing                           */
/*                        Returns:it returns no thing                         */
/*            Desc:This Function to intialize the LCD in 8-bit mode           */
/******************************************************************************/
extern void LCD_voidIntialization (void);

/******************************************************************************/
/*                      Function: LCD_4bitIntialization                       */
/*                         I/P Parameters: No Thing                           */
/*                        Returns:it returns no thing                         */
/*            Desc:This Function to intialize the LCD in 4-bit mode           */
/******************************************************************************/
extern void LCD_void4bitIntialization (void);

/******************************************************************************/
/*                          Function: Send_Command                            */
/*                      I/P Parameters: copy_u8Command                        */
/*                        Returns:it returns no thing                         */
/*       Desc:This Function to send a command to the lcd  in 8-bit mode       */
/******************************************************************************/
extern void LCD_voidSend_Command (u8 copy_u8Command);

/******************************************************************************/
/*                        Function: Send_4bitCommand                          */
/*                      I/P Parameters: copy_u8Command                        */
/*                        Returns:it returns no thing                         */
/*     Desc:This Function to send a command to the lcd in 4-bit mode          */
/******************************************************************************/
extern void LCD_voidSend_4bitCommand (u8 copy_u8Command);

/******************************************************************************/
/*                           Function: Send_Data                              */
/*                        I/P Parameters: copy_u8Data                         */
/*                        Returns:it returns no thing                         */
/*          Desc:This Function to send DATA to the lcd in 8-bit mode          */
/******************************************************************************/
extern void LCD_voidSend_Data (u8 copy_u8data);

/******************************************************************************/
/*                         Function: Send_4bitData                            */
/*                        I/P Parameters: copy_u8Data                         */
/*                        Returns:it returns no thing                         */
/*          Desc:This Function to send DATA to the lcd in 4-bit mode          */
/******************************************************************************/
extern void LCD_voidSend_4bitData (u8 copy_u8data);

/******************************************************************************/
/*                           Function: Send_String                            */
/*                    I/P Parameters: *copy_ptrString                         */
/*                        Returns:it returns no thing                         */
/*         Desc:This Function to send STRING to the lcd in 8-bit mode         */
/******************************************************************************/
extern void LCD_voidSend_String (char *copy_ptrString);

/******************************************************************************/
/*                       Function: Send_4bitString                            */
/*                    I/P Parameters: *copy_ptrString                         */
/*                        Returns:it returns no thing                         */
/*         Desc:This Function to send STRING to the lcd in 4-bit mode         */
/******************************************************************************/
extern void LCD_voidSend_4bitString (char *copy_ptrString);

/******************************************************************************/
/*                       Function: LCD_voidGoToPos                            */
/*             I/P Parameters: Copy_u8RowNum,u8 Copy_u8ColNum                 */
/*                        Returns:it returns no thing                         */
/*      Desc:This Function to go to posetion on the lcd in 8-bit mode         */
/******************************************************************************/
extern void LCD_voidGoToPos(u8 Copy_u8RowNum,u8 Copy_u8ColNum);

/******************************************************************************/
/*                       Function: LCD_voidGoToPos                            */
/*             I/P Parameters: Copy_u8RowNum,u8 Copy_u8ColNum                 */
/*                        Returns:it returns no thing                         */
/*      Desc:This Function to go to posetion on the lcd in 4-bit mode         */
/******************************************************************************/
extern void LCD_void4bitGoToPos(u8 Copy_u8RowNum,u8 Copy_u8ColNum);


extern void LCD_void4bitDisplayNumber(u32 x);


/* End of the file guard */
#endif /* HAL_LCD_INT_H_ */
