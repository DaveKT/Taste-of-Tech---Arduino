## Taste of Tech: Arduino / Circuit Playground Edition
ToT Arduino is a four day course taught over the period of four weeks (one day per week). The primary goal of the course is to intoduce technical concepts to students who show an interest and who may not have had prior exposure. During the ToT class the participating students are also exposed to thee sessions with Hour of Code and thress sessions with digital movie making. This course is specifically taylored to the Circuit Playground from Adafruit but could be modified for other Arduino-like microcontrollers. 

###Course Materials for ToT Arduino

*	[Circuit Playground](https://www.adafruit.com/products/3000)
*	[Arduino IDE](https://www.arduino.cc/en/Main/Software)
*	[Circuit Playground Board Support Package for Arduino IDE](https://learn.adafruit.com/add-boards-arduino-v164/overview)
*	[Circuit Playground Lesson Software & Plans](https://github.com/DaveKT/Taste_of_Tech_Arduino)
*	USB cables to connect the Circuit Playground to the computers
*	Computers (at least one for every two students is recommended)

###Course Outline

####Week One
**Goals**: Learn the different parts of the circuit playground microcontoller, load and use a program from the Arduino IDE, learn how to blink a light and make a sound.

**Programs**

1.	Arduino Example - Circuit Playground Hello_Blink
2.	[Arduino Morse Encoder](https://github.com/DaveKT/Taste_of_Tech_Arduino/tree/master/ArduinoMorseEncoder)
3.	[Play A Scale](https://github.com/DaveKT/Taste_of_Tech_Arduino/tree/master/Play_A_Scale)

**Setup**

Prior to starting the class make sure that the computers all have the Arduino IDE installed and the support for the Adafruit Circuit Playgrounds installed. If this is the first time setting up I also recommend loading and running a sketch to make sure everything works. Troubleshooting connectivity issues is not fun during classtime. 

**Session Guide**

1.	Give a quick definition of the microcontoller, input examples, and output examples. Ask about where we can find these things in everyday life.
2.	Review the Adafruit Circuit Playground. Point out the processor, sensors, outputs (LEDs and speaker), and IO pins/pads.
3.	Review the Arduino IDE. In particular review choosing and example program and loading a sketch.
4.	Have the students load the Hello_Blink program.
5.	Call the student back demonstrate the use of the serial monitor. Explain that it is two way communication for the board and can be used to read sensor values and send data to the board.
6.	Have the students load the Arduino Morse Encoder and use the serial monitor to enter their names and convert to morese code.
7. Have the students load and run the play a scale program.

**Stretch**

1.	Walk through the play a scale code. Review the Circuit Playgournd calls. Focus on changeing the parameters to have sounds play at different pitches and durations.
2.	Modify the play a scale program to play extra notes in the loop section of the sketch.
3. Have the students modify the code to their liking.
