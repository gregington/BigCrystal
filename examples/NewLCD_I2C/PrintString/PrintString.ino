#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BigCrystal.h>

// Set up according to your LCD pins
LiquidCrystal_I2C lcd(0x38);  // Set the LCD I2C address
BigCrystal bigCrystal(&lcd);

void setup() {
  bigCrystal.begin(20, 4);
  
  bigCrystal.printBig("10:22", 0, 0);
}

void loop() {
}
