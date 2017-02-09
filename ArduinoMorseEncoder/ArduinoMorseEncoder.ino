#include "Adafruit_CircuitPlayground.h"

//*******************************************************//
//Morse code playback variables
//Adjust PITCH to your liking and DOT for speed faster/slower
const int PITCH = 600; // Morse code audio is sent at 600-800 Hz. 680 is quite nice
const int DOT = 75;   //time duration in millis, change this to adjust transmission speed

const int DASH = 3 * DOT; //Morse standard dash is 3x longer than dot
const int GAP = DOT+25; //Morse inter-element gap within a character is same length as dot
const int INTER_LETTER = 3 * DOT; //Morse short gap between letters is 3x dot length
const int INTER_WORD = 7 * DOT; //Morse medium gap between words is 7x dot length
//*******************************************************//

String uinput = "";
int messageSize;

void setup() {

  Serial.begin(9600);

  CircuitPlayground.begin();
  CircuitPlayground.strip.clear();
  CircuitPlayground.strip.show();

}


void loop() {

  uinput = Serial.readString();
  uinput.toUpperCase();

  if (uinput != "") {
    
    //explode string to char array for sending
    messageSize = uinput.length() + 1;
    char mychararray[messageSize];
    uinput.toCharArray(mychararray, messageSize);

    for (int i = 0; i < messageSize; i++) {
      Serial.print(mychararray[i]);
      
      playMorseLetter(mychararray[i]);
      
      
    }
    Serial.println();
  }

}

void playMorseLetter(char letter) {
  // Morse table by Usman Muzaffar
  // Adapted from: http://stackoverflow.com/a/28058216
  // Define two tables of strings one for letters and one for numbers,
  // that return the Morse encoding. By using two separate tables, we
  // can just offset the ASCII value of either a number or letter as
  // the index to look up the Morse encoding.
  static const char *ALPHA_TABLE[] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
  };
  static const char *NUM_TABLE[] = {
    "-----", //0
    ".----", //1
    "..---", //2
    "...--", //3
    "....-", //4
    ".....", //5
    "-....", //6
    "--...", //7
    "---..", //8
    "----.", //9
  };
  if (letter == '/') { // use "/" as space between words
    delay(INTER_WORD);
    return;
  }

  // Look up the morseCode string for this letter
  // by finding the right table.

  char* morseCode;
  if (isalpha(letter)) {
    morseCode = ALPHA_TABLE[letter - 'A'];
  } else {
    morseCode = NUM_TABLE[letter - '0'];
  }

  for (int i = 0; i < strlen(morseCode); i++) {
    int duration = morseCode[i] == '-' ? DASH : DOT;
    for(int p = 0; i < 6; p++
    CircuitPlayground.setPixelColor(0, 0, 0, 255);
    CircuitPlayground.playTone(PITCH, duration);
    CircuitPlayground.clearPixels();
    delay(GAP);
  }
  delay(INTER_LETTER);
}
