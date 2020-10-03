
#include  "ultrasonic.h"
/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : Smart Home APP   		        */
/*   DATE        : 29 FEB 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/***************************************************/
/*              Library Directives                 */
/***************************************************/
#include "..\LIB\STD_TYPES.h"
#include "..\LIB\BIT_MATH.h"
#include "../LIB/Registers.h"
//#include <avr/io.h>
/***************************************************/
/*                 DIO Directives                  */
/***************************************************/
#include "../MCAL/DIO/DIO_INT.h"

/***************************************************/
/*           		ADC Directives                 */
/***************************************************/

#include "../MCAL/ADC/ADC_INT.h"
#include "../MCAL/ADC/ADC_PRIV.h"
//#include "../MCAL/ADC/ADC_CONF.h"

#include "../MCAL/UART/UART_INT.h"
#include "../MCAL/UART/UART_CONF.h"

/***************************************************/
/*           EXT Interrupt Directives              */
/***************************************************/
#include "../MCAL/Interrupt/ExtInterrupt_INT.h"
#include "../MCAL/Interrupt/ExtInterrupt_PRIV.h"

/***************************************************/
/*           	  Timer0 Directives                */
/***************************************************/
#include "../MCAL/TIMER0/TIMER_INT.h"

/***************************************************/
/*           	   LCD Directives                  */
/***************************************************/
#include "../HAL/LCD/LCD_INT.h"
#include "../HAL/LCD/LCD_PRIV.h"
#include "timer/timer.h"

f32 adc_value1 = 0;
f32 adc_value2 = 0;
f32 adc_volt1 = 0;
f32 adc_volt2 = 0;
f32 mili_volt = 0;
f32 t1 = 0;
f32 t2 = 0;
f32 temp = 0;

u32 counter=0;

uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance;
uint8_t distance_str[10];


void main(void){
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_OUTPUT);
	EXT_voidEnable(EXTINT0);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	LCD_4bitIntialization ();
    ultrasonic_init();
    sei();
    ADC_voidInitTEMP();
    _delay_ms(10);
	while(1){
		adc_value1=ADC_u16GetRawData(ADCCH0);
		adc_value2=ADC_u16GetRawData(ADCCH1);
		adc_volt1 = ((adc_value1*500)/1023.0); // for all volt measurement. R1= 56K, R2=5K;
		adc_volt2 = ((adc_value2*500)/1023.0); // for all volt measurement. R1= 56K, R2=5K;
		temp = (adc_volt1 - adc_volt2);
		LCD_voidSend_4bitCommand (0x01);
		LCD_void4bitGoToPos(1,1);
	    LCD_voidSend_4bitString ("temp : ");
	    LCD_void4bitDisplayNumber(temp);
	    LCD_void4bitGoToPos(2,8);
	    itoa(counter,distance_str,10);
	    strcat(distance_str, " car ");
	    LCD_voidSend_4bitString(distance_str);
	    LCD_void4bitDisplayNumber(counter);
	    _delay_ms(15);
	    ultra_triger();

	  if (distance < 250 && distance > 0 && temp > 85 && counter < 99)
	  {
		  counter++;
		  LCD_void4bitGoToPos(2,8);
		  itoa(counter,distance_str,10);
		  strcat(distance_str, " car ");
		  LCD_voidSend_4bitString(distance_str);
		  LCD_void4bitDisplayNumber(counter);
		  DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		  _delay_ms(500);
		  DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
		  _delay_ms(1500);
		  DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		  _delay_ms(500);
		  DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);


	  }
	  else
	  {
	//	  DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
	//	  DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
	  }
}

}


void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  timer0_init();
  return;
}

void handler(void)
{
 if (counter >0)
 {
	 LCD_void4bitGoToPos(2,8);
	 counter--;
     LCD_void4bitDisplayNumber(counter);
	 DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	 _delay_ms(500);
	 DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
	 _delay_ms(1500);
	 DIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_HIGH);
	 _delay_ms(500);
	 DIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
 }
}


void ultra_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

void enable_ex_interrupt(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}


ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT0)/150;
    LCD_void4bitGoToPos(2,1);
  	itoa(distance,distance_str,10);
  	strcat(distance_str, " cm-");
  	LCD_voidSend_4bitString(distance_str);
  	_delay_ms(40);
    timer_counter=0;
    rising_edge=0;
  }
}}

ISR(TIMER0_OVF_vect){
    timer_counter++;
    if(timer_counter >730){
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}

