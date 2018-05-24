## Acceleromter Graph

Print out a real time grpah of accelerometer readings.

### Behavior

This program prints the current X, Y, and Z values from the Circuit Playground's Accelerometer. These values may be plotted in real time using the Arduino IDE's Serial Plotter.

### Code

~~~~
#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  Serial.print(X);
  Serial.print(",");
  Serial.print(Y);
  Serial.print(",");
  Serial.println(Z);

  delay(100);
}
~~~~

[Download the Accelerometer Graph Code](Accelerometer_Graph.ino)

### Key Lesson

Introduces the accelerometer function to students. Spend some time explaining the effect of gravity on the accelerometer and ask the question, why is one of the values registering 9.8 m/s^2^. Make sure to move the CP around when demonstrating so students can clearly see the effect.
