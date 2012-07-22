// Controlling a servo position using a potentiometer (variable resistor)
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

#include <Servo.h>

Servo myservo;

int potpin = 0;
int val;

void setup()
{
  myservo.attach(9);
}

void loop()
{
  val = analogRead(potpin);
  val = map(val, 0, 900, 0, 255);
  myservo.write(val);
  delay(15);
}