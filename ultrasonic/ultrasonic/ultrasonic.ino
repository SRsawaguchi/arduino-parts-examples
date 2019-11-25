/*
    超音波距離センサの値をArduino IDEのシリアルモニタに送信して表示するサンプルプログラム。
*/

#include <Arduino.h>

#define PIN_TRIG (13)
#define PIN_ECHO (8)

typedef struct {
    int cm;
    int inches;
} Distance;

Distance dist;

void setup() {
    pinMode(PIN_TRIG, OUTPUT);
    digitalWrite(PIN_TRIG, LOW);
    Serial.begin(9600);
}

void loop() {
    measure(&dist);

    Serial.print(dist.cm);
    Serial.print("cm (");
    Serial.print(dist.inches);
    Serial.print("inch)\n");

    delay(1000);
}

// 公式で公開されているプログラムを参照。
// https://codebender.cc/sketch:356078#HC-SR04%20Ultrasonic%20Sensor%20Example.ino
unsigned long measure(Distance *d) {
    unsigned long t1;
    unsigned long t2;
    unsigned long pulse_width;

    // Hold the trigger pin high for at least 10 us
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    // Wait for pulse on echo pin
    while ( digitalRead(PIN_ECHO) == 0 );

    // Measure how long the echo pin was held high (pulse width)
    // Note: the micros() counter will overflow after ~70 min
    t1 = micros();
    while ( digitalRead(PIN_ECHO) == 1);
    t2 = micros();
    pulse_width = t2 - t1;

    // Calculate distance in centimeters and inches. The constants
    // are found in the datasheet, and calculated from the assumed speed 
    //of sound in air at sea level (~340 m/s).
    d->cm = pulse_width / 58.0;
    d->inches = pulse_width / 148.0;

    return pulse_width;
}

