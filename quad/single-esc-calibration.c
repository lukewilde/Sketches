// https://dronesandrovs.files.wordpress.com/2012/11/esc-brushless.png

#include <Servo.h>

Servo esc;
int throttlePin = 0;
int escPin = 9;

void setup() {
  Serial.begin(9600);
  calibrate();
}

void loop() {
  int throttle = analogRead(throttlePin);
  throttle = map(throttle, 0, 1023, 0, 90);
  esc.write(throttle);
  Serial.print("chilling at ");
  Serial.println(throttle);

}

void calibrate() {
  esc.attach(escPin);

  Serial.println("Calibrating max power");
  esc.write(179);

  // Wait for input
  while (!Serial.available());
  Serial.read();

  Serial.println("Calibrating min power");
  esc.write(0);

  // Wait for input
  while (!Serial.available());
  Serial.read();

  Serial.println("Set chill");
  esc.write(90);
}
