#include <LiquidCrystal_SR2W.h>
#include <BigCrystal.h>

// Change to your shift register pins
LiquidCrystal_SR2W lcd(2, 3); 
BigCrystal bigCrystal(&lcd);

void setup() {
  bigCrystal.begin(20, 4);
  
  bigCrystal.printBig("10:22", 0, 0);
}

void loop() {
}
