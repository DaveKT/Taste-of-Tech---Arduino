/*  Author:   David Tassara
 *  Purpose:  Demonstrate the raw values from the circuit playground accelerometer.
 *  Date:     10 Feb 2017
 *  Version:  1.0
 */

#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ()-10;

  Serial.print(X);
  Serial.print(",");
  Serial.print(Y);
  Serial.print(",");
  Serial.println(Z);

  delay(100);
}
