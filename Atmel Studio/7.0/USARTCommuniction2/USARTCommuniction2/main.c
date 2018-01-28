/*
 * USARTCommuniction2.c
 *
 * Created: 16-Nov-17 1:23:13 AM
 * Author : Tamim
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BAUDRATE 19200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 8UL))) - 1)

//Declaration of our functions
/*void USART_init(void);*/
void USART_init(void){
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}

unsigned char USART_receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
	
}

void USART_send( unsigned char data){
	
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	
}



char String[]=" Noyakhali Bivag Chay!!";    //String[] is in fact an array but when we put the text between the " " symbols the compiler threats it as a String and automatically puts the null termination character in the end of the text

int main(void){
	USART_init();        //Call the USART initialization code
	
	while(1){        //Infinite loop
		USART_putstring(String);    //Pass the string to the USART_putstring function and sends it over the serial
		_delay_ms(500);        //Delay for 5 seconds so it will re-send the string every 5 seconds
	
	}
	return 0;
}








