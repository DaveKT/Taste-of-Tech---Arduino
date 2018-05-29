## Light Theremin

This application will act as a theremin (a musical instrument that plays different notes based on where your hand is). Lines 24 and 27 may be commented out/in to switch between debugging mode and "play" mode. Advanced: What happens when you change the int value (currently set to 100) to some other value? Make your guess after you've run the code in debug mode with the Serial Plotter running then change the value to test your answer.

### Behavior

The code reads reads the value from the light sensor and plays a tone based on the amount of light received. Greater light results in a higher tone. *Note, best when used with a flashlight. If a flashlight isn't handy the code can be modified to work with shadow or less light.*

### Code

~~~~
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
    CircuitPlayground.playTone(lightValue, 50, false);
  }

  delay(50);
}
~~~~

[Download the Light Theramin Code](Light_Theramin.ino)

### Key Lesson

Provides a fun opportunity for students to modify software variables and other code. Alternatively, you can start with the [Light_Theramin_A](/docs/Light_Theramin_A/Light_Theramin_A.ino) which has coding errors (bugs) the students need to resolve.
