/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : KB DRIVER                        */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_KEYPAD_KDB_PRIV_H_
#define HAL_KEYPAD_KDB_PRIV_H_


/********************** 			 Macros            *********************/
/* ROWS AND COLUMNS NUMBER */
#define KBD_ROW_NUM    4
#define KBD_COL_NUM    3

/* Hardware port that keyDIO_PINd is attached to */
#define KBD_PORT_HW   DIO_PORTD

/* Rows and Columns PINS  */
#define KBD_ROW_0     DIO_PIN0
#define KBD_ROW_1     DIO_PIN1
#define KBD_ROW_2     DIO_PIN2
#define KBD_ROW_3     DIO_PIN3

#define KBD_COL_0     DIO_PIN4
#define KBD_COL_1     DIO_PIN5
#define KBD_COL_2     DIO_PIN6
//#define KBD_COL_3     DIO_PIN7

/* Registers for the keyDIO_PINd */
#define KBD_PORT      PORTD_REG
#define KBD_DIR       DDRD_REG
#define KBD_PIN       PIND_REG

/* Pressed and released values */
#define KBD_KEY_PRESSED   0
#define KBD_KEY_RELEASED  1

/*********************************************************************************************************************************/


#endif /* HAL_KEYPAD_KDB_PRIV_H_ */
