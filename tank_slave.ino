/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == SLAVE CODE ==
 */
 
int joyZ = 12; //key

#define joyX A0
#define joyY A1

int state = 20;
int buttonState = 0;

void setup() {
  pinMode(joyZ, INPUT);
  myServo.attach(9);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
// if(Serial.available() > 0){ // Checks whether data is comming from the serial port
//    state = Serial.read(); // Reads the data from the serial port
// }
// // Controlling the servo motor
// myServo.write(state);
// delay(10);
 
 //Reading the joystick  
 
  int xVal, yVal, zVal;
  xVal = analogRead(joyX);
  yVal = analogRead(joyY);
  zVal = digitalRead(joyZ);

  Serial.print(xVal ,DEC);
  Serial.print(",");
  Serial.print(yVal ,DEC);
  Serial.print(",");
  Serial.println(zVal ,DEC);
  delay(100);
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);

  if(xVal < 400)//left turn
  {
    //move_func(HIGH, LOW, LOW, HIGH);
    Serial.write('0');
  }
  else if (xVal > 600)//right turn
  {
    //move_func(LOW, HIGH, HIGH, LOW);
    Serial.write('1');
  } 
  else if (yVal < 400) //forward
  {
    //move_func(HIGH, LOW, HIGH, LOW) ;
    Serial.write('2');
  }
  else if (yVal > 600)//back
  {
    //move_func(LOW, HIGH, LOW, HIGH); 
    Serial.write('3');
  }
  else //no movement
  {
    //move_func(LOW, LOW, LOW, LOW);
    Serial.write('4');
  }
}
