#include <LiquidCrystal_SR.h>
#include <LCDBitmap.h>
#include <BigCrystal.h>

// Set up according to your shift register pins
LiquidCrystal_SR lcd(8, 7, TWO_WIRE); 
BigCrystal bigCrystal(&lcd);

void setup() {
  bigCrystal.begin(20, 4);
  
  bigCrystal.printBig("10:22", 0, 0);
}

void loop() {
}
