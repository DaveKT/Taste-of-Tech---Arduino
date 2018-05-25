## Play A Scale

The name says it all.

### Behavior

This code introduces how to play sound on the circuit playground. It's also an opportunity to discuss the basic form of an Arduino Sketch.

*Note, the code that plays the sound is in setup so that it will only run once. If the code is moved to loop() then the scale will play over and over. A room full of students with looping scales may lead to mayhem You've been warned. :)*

### Code

~~~~
#include <Adafruit_CircuitPlayground.h>

int duration = 500; //how long should each note play

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

void setup()
{
  for (int i = 0; i < numTones; i++)
  {
    CircuitPlayground.playTone(tones[i], duration);
    delay(100);
  }
}

void loop()
{
}
~~~~

[Download the Play A Scale Code](Play_A_Scale.ino)

### Key Lesson

Talk about the parts of a sketch. Point out the setup() and loop() functions. Both are required. Setup runs once, loop runs forever. Set up us used to prep the Arduino to run your code (set variables, turn on features, etc) loop is used to run the code indefinitely.
