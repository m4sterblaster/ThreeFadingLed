/*
An Arduino sketch for three LED pulsing in turn, repeatedly. 
A progression from [Arduino's blinking LED example](http://arduino.cc/en/Tutorial/Blink?from=Tutorial.BlinkingLED):

Author: Stephanie Pau @citizeninventor  
*/

int ledPins[] = {9,10,11};
int fadeDelay = 10;
int fadeInDelay = fadeDelay;
int fadeOutDelay = fadeDelay * 2;
int pulseInterval = fadeDelay * 2;

void setup()  { 
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
} 

void loop()  { 
  for (int i = 0; i < 3; i++) {
    pulse(ledPins[i]);
    pulse(ledPins[i]);
  }
}

void pulse(int ledPin) {
    // to make light pulse like a heartbeat
    fadeIn(ledPin);
    delay(pulseInterval);
    fadeOut(ledPin);
    delay(pulseInterval);
}
void fadeIn(int ledPin){
    // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(ledPin, fadeValue);         
    delay(fadeInDelay);
  } 
}

void fadeOut(int ledPin){
  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(ledPin, fadeValue);         
    delay(fadeOutDelay);
  } 
}



