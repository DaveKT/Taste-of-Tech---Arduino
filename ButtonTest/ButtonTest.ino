#include <Adafruit_CircuitPlayground.h>
 
int lcurrentState;
int rcurrentState;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

}
 

void loop() {
  lcurrentState = CircuitPlayground.leftButton();
  rcurrentState = CircuitPlayground.rightButton();

  Serial.print(lcurrentState);Serial.print(",");Serial.println(rcurrentState*-1);

  delay(50);
}
