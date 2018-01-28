
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD =0xff;
	int i,j;
  
    while (1) 
    {
		
	for(i=0;i<=7;i++)
		{
			PORTD |=(1<<i);
			_delay_ms(50);
			
		}
		
// 	for(j=0;j<=7;j++)
// 	{
// 		PORTD &= ~(1<<PD7-j);
// 		
// 	}
		}
		
    }


