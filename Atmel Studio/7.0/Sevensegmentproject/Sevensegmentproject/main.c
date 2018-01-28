
# define F_CPU 8000000UL // clock speed is 8MHz
#include <avr/io.h>
#include <util/delay.h>

int main(void)

{
	DDRD =0xff;
	int a,b,c;
   char seg_code[]={0x3f,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
	   
					
    while (1) 
    {
		for(a=0;a<=9;a++)
		{
			PORTD=seg_code[a];
			_delay_ms(100);
		}
		
		 }
}

