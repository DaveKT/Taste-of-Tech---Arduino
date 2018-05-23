/*
 * Circuit Playground How Tall Is It 
 * Uses the accelerometer to turn the Circuit Playground into an inclinometer.
 * Can be used to determine the height of objects using a little right angle
 * math.
 * 
 * Author: Carter Nelson
 * MIT License (https://opensource.org/licenses/MIT)
 * Taken from Adafruit's Learning Site on 14 Feb 2017
 * Site: https://learn.adafruit.com/how-tall-is-it/software?view=all#overview
 * Also see attachement, How_Tall_Is_It_Worksheet.pdf
 */

 
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
 
float X, Y, Z;
float angle;
float totalAccel;
bool goodReading;
uint8_t angleDisplay;
 
///////////////////////////////////////////////////////////////////////////////
void setup()
{
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
 
  // Set the accelerometer range.
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_2_G);
 
  // Indicate ready using NeoPixel 9.
  // Set it red to indicate no good reading yet.
  CircuitPlayground.setPixelColor(9, 255, 0, 0);
}
 
///////////////////////////////////////////////////////////////////////////////
void loop()
{
  // Only take action when either button is pressed.
  if ( (CircuitPlayground.leftButton()  == true) || 
       (CircuitPlayground.rightButton() == true) ) {
    
    // Average several readings.
    X = 0.0;
    Y = 0.0;
    Z = 0.0;
    for (int i=0; i<10; i=i+1) {
      X = X + CircuitPlayground.motionX();
      Y = Y + CircuitPlayground.motionY();
      Z = Z + CircuitPlayground.motionZ();
      delay(10);
    }
    X = X / 10.0;
    Y = Y / 10.0;
    Z = Z / 10.0;
    
    // Compute angle.
    angle = atan2(Y, X);
 
    // Compute total acceleration
    totalAccel = sqrt(X*X + Y*Y + Z*Z);
 
    // Initially assume the reading is good.
    goodReading = true;
 
    // Check for levelness.
    // Ideally Z=0, but allow a small amount of Z.
    if (abs(Z) > 1.0) {
      goodReading = false;
    }
 
    // Check for motion.
    // Gravity (9.8 m/s^2) should be the only acceleration, but allow a small amount of motion.
    if (totalAccel > 10.0) {
      goodReading = false;
    } 
    
    // Indicate if reading was good.
    if (goodReading == true) {
      // Green light.
      CircuitPlayground.setPixelColor(9, 0, 255, 0);
    } else {
      // Red light.
      CircuitPlayground.setPixelColor(9, 255, 0, 0);
    }
    
    // Indicate sign of angle.
    if (angle < 0) {
      // Blue light.
      CircuitPlayground.setPixelColor(8, 0, 0, 255);
    } else {
      // Off.
      CircuitPlayground.setPixelColor(8, 0, 0, 0);
    }
    
    // Display angle magnitude, in degrees, on NeoPixels 0-7 as 8 bit value.
    // 1 = NeoPixel ON, 0 = NeoPixel OFF
    // First, convert the angle to degrees and make integer. 
    angleDisplay = uint8_t(abs(angle * 57.29578));
    // Now display one bit at a time
    for (int p=0; p<8; p=p+1) {
      // Is the least signficant bit a 1?
      if (angleDisplay & 0x01 == 1) {
        // Turn on the NeoPixel
        CircuitPlayground.setPixelColor(p, 255, 255, 255);
      } else {
        // Turn off the NeoPixel
        CircuitPlayground.setPixelColor(p, 0, 0, 0);
      }
      // Shift the value down to the next bit.
      angleDisplay = angleDisplay >> 1;
    }
    
  }
}
