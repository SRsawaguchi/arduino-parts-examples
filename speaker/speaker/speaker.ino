/*
    スピーカーから音を鳴らすプログラム。
*/

#include <Arduino.h>

#define PIN_SPEAKER (13)

void setup() {
    pinMode(PIN_SPEAKER, OUTPUT);
}

void loop() {
    tone(PIN_SPEAKER, 262); // ド

    delay(1000);
}
