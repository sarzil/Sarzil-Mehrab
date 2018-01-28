

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL 

int main(void)
{
	
    DDRD =0xff;
	DDRB=0x00000011;
	char portBinput[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
		int i,j;
	
	
    while (1) 
    {
		for (i=0;i<=9;i++)
		{
			PORTD=portBinput[i];
			PORTB=0b0001;
			_delay_ms(30);
			
			PORTB=0b0010;
			_delay_ms(80);
		}
				
		
		
		
    }
}

