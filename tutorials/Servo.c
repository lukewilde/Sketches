/*
  Servo
  Servo's
 */

#include <Servo.h>

Servo servo;

int outputPin = 9;
int angle = 0;

void setup() {
  // initialize the digital pin as an output.
  servo.attach(outputPin);
}

void loop() {
  for (angle = 0; angle < 180; angle++) {
    servo.write(angle);
    delay(15);
  }

  for (angle = 180; angle > 1; angle--) {
    servo.write(angle);
    delay(15);
  }
}