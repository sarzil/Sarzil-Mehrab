int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}
char arr[10];
int i=0;
bool flag=false;
void loop() {
  
        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                if(incomingByte !='/')
                {
                    arr[i]=(char) incomingByte;
                    i++;
                }else{
                  i=0;
                  flag=true;
                }

                if(flag==true){
                  int num =atoi(arr);
                  Serial.println(num, HEX);
                  flag=false;
                }
                // say what you got:
                //Serial.print("\nI received: ");
                //Serial.println(incomingByte, BIN);
                //Serial.println(incomingByte, OCT);
                //Serial.println(incomingByte, HEX);
                
        }
}
 
