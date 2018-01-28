/*
 * AllProject.c
 *
 * Created: 21-Nov-17 3:15:15 PM
 * Author : Tamim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define BUAD 19200
#define BUAD_RATE_CALC  (((F_CPU / (BUAD * 16UL))) - 1)

void USART_init(void){
	
	UBRR0H = (uint8_t)(BUAD_RATE_CALC>>8);
	UBRR0L = (uint8_t)(BUAD_RATE_CALC);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
}
unsigned char USART_receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));
		return UDR0;
}
void USART_send( unsigned char data){	
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}
void USART_putstring(char* StringPtr){	
	while(*StringPtr != 0x00){
		USART_send(*StringPtr);
	StringPtr++;}
}


int main(void)
{
	USART_init();
	//unsigned int adc_value; 
 	DDRB=0xff; 
 	PORTB = 0x00;
 	DDRD|=(1<<PORTD0)|(1<<PORTD1);
	ADMUX |= (1<<REFS0)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0); 
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
	while (1)
	{
		char str[4];	
		ADCSRA |= (1<<ADSC);  
		while (ADCSRA & (1<<ADSC)); 
		unsigned int adc_value = ADCW;
		float temp= (adc_value*0.49);
		utoa(temp,str,10);
		
		//char string[]="adc_value: ";
		USART_putstring("Temperature is: ");  
		USART_putstring(str); 
		USART_putstring("*C");
		USART_putstring("\r");
		PORTB=0b00000100; 
		if (temp < 26)
		{
			PORTB=0x01;
		
		}
		else if ( temp>=24 && temp <30 )
		{
			PORTB = 0b00000010;
		}
		else if ( temp >=30 )
		{
			PORTB = 0b00000100;
		}
		
		_delay_ms(100);
	}
	return 0;
}




