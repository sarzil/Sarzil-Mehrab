/*
 * LedBlinkPushBtton.c
 *
 * Created: 20-Nov-17 10:21:44 PM
 * Author : Tamim
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

int main(void)
{
	DDRB = 0xFF;		// set all port of port b as output //DDRB |= 0b00000001; //set only 0th pin of port c as output //DDRB = 0X01;		  // Set daatadirection protb 0 output //DDRB = 0X01;		  // Set daatadirection protb 0 output 
	DDRD = 0x00;		//Makes all pins of PORTD input
	
	PORTB = 0;
	
	
	while(1) //infinite loop

		{
			if((PIND & 0b00000001)==1) 
			{
				PORTB = 0x01;
				/*_delay_ms(500);			// delay 1/2 second*/
			}
			
			else if ((PIND & 0b00000001)==0)
			{
				PORTB = 0;
			}
									
		}
		
}





















// 	DDRB |= (1<<PORTB0); //Nakes first pin of PORTC as Output
// 		 DDRB |= (0<<PORTB0);
// 		 DDRB |=!(1<<PORTB1);
// 		//DDRB &= ~(1<<PORTB1);//Makes firs pin of PORTD as Input
// 		 //DDRB = 0x00; //Makes all pins of PORTD input