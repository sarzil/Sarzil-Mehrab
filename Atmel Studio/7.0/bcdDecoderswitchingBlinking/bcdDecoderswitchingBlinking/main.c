/*
 * bcdDecoderswitchingBlinking.c
 *
 * Created: 10/24/2017 1:23:32 AM
 * Author : Tamim
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	int i=0;
	int seg_code[]={0,1,2,3,4,5,6,7,8,9};
		int dig_code=0b00000001;
    DDRB = 0xff;
	DDRC = 0xff;
    while (1) 
    {
		for(i=0;i<=9;i++)
		{
		
		PORTC=0x01;
		PORTB=seg_code[i];
		_delay_ms(80);
		PORTC=0x02;
		PORTB=seg_code[dig_code];
		_delay_ms(80);
		}
		
    }
}

