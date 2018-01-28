/*
 * sevenSegmentDublePort.c
 *
 * Created: 25-Oct-17 12:32:01 PM
 * Author : Tamim
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD=0xff;
	DDRB=0xff;
    while (1) 
    {
		char seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
			for (int j=0;j<10;j++)
			{
				for (int i=0;i<10;i++)
				{
					PORTB=0b00000010;
					PORTD=seg[i];
					_delay_ms(300);
					PORTB=0b00000001;
					PORTD=seg[j];
					_delay_ms(300);
				}
			
			}
    }
}

