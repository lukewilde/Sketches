/*
 * We have already controlled 8 LEDs however this does it in a slightly
 * different manner. Rather than using 8 pins we will use just three
 * and an additional chip.
 */


//The 74HC595 uses a serial communication link which has three pins
int data = 3;
int latch = 5;
int clock = 6;

int temperaturePin = 0;
float temperature = 0;

//Used for single LED manipulation
int ledState = 0;

const int ON = HIGH;
const int OFF = LOW;
const int DELAY_TIME = 2000;

void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  temperature = getVoltage(temperaturePin);
  temperature = (temperature - .5) * 100;

  Serial.println(temperature);
  Serial.println(floor(temperature + 0.5));

  updateLEDs(floor(temperature + 0.5));
  delay(DELAY_TIME);
}

/**
 * Returns the voltage on the analog input defined by pin.
 *
 * Converting from a 0 to 1023 digital range to 0 to 5 volts
 * (each 1 reading equals ~ 5 millivolts)
 */
float getVoltage(int pin){
  return (analogRead(pin) * .004882814);
}

/**
 * Sends the LED states.
 */
void updateLEDs(int value) {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, value);
  digitalWrite(latch, HIGH);
}