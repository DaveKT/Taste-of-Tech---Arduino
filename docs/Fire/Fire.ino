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

  //set the RGB values for our "fire"
  int r = 255;
  int g = r - 90;
  int b = 40;

  //for each neopixel vary the flame color to make it "flicker"
  for (int x = 0; x < 10; x++) //we use 10 because that's how many CP Pixels there are
  {
    //pick a random number and adjust the color by that amount.
    int flicker = random(50, 150);
    int r1 = r - flicker;
    int g1 = g - flicker;
    int b1 = b - flicker;
    //don't go below zero for any pixel
    if (g1 < 0) g1 = 0;
    if (r1 < 0) r1 = 0;
    if (b1 < 0) b1 = 0;
    //set that pixel's color
    CircuitPlayground.setPixelColor(x, r1, g1, b1);
  }
  //wait a random amount of time before updating the pixels again
  //to give the fliker a natural feeling.
  delay(random(50, 150));
}
