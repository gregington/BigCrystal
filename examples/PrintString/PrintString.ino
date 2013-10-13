#include <BigCrystal.h>
#include <LiquidCrystal.h>

// Set up according to your LCD pins
BigCrystal lcd(22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);

void setup() {
  lcd.begin(20, 4);

  lcd.printBig("10:22", 0, 0);
}

void loop() {
}
