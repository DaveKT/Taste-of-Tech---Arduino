## Taste of Tech: Circuit Playground Edition
ToT Arduino is a four day course taught over the period of four weeks (one day per week). The primary goal of the course is to introduce technical concepts to students who show an interest and who may not have had prior exposure. During the ToT class the participating students are also exposed to thee sessions with Hour of Code and three sessions with digital movie making. This course is specifically tailored to the Circuit Playground from Adafruit but could be modified for other Arduino-like microcontrollers.

### Course Materials for ToT Circuit Playground

*	[Circuit Playground](https://www.adafruit.com/products/3000)
*	[Circuit Playground Library Reference](https://caternuson.github.io/Adafruit_CircuitPlayground/)
*	[Arduino IDE](https://www.arduino.cc/en/Main/Software)
*	[Arduino Language Reference](https://www.arduino.cc/en/Reference/HomePage)
*	[Circuit Playground Board Support Package for Arduino IDE](https://learn.adafruit.com/add-boards-arduino-v164/overview)
*	[Circuit Playground Lesson Software & Plans](https://github.com/DaveKT/Taste_of_Tech_Arduino)
*	USB cables to connect the Circuit Playground to the computers
*	Computers (at least one for every two students is recommended)

### Course Outline

####Week One
**Goals**: Learn the different parts of the circuit playground microcontoller, load and use a program from the Arduino IDE, learn how to blink a light and make a sound.

**Programs**

1.	Arduino Example - Circuit Playground Hello_Blink
2.	[CP Morse Encoder](docs/CPMorseEncoder)
3.	[Play A Scale](docs/Play_A_Scale)

**Setup**

Prior to starting the class make sure that the computers all have the Arduino IDE installed and the support for the Adafruit Circuit Playgrounds installed. If this is the first time setting up I also recommend loading and running a sketch to make sure everything works. Troubleshooting connectivity issues is not fun during class time.

**Session Guide**

1.	Give a quick definition of the microcontoller, input examples, and output examples. Ask about where we can find these things in everyday life.
2.	Review the Adafruit Circuit Playground. Point out the processor, sensors, outputs (LEDs and speaker), and IO pins/pads.
3.	Review the Arduino IDE. In particular review choosing and example program and loading a sketch.
4.	Have the students load the Hello_Blink program.
5.	Call the student back demonstrate the use of the serial monitor. Explain that it is two way communication for the board and can be used to read sensor values and send data to the board.
6.	Have the students load the Arduino Morse Encoder and use the serial monitor to enter their names and convert to Morse code.
7. Have the students load and run the play a scale program.

**Stretch**

1.	Walk through the play a scale code. Review the Circuit Playground calls. Focus on changing the parameters to have sounds play at different pitches and durations.
2.	Modify the play a scale program to play extra notes in the loop section of the sketch.
3. Have the students modify the code to their liking.

#### Week Two
**Goals**: Learn about the other inputs and outputs available on the Circuit Playground. Apply the definition of inputs and outputs (interfaces) to discuss where electronic systems in our everyday life have inputs and outputs. Load more advanced scripts and use the serial plotter to investigate sensor readings.

**Programs**

1.	[Sound Graph](docs/SoundGraph)
2.	[KnockKnockKock](docs/KnockKnockKnock)
3.	[Accelerometer Graph](docs/Accelerometer_Graph)
4.	[Don't Wake the Circuit Playground](docs/Accelerometer_DontWakeCPGame/DontWake.md)

**Session Guide**

1.	Review all the inputs and outputs on the circuit playground (don't review the capacitive touch features of the pads as it might confuse students at this point). Use an image of the CP projected on the screen.
2.	Work with the class to come up with general definitions of the inputs/outputs and how they interface with users (people). Come up with some non-Arduino, CP examples.
3.	With the whole class load  Sound Graph  on the overhead and run the sketch. Open up the Serial Plotter and have the students take turns making some noise. Review the plotted signal and talk about thresholds.
4.	Have the students load the KnockKnockKnock sketch and start the Serial Plotter. Explain how the knock knock sketch works and point out the threshold line on the plot. Have the students take turns knocking to light the lights.
5. Have the students load the Accelerometer_Graph and run the Serial Plotter. Ask them to carefully rotate the CP and note how the graph changes. Bring everyone back together and discuss the axis of acceleration. Explain what the accelerometer is measuring (changes in orientation relative to the Earth's gravitational field.) Fun question, ask if this sketch will work on the moon, why or why not?

**Stretch**

1.	Have the students load the *Don't Wake the Circuit Playground Game*, explain how the game works, and let each student play a round on level three.
2.	If there is more time let them try level four (insane) or level 5 (ludicrous).

#### Week Three

**Goals**: Learn about coding in C. Introduce basic concepts of coding including variables, constants, operators & comparators, conditional statements, and loops. Practice using the serial plotter to debug a program. Learn to alter a program to change some basic behavior.

**Programs**

1.	[Light Lab](docs/Light_Lab)
2.	[Light Theramin](docs/Light_Theramin)
3.	[Light_Theramin_A](docs/Light_Theramin_A)

**Session Guide**

1.	Start the session by opening the Light_Lab on the CircuitPlayground on the overhead and walking through the code start from the top and walk all the way through to the end explaining each line. Things to point out:
	*	Comments
	*	Library
	*	setup and loop functions
	*	Constants
	*	Variables
	*	Assignment Operator
	*	Serial print and println
2.	Ask each student load the Light Lab code on their own CP. Once successfully loaded have them run the serial plotter. They should take note of the MIN, MAX lines as well as the sensed value. If the sensor value is not midway between the min and max have them adjust the MAXV constant so that the sensed reading is midway between the min & max.
3. Ask the students to load the Light_Theramin_A program. (Note, this version has bugs.) Do a walk through of the code with less detail than the prior walk through. Review conditional statements. DEMO the working program.
4.	Ask the students to review the code. Show that they can check the code by compiling. Once the code compiles have them load the code and see if it works. (It won't.) Help the students troubleshoot.

**Stretch**

1.	Ask the students to modify the code so that the tone goes up when the light level goes down.
2.	Ask the students to update the playTone function so that the notes play longer.

#### Week Four

**Goals**: Practice all the skills learned this session to debug, install, and play the simple Simple Simon game.

**Programs**

1.	Simple Simon A
2.	[Simple Simon](docs/SimpleSimon)

**Session Guide**

1.	Demo the Simple Simon game. Point out the use of buttons as selectors and explain that the pads are being used as capacitive touch sensors.
2.	Load the Simple Simon A lab into the IDE and project it onto the white board. Conduct a brief code walkthrough to reinforce the coding concepts learned in the prior week. DO NOT discuss the bugs but if the students find a bug ask them to record it so they can fix it in the next task.
3. Ask the students to load and debug Simple Simon A. Let the students know this program has a few more bugs than the program last week had.  

**Stretch**

1. 	Let the students pick any of the sketches they would like to play with from Github. Encourage them to modify the code to behave differently.
2. Write Blinky Code from Scratch
