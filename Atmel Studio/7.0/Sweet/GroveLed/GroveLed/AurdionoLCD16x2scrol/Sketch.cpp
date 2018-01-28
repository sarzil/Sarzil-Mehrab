#include <Arduino.h>

const int button = 2;       // the Grove port No. you attached a button to
const int LED    = 3;       // the Grove port No. you attached an LED to
void setup()
{
	pinMode(button, INPUT); //set button as an INPUT device
	pinMode(LED, OUTPUT);   //set LED as an OUTPUT device
}
void loop()
{
	int btn = digitalRead(button); //read the status of the button
	digitalWrite(LED,btn);
	delay(100);
}