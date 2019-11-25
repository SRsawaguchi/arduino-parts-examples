/*
   cdsの値をArduino IDEのシリアルモニタに送信して表示するサンプルプログラム。
*/

#include <Arduino.h>

#define PIN_CDS (A0)

void setup() {
    Serial.begin(9600);
}

void loop() {
    int val = analogRead(PIN_CDS);
    Serial.println(val);
    delay(1000);
}
