/*
    ジャイロセンサの値をシリアルモニタに表示するプログラム。
*/

#include <Arduino.h>

#define PIN_X A0
#define PIN_Y A1
#define PIN_Z A2

typedef struct {
  int x;
  int y;
  int z;
} Point;

void gyro_get(Point *out) {
  out->x = analogRead(PIN_X);
  out->y = analogRead(PIN_Y);
  out->z = analogRead(PIN_Z);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Point p;
  gyro_get(&p);

  Serial.print("x = ");
  Serial.print(p.x);
  Serial.print(", y = ");
  Serial.print(p.y);
  Serial.print(", z = ");
  Serial.print(p.z);
  Serial.println("");
  delay(1000);
}
