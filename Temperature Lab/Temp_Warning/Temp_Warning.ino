//Name: Temp Warning
//Author: David Tassara
//Date: December 5, 2013
//Purpose: Gives a visual alarm (LED) when the temp exceeds a given value

int tempSensor = 0; //the TMP36 Sensor is connected here
int led = 13; //the LED is connected on this pin
int voltage;
float tempReading;
float tempC;
float tempF;
float maxWarnTempF = 75.0; //if the temp goes above this number the LED will illuminate

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() { 
  voltage = analogRead(tempSensor);
  tempReading = voltage * 5.0;
  tempReading /= 1024.0;
  tempC = (tempReading - 0.5) * 100;
  tempF = (tempC * 9.0 / 5.0) + 32.0;
  
  Serial.print(tempC);Serial.println("C");
  Serial.print(tempF);Serial.println("F");
  
  if (tempF > maxWarnTempF ) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  delay(1000);
}
