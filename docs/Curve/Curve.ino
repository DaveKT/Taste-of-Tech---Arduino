
const float pi = 3.1415;
const float FREQUENCY = 5.0;
int current;
int outV;
float x;

void setup() {
  Serial.begin(115200);
}

void loop() {

  current = millis()*10;
  x = sin(2 * pi * FREQUENCY * current);
  outV = myMap(x, -1.0, 1.0, 1, 100);
  //  Serial.println(current);
  //  Serial.println(x);
  //  Serial.println(outV);

  for (int i = 0; i < int(outV); i++) {
    Serial.print("*");
  }
  //  Serial.print(outV);
  Serial.println();

  delay(10);
}

float myMap(float v, float x0, float x1, float y0, float y1) {
  return y0 + (v - x0) * ((y1 - y0) / (x1 - x0));
}

