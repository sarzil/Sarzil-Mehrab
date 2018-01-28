/*
 * 7447icSevensegment.c
 *
 * Created: 26-Oct-17 2:04:59 PM
 * Author : Tamim
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	DDRC = 0b11111111;
	/* Replace with your application code */
	while (1)
	{
		char output[] = {0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000,0b1001};
		for(int i=0;i<=9;i++)
		{
			PORTC = output[i];
			_delay_ms(250);
		}
		
	}
}


