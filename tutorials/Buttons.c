/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 7.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 17 Jun 2009
 by Tom Igoe

  http://www.arduino.cc/en/Tutorial/Button
 */

const int button1 = 2;
const int button2 = 3;

const int ledPin =  9;

int brightness =  0;
int origionalValue = 20;
int incrementorValue = 0;

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  // Serial.begin(9600);
}

void loop() {

  brightness = updateBrightness();

  analogWrite(ledPin, brightness);
  delay(10);
}

int updateBrightness() {

  if (digitalRead(button1) == LOW) {
    incrementorValue = origionalValue;
  } else if (digitalRead(button2) == LOW) {
    incrementorValue = origionalValue * -1;
  }

  brightness += incrementorValue;

  return  constrain(brightness, 0, 255);

  // Serial.println(brightness);
  // return brightness;
}