/*
  Analog Input

 Created by David Cuartielles
 Modified 16 Jun 2009
 By Tom Igoe

 http://arduino.cc/en/Tutorial/AnalogInput

 */

int sensorPin = 0;
int ledPin = 9;

int sensorValue = 0;
int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  brightness = sensorValue / 4;
  Serial.println(brightness);
  analogWrite(ledPin, sensorValue);
}