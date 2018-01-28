#include <Arduino.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1,8,9,10,11);
const int Upper = 5;
const int Lower = 7;
const int sensorPin = A0;
const int LED =13;
int buttonState = 0;
int count=10;
int sensorValue=0;
void setup() {
	pinMode(Upper, INPUT);
	pinMode(Lower, INPUT);
	pinMode(LED, OUTPUT);
	lcd.begin(16, 2);
	lcd.print("Temperature:");
}
void loop() {
	sensorValue = analogRead(sensorPin);
	if(digitalRead(Upper)==1)
	{
		count++;		
	}
	if(digitalRead(Lower)==1)
	{
		count--;
	}
	if(sensorValue>=count)
	{
		digitalWrite(LED, HIGH);
	}
	else{
		digitalWrite(LED, LOW);
	}
	lcd.setCursor(0, 1);
	// print the number of seconds since reset:
	// lcd.print(millis() / 1000);
	lcd.print(count);
	lcd.setCursor(4, 1);
	lcd.print(sensorValue);
	delay(250);	
}