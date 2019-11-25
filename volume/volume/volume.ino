/*
    1秒おきにボリュームの値をArduino IDEのシリアルモニタに送信して表示するサンプルプログラム。
*/

#include <Arduino.h>

#define PIN_VOLUME (A0)

void setup() {
  Serial.begin(9600);
}

void loop() {
    int val = analogRead(PIN_VOLUME);
    Serial.println(val);
    delay(1000);
}
