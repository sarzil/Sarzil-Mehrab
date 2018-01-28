/*
 * UsartHomeWork.c
 *
 * Created: 13-Nov-17 10:27:47 PM
 * Author : Tamim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUDRATE 115200
#define BAUDRATE_PRESCALLER (((F_CPU)/(BAUDRATE*16UL))-1)
void USART_init (void)
{
	UBRR0H = (BAUDRATE>>8);
	UBRR0L = BAUDRATE;
	UCSR0B |= (1<<TXEN0)|(1<<RXEN0);
	UCSR0C |= (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
}