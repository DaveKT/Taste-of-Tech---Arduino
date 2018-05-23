/*
 * Author:  David Tassara
 * Date:    February 13, 2017
 * Purpose: Demonstrate the microphone sensor on Arduino Playground
 * Note:    With the CP connected to USB run the serial plotter in Arduino IDE
 *          to help the student visualize the knocking. This is a great
 *          jumping off point for thresholds.
 */

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
