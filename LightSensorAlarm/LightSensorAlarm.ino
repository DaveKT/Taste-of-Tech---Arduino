// Circuit Playground Dear Diary Alarm
// 
// Don't let sister/brother read your secrets! Place the "armed" Circuit
// Playground under your diary. If someone tries to remove the diary, an alarm
// will sound.
//
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)
 
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
 
uint16_t lightValue;           // current light sensor reading
uint16_t coveredValue;         // the light sensor value with diary on top
uint16_t alarmThreshold = 20;  // adjust to change alarm sensitivty
bool triggered = false;        // becomes true when diary removed
 
///////////////////////////////////////////////////////////////////////////////
void setup()
{
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
  
  // Turn on all the NeoPixels.
  for (int p=0; p<10; p=p+1) {
    CircuitPlayground.setPixelColor(p, 255, 0, 0);
  }
  
  // Wait for button press.
  while ( (CircuitPlayground.leftButton()  == false) && 
          (CircuitPlayground.rightButton() == false) ) {
            // Do nothing.
  }
  
  // Countdown timer.
  for (int p=0; p<10; p=p+1) {
    CircuitPlayground.setPixelColor(p, 0, 0, 0);
    delay(500);
  }
  
  // Compute covered light sensor value as average of 5 readings.
  coveredValue = 0;
  for (int i=0; i<5; i=i+1) {
    lightValue = CircuitPlayground.lightSensor();
    coveredValue = coveredValue + lightValue;
  }
  coveredValue = coveredValue / 5;
  
  // Beep to indicate ARMED.
  CircuitPlayground.playTone(1000, 1000);
  delay(1000);
}
 
///////////////////////////////////////////////////////////////////////////////
void loop()
{
  // Check to see if alarm has been triggered.
  if (triggered) {
    // Sound the alarm.
    CircuitPlayground.playTone(2000, 500);
    delay(500);
    CircuitPlayground.playTone(3000, 500);
    delay(500);
  } else {
    // Get current light sensor value.
    lightValue = CircuitPlayground.lightSensor();
 
    // Check light sensor value to determine if alarm should be triggered.
    if (lightValue > coveredValue + alarmThreshold) {
      triggered = true;  // Trigger the alarm.
    }
  }
}
