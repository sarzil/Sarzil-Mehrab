/*
 * bcdDecoder.c
 *
 * Created: 10/23/2017 11:13:33 PM
 * Author : Tamim
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{int i,count=0;
	DDRD =0xff;
	DDRA=0xff;
	char digit[]={0,1,2,3,4,5,6,7,8,9};
    while (1) 
    {
		for(i=0;i<=9;i++)
		{
		PORTD=digit[i];	
		_delay_ms(50);	
		}
	count++;
		
			PORTA=digit[count];
		
		
		}
		
    }


