/*
 * LedBlinkingSwitchMode.c
 *
 * Created: 20-Nov-17 9:19:48 PM
 * Author : Tamim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0b00000010;
	
	while(1) {
	
 		if(!(PINB & (1<<PINB0) )) 
 		{
 			PORTB =0b00000010; 
		
 		}
 		else 
		 {
 			PORTB =0b00000000;
		 }
		}

}

