#include <BigCrystal.h>
#include <LiquidCrystal.h>

// Set up according to your LCD pins
LiquidCrystal lcd(22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);
BigCrystal bigCrystal(&lcd);

void setup() {
  bigCrystal.begin(20, 4);
  
  bigCrystal.printBig("10:22", 0, 0);
}

void loop() {
}
