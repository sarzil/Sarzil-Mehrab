
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRD = 0xff;
	int p,q;
	     while (1) 
    {
 		
			for( p=0;p<=7;p++)
			{
				PORTD |= (1 << p);
				_delay_ms(50);
				PORTD &=~ (1<<p);
				}
								
			for ( q=p; q>=0; q--)
			{
				PORTD |= (1<<q);
				_delay_ms(50);
				PORTD &=~ (1<<q);
			}
							
    }
	
}

