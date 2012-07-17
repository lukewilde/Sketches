/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 */

int outputPin = 9;

void setup() {
  // initialize the digital pin as an output.
  pinMode(outputPin, OUTPUT);
}

void loop() {
  analogWrite(outputPin, 255);
  delay(500);
  analogWrite(outputPin, 120);
  delay(500);
}