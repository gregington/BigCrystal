#include <BigCrystal.h>
#include <LiquidCrystal.h>

// Set up according to your LCD pins
LiquidCrystal lcd(22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);
BigCrystal bigCrystal(&lcd);

void setup() {
  bigCrystal.begin(20, 4); // Set to your LCD size
}

void loop() {
  // Displays all characters is big front from 0x00 (space) to 0x5A (Z)
  for (char c = 0x20; c <= 0x5A; c++) {
    // Clear out the maximum width so that pars of wider
    // characters are removed
    clear();

    bigCrystal.writeBig(c, 0, 0);
    bigCrystal.setCursor(7, 0);
    bigCrystal.write(c);
    delay(1000);
  }
}

void clear() {
  for (int i = 0; i < 5; i++) {
    bigCrystal.setCursor(i, 0);
    bigCrystal.print(' ');
    bigCrystal.setCursor(i, 1);
    bigCrystal.print(' ');
  }
}
