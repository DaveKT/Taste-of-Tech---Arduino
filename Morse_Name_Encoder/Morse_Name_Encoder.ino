/*
  Simple sketch to send morse code via the Serial Monitor

  GNU GPLv3 license (http://www.gnu.org/licenses)
  Contact: raronzen@gmail.com  (not checked too often..)
  Details: http://raronoff.wordpress.com/2010/12/16/morse-endecoder/
*/

#include <avr/pgmspace.h>
#include <MorseEnDecoder.h>

// Pin mapping     
const byte morseOutPin = 13;
morseEncoder morseOutput(morseOutPin);

void setup()
{
  Serial.begin(9600);
  Serial.println("Morse EnDecoder barebones demo");
  
  // Setting Morse speed in wpm - words per minute
  // If not set, 13 wpm is default anyway
  morseOutput.setspeed(8);
}


void loop()
{
  // Need to call these once per loop
  morseOutput.encode();

  // SEND MORSE (OUTPUT)
  // Encode and send text received from the serial port (serial monitor)
  if (Serial.available() && morseOutput.available())
  {
    // Get character from serial and send as Morse code
    char sendMorse = Serial.read();
    morseOutput.write(sendMorse);
  }

}

