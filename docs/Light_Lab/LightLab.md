## Light Lab

Provides a quick review of simple programming concepts and introduces the light sensor. See the full [Light Lab Code](Light_Lab.ino) for a full explanation of the code below.

### Behavior

The code reads the value from the light sensor and outputs the value in a serial connection. You can use the Serial plotter to track the changes.

### Code

~~~~
const int MAXV = 160;
const int MINV = 0;

#include <Adafruit_CircuitPlayground.h>

void setup() {
 CircuitPlayground.begin();
 Serial.begin(9600);
}

void loop() {


 lightValue = CircuitPlayground.lightSensor();

 Serial.print(MAXV); Serial.print(","); Serial.print(lightValue); Serial.print(","); Serial.println(MINV);

 delay(100);
}
~~~~

[Download the Light Lab Code](Light_Lab.ino)

### Key Lesson

Introduces using the light sensor and provides a quick review for prior lessons.
