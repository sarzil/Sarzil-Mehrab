/*
 * LED ON-OFF usig single switch.c
 *
 * Created: 21-Nov-17 4:30:45 AM
 * Author : Sweet
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


int main(void)
{
	DDRB = 0b11111111;		// set all port of port b as output //DDRB |= 0b00000001; //set only 0th pin of port c as output //DDRB = 0X01;		  // Set daatadirection protb 0 output //DDRB = 0X01;		  // Set daatadirection protb 0 output 
	DDRD = 0b00000000;		//Makes all pins of PORTD input
	
	PORTB = 0;
	PORTD = 0;
	
	while(1) //infinite loop

		{
			if((PIND & 0b00000001)==1) 
			{
				PORTB = 0b11111111;
				/*_delay_ms(500);			// delay 1/2 second*/
			}
					
											
		}
		
}

