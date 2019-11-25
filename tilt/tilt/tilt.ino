/*
    チルトスイッチが傾きを検出している間、LEDを点灯させる。
*/

#include <Arduino.h>

#define PIN_LED (13)
#define PIN_TILT (9)

void setup() {
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    if (digitalRead(PIN_TILT) == LOW) {
      digitalWrite(PIN_LED, HIGH);
    } else {
      digitalWrite(PIN_LED, LOW);
    }

    delay(250);
}
