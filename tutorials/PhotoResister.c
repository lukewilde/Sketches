/*
 * A simple programme that will change the intensity of
 * an LED based  * on the amount of light incident on
 * the photo resistor.
 *
 */

//PhotoResistor Pin
int lightPin = 0;

//LED Pin
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT); //sets the led pin to output
  Serial.begin(9600);
}

 /*
 * loop() - this function will start after setup
 * finishes and then repeat
 */
void loop() {

  int lightLevel = analogRead(lightPin); //Read the
  lightLevel = map(lightLevel, 0, 900, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);

  Serial.println(lightLevel);

  analogWrite(ledPin, lightLevel);
}