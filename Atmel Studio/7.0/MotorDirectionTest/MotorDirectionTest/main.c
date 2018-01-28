/*
 * MotorDirectionTest.c
 *
 * Created: 16-Nov-17 3:38:25 PM
 * Author : Tamim
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0xff;
    /* Replace with your application code */
    while (1) 
    {
		PORTB=0b00000001;
		_delay_ms(180);
		PORTB=0b00000010;
		_delay_ms(180);
		PORTB=0b00000100;
		_delay_ms(200);
		
    }
}

