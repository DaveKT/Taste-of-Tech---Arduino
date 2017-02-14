/*
 * Purpose: Circuit Playground Sensor Lesson
 * Author: David Tassara
 * Date: 3 February 2017
 * 
 * Note:  This application will act as a theramin (a musical instrucment that plays
 *        different notes based on where your hand is). Lines 24 and 27 may be commented 
 *        out/in to switch between debugging mode and "play" mode.
 *        
 *        Advanced: What happens when you change the int value (currently set to 100)
 *        to some other value? Make your guess after you've run the code in debug mode
 *        with the Serial Plotter running then change the value to test your answer.
*/

#include <Adafruit_CircuitPlayground.h>

int lightValue;

void setup()
{
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop()
{
  lightValue = CircuitPlayground.lightSensor();

  Serial.print(500); Serial.print(","); Serial.print(lightValue); Serial.print(","); Serial.println(0); 
   
  if (lightValue > 100) {
    //CircuitPlayground.playTone(lightValue, 50, false);
  }

  delay(100);
}
