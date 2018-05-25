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
