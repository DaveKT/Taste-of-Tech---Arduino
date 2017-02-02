/*
Purpose: Arduino Sensor Lesson
Author: David Tassara
Date: 21 November 2013
*/

//Step 1. Update the pin to 11 and change your circuit
int speakerPin = 12;
int photocellPin = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(photocellPin);
  
//Step 2: Load program and check the light reading using Serial Monitor (call Dave)
  Serial.println(reading);
  
//Step 3: Uncomment the code below and run. What happens?  
//  if (reading < 100) {
//    tone(speakerPin, 400);
//  }
//  else {
//    noTone(speakerPin);
//  }
  
}
