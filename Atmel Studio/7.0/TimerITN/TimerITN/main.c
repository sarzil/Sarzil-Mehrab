/*
 * TimerITN.c
 *
 * Created: 29-Oct-17 2:47:26 PM
 * Author : Tamim
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

volatile uint8_t timeVeriable=0;
ISR(TIMER0_OVF_vect)

{
	timeVeriable++;
	if (timeVeriable>=125)
	{
		timeVeriable=0;
		PORTB ^= (1<<PORTB5);
	}
}

int main(void)
{
    DDRB=0x20;
	TCCR0B |= (1<<CS00) |(1<<CS01);
	TIFR0 = 1<<TOV0;
	TIMSK0 = 1<<TOIE0;
	sei();
	
    while (1) 
    {
    }
}

