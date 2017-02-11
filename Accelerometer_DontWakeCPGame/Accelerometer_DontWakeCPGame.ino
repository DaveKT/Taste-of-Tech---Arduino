/*  Author:   David Tassara
 *  Purpose:  Demonstrate the raw values from the circuit playground accelerometer.
 *  Date:     10 Feb 2017
 *  Version:  1.0
 *  TODO set maxV as float, move setup to loop
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
    wakeCP();
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
  // Set game difficulty based on skill level
  switch (skillLevel) {
    case 1:
      maxV = 3;
      CircuitPlayground.setPixelColor(0, 0x98FF48);
      CircuitPlayground.setPixelColor(1, 0x98FF48);
      CircuitPlayground.setPixelColor(2, 0x98FF48);
      break;
    case 2:
      maxV = 2;
      CircuitPlayground.setPixelColor(0, 0x98FF48);
      CircuitPlayground.setPixelColor(1, 0x98FF48);
      break;
    case 3:
      maxV = 1;
      CircuitPlayground.setPixelColor(0, 0x98FF48);
      break;
  }
}

void wakeCP() {
  CircuitPlayground.playTone(440, 1000);
  for(int i=5;i<10;i++) {
    CircuitPlayground.setPixelColor(i, 0x002366);
    delay(100);
  }
  for(int i=9;i>4;i--) {
    CircuitPlayground.setPixelColor(i, 0x000000);
    delay(100);
  }
}

