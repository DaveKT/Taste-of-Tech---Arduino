#include <Adafruit_CircuitPlayground.h>

bool current;

void setup() {

  Serial.begin(9600);
  CircuitPlayground.begin();
  current = CircuitPlayground.slideSwitch();

}

void loop() {

  if(!current == CircuitPlayground.slideSwitch()) {
    if(CircuitPlayground.slideSwitch()) {
      Serial.println("Switch is on the left.");
    } else {Serial.println("Switch is on the right.");}
  }

  current = CircuitPlayground.slideSwitch();
  delay(100);

}
