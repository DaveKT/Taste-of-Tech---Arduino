 /*
  * Author: David Tassara
  * Board:  Circuit Playground
  * Date:   April 4, 2017
  * 
  * Note:   Without any modification this code will play a scale.
  *         Your task is to replace the scale with the "mystery song"
  * 
  */
#include <Adafruit_CircuitPlayground.h>

// 261, 294, 330, 349, 392, 440, 494, 523
// C    D    E    F    G    A    B    C

// Your CP should play the song notes below. After you're done programming get my attention.
// qE, qD, qC, qD, qE, qE, hE, qD, qD, hD, qE, qG, hG
// qE, qD, qC, qD, qE, qE, qE, qE, qD, qD, qE, qD, wC

int whole = 1000;
int half = 500;
int quarter = 250;

void setup()
{
  // There is nothing to set up since we're just playing sounds.
  // Leave this section blank.
}

void loop()
{
  // Remove this part of the code. You can either delete the lines OR comment it out
  CircuitPlayground.playTone(261, half);
  delay(10);
  CircuitPlayground.playTone(294, half);
  delay(10);
  CircuitPlayground.playTone(330, half);
  delay(10);
  CircuitPlayground.playTone(349, half);
  delay(10);
  CircuitPlayground.playTone(392, half);
  delay(10);
  CircuitPlayground.playTone(440, half);
  delay(10);
  CircuitPlayground.playTone(494, half);
  delay(10);
  CircuitPlayground.playTone(523, half);

  //INSERT YOUR SONG CODE HERE
 
  delay(5000); // Don't delete this line. We should wait 5 seconds between songs.
}
