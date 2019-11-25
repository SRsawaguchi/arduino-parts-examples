/*
    LCDにHello worldを表示するプログラム。
*/

#include <Arduino.h>
#include <Wire.h> // Arduinoの拡張ライブラリを利用

#define LCD_I2C_ADDR (0x3e)
#define LCD_CONTRAST (28)

void setup() {
    lcd_init(LCD_CONTRAST);

    lcd_set_cursor(1, 0);
    lcd_print("Hello,");

    lcd_set_cursor(2, 1);
    lcd_print("World!");
}

void loop() {
    delay(5000);
}

// i2cでLCDにコマンドを送る。
void lcd_cmd(byte cmd) {
    Wire.beginTransmission(LCD_I2C_ADDR);
    Wire.write(0x00);
    Wire.write(cmd);
    Wire.endTransmission();
}

// i2cでLCDにデータを送る。
void lcd_data(byte data) {
    Wire.beginTransmission(LCD_I2C_ADDR);
    Wire.write(0x40);
    Wire.write(data);
    Wire.endTransmission();
}

// lcdに文字を表示する。
void lcd_print(const char *s) {
    while(*s) lcd_data(*s++);
}

// lcdのカーソルを設定する。
// lcd_printでは、ここで指定した場所から文字が印字される。
void lcd_set_cursor(byte col, byte row) {
    lcd_cmd(0x80 | (row * 0x40 + col));
    delayMicroseconds(27);
}

// http://akizukidenshi.com/download/ds/xiamen/AQM0802.pdf
// データシートに書かれた初期設定を行う関数。
void lcd_init(int contrast) {
    delay(40);
    Wire.begin();

    // function set
    lcd_cmd(0x38);
    delayMicroseconds(27);

    // function set
    lcd_cmd(0x39);
    delayMicroseconds(27);

    // function set
    lcd_cmd(0x14);
    delayMicroseconds(27);

    // contrast set
    lcd_cmd(0x70 | (contrast & 15));
    delayMicroseconds(27);

    // power/icon/contrast control
    lcd_cmd(0x5c | (contrast >> 4 & 3));
    delayMicroseconds(27);

    // follower control
    lcd_cmd(0x6c);
    delay(200);

    // function set
    lcd_cmd(0x38);
    delayMicroseconds(27);

    // display on/off control
    lcd_cmd(0x0c);
    delayMicroseconds(27);

    // clear display
    lcd_cmd(0x01);
    delay(2);
}
