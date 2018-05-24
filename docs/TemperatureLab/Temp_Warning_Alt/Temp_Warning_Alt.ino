int thermistorPin = A0; //analog pin 0
int maxReading = 200;
int led = 13;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  int thermistorReading = analogRead(thermistorPin); 

  Serial.println(thermistorReading);
  
  
  if (thermistorReading > maxReading ) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  delay(1000);
}
