/*
Purpose: Circuit Playground Sensor Lesson
Author: David Tassara
Date: 3 February 2017
*/

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

//Step 1. Update the pin to 11 and change your circuit
int speakerPin = 5;
uint16_t lightValue; 

void setup()
{
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop()
{
  int lightValue = CircuitPlayground.lightSensor();
  
//Step 2: Load program and check the light reading using Serial Monitor (call Dave)
//  Serial.println(lightValue);
  
//Step 3: Uncomment the code below and run. What happens?  
  if (lightValue > 100) {
    CircuitPlayground.playTone(lightValue, 50, false);
  }
  else {
    //CircuitPlayground.playTone(lightValue, 100);
  }
  
}
