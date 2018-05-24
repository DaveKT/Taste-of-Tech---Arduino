## Don't Wake the Circuit Playground Game

This application applies many of the core concepts in programming including variables, conditional statements, and loops. Beginning programmers may require the instructor to walk through the code with them before they fully understand.

### Behavior

The program challenges the player to move the circuit playground some distance without setting off the "alarm". It takes a veeery steady hand. At the start of the game the player may choose a level between "easy" and "ludicrous" by pressing the "left" button. Play is started once the player presses the "right" button.

### Code

~~~~
#include <Adafruit_CircuitPlayground.h>

float X, Y, Z, maxV;
int skillLevel;

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
// Serial.print(maxV);
// Serial.print(",");
// Serial.print(X);
// Serial.print(",");
// Serial.print(Y);
// Serial.print(",");
// Serial.print(Z);
// Serial.print(",");
// Serial.println(-maxV);


  if (X > maxV | X < -maxV | Y > maxV | Y < -maxV | Z > maxV | Z < -maxV) {
    wakeCP();
  }
  delay(100);

}

void chooseSkillLevel() {
  while (!CircuitPlayground.rightButton()) {
    if (CircuitPlayground.leftButton()) {
      skillLevel = skillLevel + 1;
      if (skillLevel > 5) skillLevel = 1;

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
    case 1: //easy
      maxV = 3;
      CircuitPlayground.setPixelColor(0, 0x00FF00);
      break;
    case 2: //moderate
      maxV = 2;
      CircuitPlayground.setPixelColor(0, 0x00FF00);
      CircuitPlayground.setPixelColor(1, 0x00FF00);
      break;
    case 3: //difficult
      maxV = 1;
      CircuitPlayground.setPixelColor(0, 0x00FF00);
      CircuitPlayground.setPixelColor(1, 0x00FF00);
      CircuitPlayground.setPixelColor(2, 0x00FF00);
      break;
    case 4: //insane
      maxV = 0.5;
      CircuitPlayground.setPixelColor(0, 0x00FF00);
      CircuitPlayground.setPixelColor(1, 0x00FF00);
      CircuitPlayground.setPixelColor(2, 0x00FF00);
      CircuitPlayground.setPixelColor(3, 0x00FF00);
      break;
    case 5: //ludicrous
      maxV = 0.35;
      CircuitPlayground.setPixelColor(0, 0x00FF00);
      CircuitPlayground.setPixelColor(1, 0x00FF00);
      CircuitPlayground.setPixelColor(2, 0x00FF00);
      CircuitPlayground.setPixelColor(3, 0x00FF00);
      CircuitPlayground.setPixelColor(4, 0x00FF00);
  }
}

void wakeCP() {
  for(int i=5;i<10;i++) {
    CircuitPlayground.setPixelColor(i, 0x002366);
    CircuitPlayground.playTone(440, 75);
  }
  for(int i=9;i>4;i--) {
    CircuitPlayground.setPixelColor(i, 0x000000);
    CircuitPlayground.playTone(440, 75);
  }
}
~~~~

[Download the Don't Wake the CP Game](Accelerometer_DontWakeCPGame.ino)

### Key Lesson

Review fundamental programming concepts and have fun!
