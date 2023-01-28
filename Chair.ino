#include <Servo.h>
int RGB_RED_PIN = 4;
int RGB_GREEN_PIN = 2;
int RGB_BLUE_PIN = 3;
Servo myservo;  // create servo object to control a servo
Servo myservo2;
int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;
int incline;    // variable to read the value from the analog pin
int rotate;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
}

void loop() {
  incline = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  incline = map(incline, 0, 1023, 0, 60);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(incline);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  int rgb;
  rgb = analogRead(potpin);
  int rgbValue = map(rgb, 0, 1023, 0, 1535);
  
  rotate = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  rotate = map(rotate, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo2.write(rotate);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  
  int red;
  int blue;
  int green;
  
  if (rgbValue < 256) {
    red = 255;
    
    green = 0;
  }
  
  else if (rgbValue < 1024) {
    red = 0;
    
    green = 255;
  }
  else if (rgbValue < 1280) {
    red = rgbValue - 1024;
    blue = 0;
    green = 255;
  }
  else {
    red = 255;
    blue = 0;
    green = 1535 - rgbValue;
  }
  
  analogWrite(RGB_RED_PIN, red);
  analogWrite(RGB_BLUE_PIN, blue);
  analogWrite(RGB_GREEN_PIN, green);
}

