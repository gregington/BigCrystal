#include <LiquidCrystal_SR3W.h>
#include <LCDBitmap.h>
#include <BigCrystal.h>

// Set to your shift rgister pins
LiquidCrystal_SR3W lcd(2, 3, 4, 7, POSITIVE);
BigCrystal bigCrystal(&lcd);

void setup() {
  bigCrystal.begin(20, 4);
  
  bigCrystal.printBig("10:22", 0, 0);
}

void loop() {
}
