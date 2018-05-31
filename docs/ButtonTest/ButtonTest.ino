// Purpose: Detects a button press and outputs the event to serial.


#include <Adafruit_CircuitPlayground.h>

// Button states return an integer. 1 for pressed or 0 for not pressed.
int lcurrentState;
int rcurrentState;

// Turn on the serial monitor and start Circuit Playground.
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

}

//loop forever
void loop() {
  //get the current state of the buttons
  lcurrentState = CircuitPlayground.leftButton();
  rcurrentState = CircuitPlayground.rightButton();

  //print out the button state
  Serial.print(lcurrentState);Serial.print(",");Serial.println(rcurrentState);

  //small delay to give the processor some free time
  delay(50);
}
