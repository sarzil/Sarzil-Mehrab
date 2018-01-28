/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
void setup() {
	Serial.begin(9600);
	pinMode(A1,INPUT);
}

void loop() {
	// put your main code here, to run repeatedly:
	float temp=analogRead(A1);
	//float check=((temp*5.0)-5.0)*100;

	float mv = ( temp/1024.0)*5000;
	float cel = mv/10;
	//float farh = (cel*9)/5 + 32;
	Serial.print("Current temp: ");
	Serial.print(cel);
	Serial.println("*C");
	Serial.print("Current ADC: ");
	Serial.print(mv/1000);
	Serial.println("V");
	Serial.print(temp);
	delay(1500);
	

}