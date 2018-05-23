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
  mic = CircuitPlayground.soundSensor();
  Serial.print(200);
  Serial.print(",");
  Serial.print(mic);
  Serial.print(",");
  Serial.println(500);
  delay(10);

}
