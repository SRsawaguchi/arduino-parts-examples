/*
    DCモータを駆動させるプログラム
*/

#include <Arduino.h>
#define PIN_BASE 11

void setup() {
  pinMode(PIN_BASE, OUTPUT);
}

void motorOn() {
  digitalWrite(PIN_BASE, HIGH);
}

void motorOff() {
  digitalWrite(PIN_BASE, LOW);
}

void loop() {
  motorOn();
  delay(2000);

  motorOff();
  delay(2000);
}
