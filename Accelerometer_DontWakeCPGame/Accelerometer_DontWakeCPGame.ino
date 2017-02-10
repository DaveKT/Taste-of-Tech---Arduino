/*  Author:   David Tassara
 *  Purpose:  Demonstrate the raw values from the circuit playground accelerometer.
 *  Date:     10 Feb 2017
 *  Version:  1.0
 */

#include <Adafruit_CircuitPlayground.h>

float X, Y, Z;
int skillLevel;
int maxV;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

  chooseSkillLevel();
  setSkillLevel();
  
}

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ()-10;


//uncomment these lines to plot X,Y, Z with Serial Plotter
  Serial.print(maxV);
  Serial.print(",");
  Serial.print(X);
  Serial.print(",");
  Serial.print(Y);
  Serial.print(",");
  Serial.print(Z);
  Serial.print(",");
  Serial.println(-maxV);


  if (X > maxV | X < -maxV | Y > maxV | Y < -maxV | Z > maxV | Z < -maxV) {
    CircuitPlayground.playTone(440, 1000);
  }

  delay(100);
}

void chooseSkillLevel() {
  while (!CircuitPlayground.rightButton()) {
    if (CircuitPlayground.leftButton()) {
      skillLevel = skillLevel + 1;
      if (skillLevel > 3) skillLevel = 1;
      
      CircuitPlayground.clearPixels();
      for (int p=0; p<skillLevel; p++) {
        CircuitPlayground.setPixelColor(p, 0xFFFFFF);
      }
      
      delay(250); 
    }
  }
}

void setSkillLevel() {
  // Set game difficulty  based on skill level
  switch (skillLevel) {
    case 1:
      maxV = 3;
      break;
    case 2:
      maxV = 2;
      break;
    case 3:
      maxV = 1;
      break;
  }
}
