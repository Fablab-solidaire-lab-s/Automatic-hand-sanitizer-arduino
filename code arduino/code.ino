/*
Descriptionn : this code is used to control a servomotor when the proximity 
	       sensor detects the hand 

VERSION       : 1.0
DATE CREATION : 22/03/2020
LICENCE       : AGPL v3
AUTHOR        : Mamadou DIALLO
EMAIL         : diallo@bloctechno.com

ABOUT         : in this tutorial a parallax continuous rotation actuator is used,
		they have a small potentiometer next to the connector output, 
		this potentiometer allows to fix the rotation of the actuator in the middle.
		So when you upload the code; without touching the sensor, if you see that the servo motor continues to rotate,
		take a screwdriver, turn the potentiometer until it stops.

*/

//include librairie 
#include <Servo.h>

//define pin for proximity sensor
#define sensor 2

//create servo instance 
Servo servo;


// setup code
void setup() {
  // enable serial communication 
  Serial.begin(9600);

  // setup pin for proximity sensor, here we use it on INPUT
  pinMode(sensor,INPUT);

  //setup servomotor pin 
  servo.attach(3);
}

// loop code
void loop() {
  // create variable and store value from proximity sensor
  int value = digitalRead(sensor);

  //for stop rotate of servomotor
  servo.write(90);

  //condition if the sensor detects the hand, the value of the variable is 0 LOW,
  // and the servo motor is commanded to rotate for 5s to lower the piston and after mount the piston during 4s  
  if (value == LOW )
  {
    servo.write(0); // lower piston
    delay(5000);
    servo.write(180); // mount piston
    delay(4000);
  }
}
