/*
 * GccApplication2.c
 *
 * Created: 25-Oct-17 8:53:16 PM
 * Author : Tamim
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
    //DDRD=0x01;
	DDRD |= (1<<0);
    while (1) 
    {
		PORTD |= (1<<0);
		_delay_ms(50);
		PORTD &= (0<<0);
		_delay_ms(10);
// 		PORTD=0x01;
// 		_delay_ms(10);
// 		PORTD=0x00;
// 		_delay_ms(10);
    }
}


