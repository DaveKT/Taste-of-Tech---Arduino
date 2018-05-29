## Knock Knock Knock

This application demonstrates the using the microphone sensor on Circuit Playground Express. You can use Arduino's serial plotter to help the student visualize the knocking. This is a good jumping off point for thresholds.

### Behavior

The software uses the microphone to sample the microphone. If a peak greater than 200 is detected a "knock" is registered and the counter records the event. If two more knocks occur within half a second of one another then the CPX will turn the pixels blue. Otherwise, the knock counter will reset and the pixels will remain off. Successfully recorded knocks briefly turn the pixels green.

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
  mic = CircuitPlayground.mic.peak(10);
  Serial.print(200);
  Serial.print(",");
  Serial.print(mic);
  Serial.print(",");
  Serial.println(350);
  delay(5);

  if (mic > 200) {
    CircuitPlayground.setPixelColor(5, 0x00FF00);
    knockCounter++;
    //Serial.print("Knock Counter: "); Serial.println(knockCounter);
    if (!timerActive) {
      startTime = millis();
      timerActive = true;
    }
    now = millis();
    delay(50);
    CircuitPlayground.setPixelColor(5, 0x000000);
  }

  if (knockCounter > 2) {
    for (int i = 0; i < 10 ; i++) {
      CircuitPlayground.setPixelColor(i, 0x0000FF);
    }
    delay(3000);
    for (int i = 0; i < 10 ; i++) {
      CircuitPlayground.setPixelColor(i, 0x000000);
    }
    knockCounter = 0;
    timerActive = false;
  }

  if (now - startTime > 500) {
    knockCounter = 0;
    timerActive = false;
  }

}
~~~~

[Download the Knock Knock Knock Code](KnockKnockKnock.ino)

### Key Lesson

There are two main lessons that come with this program. First, using the serial plotter to look at sensor patterns (signals) to help develop software that can reliably detect those patterns. Second, Using signals to do something, which in this case is determining if knock pattern is present. *Note: this software could be updated to use the acceleromter instead.*
