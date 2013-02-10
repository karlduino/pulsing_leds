/**
 Two pulsing LEDs, sort of like Apple's sleep mode LED

 LED connections: pin -> resisitor -> LED -> gnd    
**/

#include "math.h"
const int LED[2] = {11, 9};
const int nstep = 100;
const int maxOutput = 255*0.25;
const int timePerPulse = 2000;
int value;
int whichLED = 0;

void setup() {
  for(int j=0; j<2; j++) {
    pinMode(LED[j], OUTPUT);
    digitalWrite(LED[j], 0);
  }
  Serial.begin(9600);
}

void loop(){
  for(int i=0; i<nstep; i++) {
    delay(timePerPulse/nstep);

    value = (int)((double)maxOutput*(1-abs(cos((double)(i+1) * M_PI / (double)nstep))));

    Serial.println(value);
    analogWrite(LED[whichLED], value);
  }
  digitalWrite(LED[whichLED], 0);

  whichLED = 1 - whichLED;
  delay(timePerPulse/2);
}
