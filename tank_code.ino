#include <SoftwareSerial.h>

int txPin = 3;
int rxPin = 2;

SoftwareSerial guy = SoftwareSerial(rxPin, txPin);


int joyZ = 12; //key

#define joyX A0
#define joyY A1

void setup() {
  pinMode(joyZ, INPUT);
  Serial.begin(9600);
  guy.begin(9600);
}

void loop() {
  int xVal, yVal, zVal;
  // put your main code here, to run repeatedly:
  xVal = analogRead(joyX);
  yVal = analogRead(joyY);
  zVal = digitalRead(joyZ);

  guy.println(xVal, DEC);
  guy.println(yVal, DEC);
  guy.println(zVal, DEC);
  Serial.println(xVal, DEC);
  Serial.println(yVal, DEC);
  Serial.println(zVal, DEC);
  delay(100);

}
