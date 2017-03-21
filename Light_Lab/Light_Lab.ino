/*
 * Author:  David Tassara
 * Date:    February 18, 2017
 * Purpose: Demonstrate the light sensor on the Ciccuit Playground
 * Note:    This sketch demonstrates constants, variables, loops, and the assignment operator. During
 *          the code walktrhough you should talk about each of these elements. 
 */

 const int MAXV = 160;  //this number should be adjusted so that the nominal light reading is plotted midway between the MIN and MAX.
 const int MINV = 0;
 int lightValue; //this is a variable; it's used to store the current reading of the light sensor.

 #include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin(); //since we are working we the CP we need to tell the platform to start.
  Serial.begin(9600); //We also need to torn on Serial so that we can send our readings to the computer.
}

void loop() {

  //the line below takes a reading from the CP light sensor and stores the value in our lightValue variable.
  //the = sign in this case is called an assignment operator since we are using it to assign a value to a variable
  lightValue = CircuitPlayground.lightSensor();

  //this line sends a string ("MAXV,lightValue,MINV") to the computer (e.g. "100,67,0"
  Serial.print(MAXV); Serial.print(","); Serial.print(lightValue); Serial.print(","); Serial.println(MINV);

  //this line tell the program to wait for 100 ms. 1000ms = 1 second
  //this means program is limited to taking 10 readings every second
  delay(100);
}
