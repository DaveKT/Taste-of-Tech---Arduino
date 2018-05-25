## Sound Graph

Demonstrates the use of the serial plotter to monitor sensor input.

### Behavior

This application takes input from the microphone and write the DB level to serial out. The results may be charted in real time using Arduino IDE's serial plotter.

### Code

~~~~
#include <Adafruit_CircuitPlayground.h>

int mic;
unsigned long startTime;
unsigned long now;
int knockCounter = 0;
boolean timerActive = false;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  mic = CircuitPlayground.mic.soundPressureLevel(10);
  Serial.print(0);
  Serial.print(",");
  Serial.print(mic);
  Serial.print(",");
  Serial.println(85); //85db is dangerous over prolonged periods
  delay(5);

}
~~~~

[Download the Sound Graph Code](SoundGraph.ino)

### Key Lesson

Talk about the serial plotter and talk about what is being shown on the graph and tie that back to the original program. As a fun exercise... have the students try to modify the program to turn the neopixels on when a certain DB level is reached. Could this be used to warn people of an environmental hazard? Where might such a device be used.
