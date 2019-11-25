/*
    LEDを1秒おきに点滅させるプログラム。
*/

#include <Arduino.h>

#define PIN_LED (13)

void setup() {
    pinMode(PIN_LED, OUTPUT);
}

int led_state = 0;
void loop() {
    if (led_state ^= 0x01) {
        digitalWrite(PIN_LED, HIGH);
    } else {
        digitalWrite(PIN_LED, LOW);
    }
    delay(1000);
}
