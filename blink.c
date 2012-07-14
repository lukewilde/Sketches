/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

int inputPin = 9;

void setup() {
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(inputPin, OUTPUT);
}

void loop() {
  analogWrite(inputPin, 255);   // set the LED on
  delay(500);              // wait for a second
  analogWrite(inputPin, 120);    // set the LED off
  delay(500);              // wait for a second
}