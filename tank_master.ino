/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == MASTER CODE ==
 */

int en1 = 9;
int in1 = 8;
int in2 = 7;

int en2 = 3;
int in3 = 5;
int in4 = 4;

int state = 0;
int potValue = 0;

void setup() {
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
  
  digitalWrite(ledPin, LOW);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
  // Controlling the LED

  if(state == '0')//left turn
  {
    move_func(HIGH, LOW, LOW, HIGH);
  }
  else if (state == '1')//right turn
  {
    move_func(LOW, HIGH, HIGH, LOW);
  } 
  else if (state == '2') //forward
  {
    move_func(HIGH, LOW, HIGH, LOW);
  }
  else if (state == '3')//back
  {
    move_func(LOW, HIGH, LOW, HIGH); 
  }
  else //no movement
  {
    move_func(LOW, LOW, LOW, LOW);
  }
 
}

void move_func(int a, int b, int c, int d){
  digitalWrite(in1, a);
  digitalWrite(in2, b);
  digitalWrite(in3, c);
  digitalWrite(in4, d);
}
