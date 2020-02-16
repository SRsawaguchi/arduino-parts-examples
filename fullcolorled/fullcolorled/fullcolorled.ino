/*
    フルカラーLEDをR,G,Bの順番に点灯させるプログラム
*/

#include <Arduino.h>

#define PIN_R 6
#define PIN_G 3
#define PIN_B 5

void ledSetRGB(int r, int g, int b) {
  digitalWrite(PIN_R, r);
  digitalWrite(PIN_G, g);
  digitalWrite(PIN_B, b);
}

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void loop() {
  const int duration = 1000;

  // R
  ledSetRGB(HIGH, LOW, LOW);
  delay(duration);

  // G
  ledSetRGB(LOW, HIGH, LOW);
  delay(duration);

  // B
  ledSetRGB(LOW, LOW, HIGH);
  delay(duration);
}
