int analogInPin = A0;
int sensorValue = 0; 
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  
  if(Serial.read())
  {
    sensorValue = analogRead(analogInPin);
  }
  
}
