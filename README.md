BigCrystal
==========

Arduino Library for displaying double height characters on an LCD display.

A corresponding library, [BigCrystalTWI](https://github.com/gregington/BigCrystalTWI)
is available to use if connecting the LCD using I<sup>2</sup>C.

Usage
-----

To use BigCrystal, the sketch will need the following includes:

    #include <LiquidCrystal.h>
    #include <BigCrystal.h>

Creating the LCD object is similar to the [LiquidCrystal library](https://github.com/Stephanie-Maks/Arduino-LiquidTWI);
the pin numbers on the Arduino that connect to the LCD need to be specified.
All constructors available in LiquidCrystal are available in BigCrystal. For example:

    BigCrystal lcd(22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);

The following methods, in addition to those in LiquidTWI are available:
* writeBig(char c, uint8_t row, uint8_t col) - writes a single large character to the specified coordinates.
* printBig(char* str, uint8_t row, uint8_t col) - writes a String to the specified coordinates.
* widthBig(char c) - returns the width in characters of the specified large character.
  Includes the one column space following the character.
