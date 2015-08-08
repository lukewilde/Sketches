// https://dronesandrovs.files.wordpress.com/2012/11/esc-brushless.png

#include <Servo.h>

Servo escs[4];
int escPins[4] = { 6, 9, 10, 11 };

int throttlePin = 0;

void setup() {
  Serial.begin(9600);

  calibrate();

  Serial.println();
  Serial.println(" -- Ready for orders! -- ");
}

void loop() {
  int throttle = analogRead(throttlePin);
  throttle = map(throttle, 0, 1023, 0, 90);

  Serial.println(throttle);
  writeToEscs(throttle);

  Serial.println(throttle);
}

void calibrate() {

  initialise();
  setMaxPower();
  setMinPower();
  chill();
}

void chill() {
  Serial.println();
  Serial.println("  -- Auto chill -- ");
  Serial.println("420 blaze it?");
  waitForInput();
  writeToEscsAndLog(90);
}

void setMinPower() {
  Serial.println();
  Serial.println(" -- Calibrating min power -- ");
  Serial.println("Ready to min power?");

  waitForInput();

  writeToEscsAndLog(0);
}

void setMaxPower() {
  Serial.println();
  Serial.println(" -- Calibrating max power -- ");
  Serial.println("Ready to max power?");

  waitForInput();

  writeToEscsAndLog(179);
}

void waitForInput() {
  while (!Serial.available());
  Serial.read();
}

void initialise() {
  Serial.println(" -- Initialise -- ");
  Serial.println("Want to initialise?");

  waitForInput();

  for (int i = 0; i < 4; i++) {
    escs[i].attach(escPins[i]);
  }

  Serial.println("Initialised!");
}

void writeToEscs(int throttle) {
  for (int i = 0; i < 4; i++) {
    escs[i].write(throttle);
  }
}

void writeToEscsAndLog(int throttle) {

  Serial.print("Setting escs: ");

  for (int i = 0; i < 4; i++) {
    // Serial.println(i);
    Serial.print(", ");
    Serial.print(i);
    escs[i].write(throttle);
  }

  Serial.print(" are set to: ");
  Serial.println(throttle);
}
