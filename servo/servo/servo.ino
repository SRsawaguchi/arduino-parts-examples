/*
    サーボモータを一定時間おきに動作させるプログラム。
*/

#include <Arduino.h>
#include <Servo.h>

#define PIN_SERVO 3
#define DURATION 1500

Servo servo;

void setup() {
  servo.attach(PIN_SERVO);
  servo.write(0);
}

int points[] = {0, 45, 90, 135, 165}; //180にすると止まらなかった。
int len = sizeof(points) / sizeof(int);
void loop() {
  int i;
  for (i=0; i<len; i++) {
    servo.write(points[i]);
    delay(DURATION);
  }

  for (i=len-2; i>0; i--) {
    servo.write(points[i]);
    delay(DURATION);
  }
}
