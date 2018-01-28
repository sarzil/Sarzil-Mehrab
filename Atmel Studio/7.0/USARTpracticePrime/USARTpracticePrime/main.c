/*
 * USARTpracticePrime.c
 *
 * Created: 30-Nov-17 4:38:58 PM
 * Author : Tamim
 */ 

#include <avr/io.h>
#define  BAUDRATE 19200 //bitrate 
#define F_CPU 16000000UL //hz
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1) 
 
 void USART_Init()
 {
	 UBRR0H=(uint8_t)(1<<BAUD_PRESCALLER);
	 UBRR0L=(uint8_t)(BAUD_PRESCALLER);
	 UCSR0B|=(1<<RXEN0)|(TXEN0);
	 UCSR0C=(1<<UCSZ01)|(1<<UCSZ00); 
	 UCSR0A = (1<<UDRE0);
 }
void USART_send(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	{
		UDR0 =data; 
	}
	
}


 USART_receive()

{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void USART_putstring(char* StringPtr){
	
	while(*StringPtr != 0x00){
		USART_send(*StringPtr);
	StringPtr++;}
	
}
int main(void)
{
	
char		String[] ="kjdksjdksjksdjsdjs";
		while(1)
		{USART_putstring(String);
		_delay_ms(50);
		}
		return 0;
    }
	


