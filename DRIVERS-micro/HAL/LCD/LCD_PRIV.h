/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : LCD DRIVER                       */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/
/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_LCD_PRIV_H_
#define HAL_LCD_PRIV_H_

/*********************************************/
/*         control pins configuration 		 */
/*********************************************/
#define LCD_u8RS    DIO_PIN4
#define LCD_u8RW	DIO_PIN5
#define LCD_u8EN	DIO_PIN6

/*********************************************/
/*          Data Pins configuration 		 */
/*********************************************/
#define LCD_u8DATA_0    DIO_PIN0
#define LCD_u8DATA_1	DIO_PIN1
#define LCD_u8DATA_2	DIO_PIN2
#define LCD_u8DATA_3	DIO_PIN3
#define LCD_u8DATA_4	DIO_PIN4
#define LCD_u8DATA_5	DIO_PIN5
#define LCD_u8DATA_6	DIO_PIN6
#define LCD_u8DATA_7	DIO_PIN7

#define LCD_Data_PORT   DIO_PORTC
#define LCD_CNT_PORT    DIO_PORTD

/****************************/
/*    END OF FILE GUARD     */
/****************************/
#endif /* HAL_LCD_PRIV_H_ */
