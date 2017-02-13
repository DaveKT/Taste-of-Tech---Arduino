/*  Author:   David Tassara
 *  Purpose:  Demonstrate the raw values from the circuit playground accelerometer.
 *  Date:     10 Feb 2017
 *  Version:  1.0
 *  Note:     With the CP connected to USB run the serial plotter in Arduino IDE
 *  to graph the three axis of acceleration.
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
