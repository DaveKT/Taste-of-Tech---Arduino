/*
 * Note:  Toy program to simulate a flikering flame on the Adafruit
 *        Circuit Playground. Works best if placed in a glass jar with
 *        a paper filter.
 */

#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  
  int r = 255;
  int g = r - 90;
  int b = 40;

  for (int x = 0; x < 10; x++)
  {
    int flicker = random(50, 150);
    int r1 = r - flicker;
    int g1 = g - flicker;
    int b1 = b - flicker;
    if (g1 < 0) g1 = 0;
    if (r1 < 0) r1 = 0;
    if (b1 < 0) b1 = 0;
    CircuitPlayground.setPixelColor(x, r1, g1, b1);
  }
  delay(random(50, 150));
}
