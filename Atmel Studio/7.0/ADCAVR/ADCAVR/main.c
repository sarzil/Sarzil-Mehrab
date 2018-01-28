/*
 * ADCAVR.c
 *
 * Created: 13-Nov-17 2:21:36 PM
 * Author : Tamim
 */ 


#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


#define BUAD 19200
//#define BUAD_RATE_CALC ((F_CPU/(16*BUAD)) - 1)




#include <avr/io.h>

int main(void)
{
	unsigned int adc_value; // Variable to hold ADC result
	DDRB=0xff; // Set Port D as Output
	PORTB = 0x00;
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	// ADEN: Set to turn on ADC , by default it is turned off
	//ADPS2: ADPS2 and ADPS0 set to make division factor 32
	ADMUX=(1<<REFS0); // ADC input channel set to PC5
	while (1)
	{
		ADCSRA |= (1<<ADSC); // Start conversion
		while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
		adc_value = ADCW; //Store ADC value
		if (adc_value < 512)
		{
			PORTB=0b00010000; // Toggle LEDs
			
		}
		else 
		{
			PORTB=0b00100000;

		}
	}
}










*************************************************************************************
#define F_CPU 16000000UL  // 16 MHz
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define USART_BAUDRATE 19200
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void USART_Init(void)
{
// Set baud rate
UBRR0L = BAUD_PRESCALE;//lower 8-bits into the the UBRRL register
UBRR0H = (BAUD_PRESCALE >> 8); //upper 8-bits into the UBRRH register
UCSR0B = ((1<<TXEN0)|(1<<RXEN0) | (1<<RXCIE0));//enable tx and Rx. Receive interrupt

/* Default frame format is 8 data bits, no parity, 1 stop bit to change use UCSRC, see AVR datasheet*/
}
int main(void)
{
DDRD|=(1<<PORTD0)|(1<<PORTD1);
ADMUX |= (1<<REFS0);
  ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
   while (1) 
   {
ADMUX |=(0<<MUX0)|(0<<MUX0)|(0<<MUX0)|(0<<MUX0);//Activating ADC0
ADCSRA |= (1<<ADSC); //start conversion
int adc_val=ADCW;
if(adc_val>20)
{
DDRD|=(1<<PORTD2)|(1<<PORTD3);

}
else
{
DDRD=1<<PORTD4;
}
}

   }
