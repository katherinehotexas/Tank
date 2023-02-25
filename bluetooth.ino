#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 3;
SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  //pinMode(rxPin, INPUT);
  //pinMode(txPin, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.listen();
  if(mySerial.available() > 0){
    delay(10);
    Serial.write(mySerial.read());  
  }
  if(Serial.available() > 0) {
    mySerial.write(Serial.read());
  } 
    
}
