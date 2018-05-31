//Purpose: Demonstrate the use of the slide switch.

//import the circuit playground library
#include <Adafruit_CircuitPlayground.h>

//used to keep track of the slide switch position
bool current;

void setup() {

  //Enable Serial (for printing), start Circuit Playground, and
  //get the state of the slide switch
  Serial.begin(9600);
  CircuitPlayground.begin();
  current = CircuitPlayground.slideSwitch();

}

void loop() {

  //check the state of the slideswitch and print which side it's on
  if(!current == CircuitPlayground.slideSwitch()) {
    if(CircuitPlayground.slideSwitch()) {
      Serial.println("Switch is on the left.");
    } else {Serial.println("Switch is on the right.");}
  }

  //update the current position
  current = CircuitPlayground.slideSwitch();
  delay(100);

}
