/*
 * MotorRunAndOffWithProximity.c
 *
 * Created: 19-Nov-17 12:10:33 PM
 * Author : Tamim
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0b00111000;
	/* Replace with your application code */
	while (1)
	{
		PINB |= (0<<PINB0);
	
		if (PINB==1)
		{
			PORTB=(1<<PORTB6);
		}
		else
		{
			PORTB=(0<<PORTB6);
		}
		
		
	}
}

