/*
    タクトスイッチを押下すると、LEDを点灯、消灯する。
*/

#include <Arduino.h>

#define PIN_LED (13)
#define PIN_SW (9)

void setup() {
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    if (digitalRead(PIN_SW) == HIGH) {
      digitalWrite(PIN_LED, HIGH);
    } else {
      digitalWrite(PIN_LED, LOW);
    }

    delay(250);
}
