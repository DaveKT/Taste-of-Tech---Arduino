 /*
  * Author: David Tassara
  * Board:  Circuit Playground
  * Date:   February 14, 2017
  * 
  * Note:   This code will play a scale. What happens if you move
  *         the "for" loop from setup() to loop()? Test your guess
  *         by moving the code.
  * 
  */
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
