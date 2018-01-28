/*
 * doubleSevenSegmentParallelBlink.c
 *
 * Created: 25-Oct-17 1:41:38 PM
 * Author : Tamim
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
    DDRD = 0xff;
	DDRC = 0xFF;
	int i,j;
	char seg_code[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
    while (1) 
    {
		for (i=0;i<=9;i++)
		{
			PORTC=seg_code[i];
			
			//_delay_ms(50);
			for (j=0;j<=9;j++)
			{
				
				
				PORTD=seg_code[j];
				_delay_ms(80);
				
			}
			
			}
		}
		
    
}

