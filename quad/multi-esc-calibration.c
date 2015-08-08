// https://dronesandrovs.files.wordpress.com/2012/11/esc-brushless.png

#include <Servo.h>

Servo escs[4];
int escPins[4] = { 6, 9, 10, 11 };

int throttlePin = 0;

void setup() {
  Serial.begin(9600);
  calibrate();
}

void loop() {
  int throttle = analogRead(throttlePin);
  throttle = map(throttle, 0, 1023, 0, 90);

  writeToEscs(throttle);

  Serial.print("chilling at ");
  Serial.println(throttle);

}

void calibrate() {
  for (int i = 0; i < escs.length; i = i++) {
    escs[i].attach(escPins[i]);
  }

  Serial.println("Calibrating max power");
  writeToEscs(179);

  // Wait for input
  while (!Serial.available());
  Serial.read();

  Serial.println("Calibrating min power");
  writeToEscs(0);

  // Wait for input
  while (!Serial.available());
  Serial.read();

  Serial.println("Set chill");
  writeToEscs(90);
}

void writeToEscs(int throttle) {
  for (int i = 0; i < escs.length; i = i++) {
    Serial.println(myPins[i]);
  }
}
