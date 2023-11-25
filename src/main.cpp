#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String* _plantName = 0;
float* _soilMoisture = 0;
float* _readSoilMoisture = 0;

int plantIndex = 0;

String plants[] = {"Marguerite", "Pissenlit", "Cactus", "Bambou"};
float moisture[] = {74.5, 20.76, 5, 101.5};
float readMoisture[] = {8, 42.43, 53, 342};


// Function to display the percentage on the second line, starting at the offset
void displayPercentage(int start, int percentage) {
  lcd.setCursor(start, 1);

  if (percentage > 100) {
    percentage = 100;
  } else if (percentage < 0) {
    percentage = 0;
  }

  if (percentage < 10) {
    lcd.print(" ");
  }
  if (percentage < 100) {
    lcd.print(" ");
  }
  lcd.print(percentage);
  lcd.print("%");
}

void updateScreen() {
  // Wipe LCD to start fresh
  lcd.clear();

  // Get plantName length to center in the display
  int spaces = (16 - _plantName->length()) / 2;
  Serial.println(spaces);
  lcd.setCursor(spaces, 0);
  lcd.print(*_plantName);

  // Display expected soil moisture
  lcd.setCursor(0, 1);
  lcd.print("A:");
  displayPercentage(2, (int) *_soilMoisture);

  // Display read soil moisture
  lcd.setCursor(10, 1);
  lcd.print("L:");
  displayPercentage(12, (int) *_readSoilMoisture);


}

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(2, 0);
  lcd.print("Hello, ELFO!");
  delay(2000);
}

void loop() {
  _plantName = &plants[plantIndex%4];
  _soilMoisture = &moisture[plantIndex%4];
  _readSoilMoisture = &readMoisture[plantIndex%4];
  Serial.println(*_plantName);
  updateScreen();
  delay(2000);
  plantIndex++;
}


