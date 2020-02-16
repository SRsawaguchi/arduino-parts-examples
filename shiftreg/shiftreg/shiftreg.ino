/*
    シフトレジスタのサンプル
    data[]配列の内容に合わせてLEDが点灯する。
    使ったシフトレジスタ：U74HC595AG-D16-T
*/

#include <Arduino.h>
#define PIN_SRCLK 5
#define PIN_RCLK  6
#define PIN_SER   7

void setup() {
  pinMode(PIN_SRCLK, OUTPUT);
  pinMode(PIN_RCLK , OUTPUT);
  pinMode(PIN_SER  , OUTPUT);
}

void shiftreg_write(byte data) {
  for (int i = 0; i < 8; i++) {
    if ((data >> i) & 0x01) {
      digitalWrite(PIN_SER, HIGH);
    } else {
      digitalWrite(PIN_SER, LOW);
    }
    digitalWrite(PIN_SRCLK, LOW);
    digitalWrite(PIN_SRCLK, HIGH);
  }
  digitalWrite(PIN_RCLK, LOW);
  digitalWrite(PIN_RCLK, HIGH);
}

byte data[] = {
  0b11000000,
  0b00110000,
  0b00001000,
  0b00000100,
  0b00000010,
  0b00000001,
};
int len = sizeof(data) / sizeof(byte);
void loop() {
  for (int i = 0; i< len; i++) {
    shiftreg_write(data[i]);
    delay(300);
  }
}
