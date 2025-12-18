#include "Arduino.h"
// www.elegoo.com
// 2016.12.08
#include "SR04.h"
#define TRIG_PIN 10
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

void setup()
{
  Serial.begin(9600);
  delay(50);
}

bool objectPresent = false;

void loop() {

  int d = sr04.getDistance();

  if (d > 0 && d < 40) {
    if (!objectPresent) {
      Serial.println("TRIGGER");
      objectPresent = true;
    }
  } else {
    objectPresent = false;  
  }

  delay(50);
}

