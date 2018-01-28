int pushButton = 13;
int LED = 3;

void setup() {
Serial.begin(9600);
pinMode(pushButton,INPUT_PULLUP);
pinMode(LED,OUTPUT);
}

void loop() {
    char a =99;
if (!digitalRead(pushButton))
    {
    Serial.write(a);
    }
    delay(500);
  
  byte b1 = Serial.read();
  byte b2 = Serial.read();
  int LDR = (b1*256)+b2;
  if(LDR>500)
    { 
      digitalWrite(LED,HIGH);
    }
    else
    {
     digitalWrite(LED,LOW); 
     }
}
