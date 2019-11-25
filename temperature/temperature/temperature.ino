/*
  温度センサの値をArduino IDEのシリアルモニタに送信して表示するサンプルプログラム。
  ※配線を間違えると温度センサが高温状態となり、破損する恐れがある。データシートをよく確認すること。

*/

#include <Arduino.h>

#define PIN_TEMPERATURE (A0)

void setup() {
    Serial.begin(9600);
}

void loop() {
    int v_out = analogRead(PIN_TEMPERATURE);
    float celsius = 100 * 5 * v_out / 1024;
    Serial.print(celsius);
    Serial.println("");
    delay(1000);
}
