/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
float temp;
int tempPin=0;
void setup()
{
	Serial.begin(9600);
}

void loop()
{
	temp = analogRead(tempPin);
	temp= temp*4828828125;
	Serial.print("TEMPARATURE =");
	Serial.print(temp);
	Serial.print(" *C");
	Serial.println();
	delay(1000);
}