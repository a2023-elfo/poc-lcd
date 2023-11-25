#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(2, 0);
  lcd.print("Hello, ELFO!");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);

  // print the number of seconds since reset:

  lcd.print(millis() / 1000);
}
