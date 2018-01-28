/*
 * UsartDataSend1to100.c
 *
 * Created: 12-Nov-17 11:41:00 AM
 * Author : Tamim
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BAUD 19200
#define MYUBRR    F_CPU/16/BAUD-1

void init_uart(unsigned short uValue  ){
	// setting the baud rate
	UBRR0H =(unsigned char)  ( uValue>> 8);  // 0x00
	UBRR0L =(unsigned char) uValue;  // 0x0C
	// enabling TX & RX
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0A = (1<<UDRE0);
	UCSR0C =  (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stop

}

// void USART_send (unsigned char data)
// {
// while (!(UCSR0A & (1<<UDRE0)))
// {
// UDR0 = data;
// }
// }
//
// unsigned char USART_recieve(void)
// {
// while (!(UCSR0A & (1<<RXC0)));
// return UDR0;
// }


int main ()
{




	init_uart(MYUBRR);

	DDRD |= (1<< PD7);
	for(;;){

		for (int i=100; i>=0; i--)
		{
			char buffer [20];
			itoa (i,buffer,10);

			for (int j=0; j<20;j++)
			{
				//printf(buffer);
				PORTD ^= (1<< PD7);
				UDR0 = buffer[j];
				_delay_ms(5);
			}

			// PORTD ^= (1<< PD7);
			// UDR0 = note;
			// //_delay_ms(500);
		}
	}


	return 0;
}