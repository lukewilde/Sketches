/*
  Well good 8 pin array party
 */

int ledPins[]  = {2,3,4,5,6,7,8,9};
int length = sizeof(ledPins) / sizeof(int);

void setup() {

  Serial.begin(9600);
  Serial.println(length);

  for (int i = 0; i < length; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {

  // Light random LED.
  randomChange();
  delay(100);

  // Streak on.
  // incrementalChange(HIGH, 100);
  // incrementalChange(LOW, 100);

  // Blink every second LED.
  // suddenChange(HIGH, 2);
  // delay(500);
  // suddenChange(LOW, 2);
  // delay(500);
}

void randomChange() {
  resetLeds();

  int random = (rand() % (length - 0)) + 0;
  digitalWrite(ledPins[random], HIGH);
}

void resetLeds() {
  for (int i = 0; i < length; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void incrementalChange(int value, int duration) {
  for (int i = 0; i < length; i++) {
    digitalWrite(ledPins[i], value);
    delay(duration);
  }
}

void suddenChange(int value, int everyNPins) {

  for (int i = 0; i < length; i++) {
    if (i % everyNPins == 0) {
      digitalWrite(ledPins[i], value);
    }
  }
}