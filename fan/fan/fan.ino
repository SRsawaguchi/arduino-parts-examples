/*
    ファンを回転させるサンプルプログラム。
    ※ファンが新品（まだ使ったことがない）場合、実際に回るまで少し時間がかかることがあります。
*/

#include <Arduino.h>

#define PIN_FAN (11)

void setup() {
    pinMode(PIN_FAN, OUTPUT);
}

void loop() {
    digitalWrite(PIN_FAN, HIGH);
    delay(1000);
}
