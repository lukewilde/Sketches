/*
	Well good Police

	fades an LED on and off, repeatedly.
 */

int bluePin = 5;
int redPin = 3;

int blueBrightness = 0;
bool blueIsDimming = false;

int redBrightness = 100;
bool redIsDimming = false;

int maxBrightness = 255;

int incrementor = 1;

void setup() {
	pinMode(bluePin, OUTPUT);
	pinMode(redPin, OUTPUT);

	// Serial.begin(9600);
}

void loop() {

	// Serial.println(blueBrightness);
	// Serial.println(redBrightness);

	blueBrightness = getNewBrightness(blueBrightness, blueIsDimming);
	redBrightness = getNewBrightness(redBrightness, redIsDimming);

	analogWrite(bluePin, blueBrightness);
	analogWrite(redPin, redBrightness);

	delay(1);
}

int getNewBrightness(int brightness, bool &isDimming) {

	if (brightness >= maxBrightness) {
		// Serial.println("switch");
		isDimming = true;
	} else if (brightness <= 0) {
		// Serial.println("switch up");
		isDimming = false;
	}

	if (isDimming) {
		return brightness + (incrementor * -1);
	}

	return brightness + incrementor;
}