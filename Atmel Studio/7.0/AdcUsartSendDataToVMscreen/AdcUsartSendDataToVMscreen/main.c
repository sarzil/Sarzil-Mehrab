/*
 * AdcUsartSendDataToVMscreen.c
 *
 * Created: 15-Nov-17 11:10:40 PM
 * Author : Tamim
 */ 



#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define BAUDRATE 19200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 8UL))) - 1)

//Declaration of our functions
void USART_init(void)
    {
		UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
		UBRR0L = (uint8_t)(BAUD_PRESCALLER);
		UCSR0B = (1<<RXEN0)|(1<<TXEN0);
		UCSR0C = (3<<UCSZ00);
    }
unsigned char USART_receive(void)
    {
		while(!(UCSR0A & (1<<RXC0)));
		return UDR0;
    }
void USART_send( unsigned char data)
    {
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = data;
    }
void USART_putstring(char* StringPtr)
    {
		while(*StringPtr != 0x00){
			USART_send(*StringPtr);
		StringPtr++;}
	}
	
int main(void)
{
	USART_init();
	// USART_send( unsigned char data);
	uint16_t adc_value;
	DDRB =0xff;
	ADMUX=(1<<REFS0)|(0<<MUX0)|(0<<MUX1)|(0<<MUX2)|(0<<MUX3);  // ref is enabled and ADC0 is selected for Mux 0000
	ADCSRA=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2)|(1<<ADSC);

	while (1)
	{	
		ADCSRA|=(1<<ADSC); //start conversion
		while(ADCSRA &(1<<ADSC))
		adc_value=ADC;
		//uint16_t x=adc_value;
		char xx[4];
		utoa(adc_value,xx,10);
		USART_putstring("Value: ");
		USART_putstring(xx);
				
		
			
		if (adc_value<=300)
		
		{
			PORTB=0b00000001;
			USART_putstring("LOW");
			_delay_ms(500);
 			
		}
		else if((adc_value>300)&&(adc_value<=500))
		{
			PORTB=0b00000010;
			USART_putstring("MID");
			_delay_ms(500);
						
		}
		else
		{
			PORTB=0b00000100;
			USART_putstring("HIGH");
			_delay_ms(500);
			
		}
		
		USART_send('\r');
		
		
	}
}

