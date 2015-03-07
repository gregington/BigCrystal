#ifndef BigCrystal_h
#define BigCrystal_h

#include "BigFont.h"
#include <Print.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include <LiquidCrystal.h>
#ifndef LiquidCrystal_h // Using the new LiquidCrystal library
  #ifdef LiquidCrystal_4bit_h || LiquidCrystal_I2C_h || _LIQUIDCRYSTAL_SR_ || _LIQUIDCRYSTAL_SR2W_ || _LIQUIDCRYSTAL_SR3W_H_ // Using the New LiquidCrystal library
    #include "LCD.h"
  #else
    #error You must install New LiquidCrystal library to work with non-4bit projects: http:/bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
  #endif
#endif


/* Class that displays text on a Hitachi HD44780 compatible display. As well
 * as displaying standard text, doubli height characters can also be displayed.
 */
class BigCrystal : public Print {
public:
  /* Creates a BigCrystal instance.
   * Parameters:
   *       lcd: A LiquidCrystal or LCD instance.
   */
#ifndef LiquidCrystal_h // New liquid crystal library
  BigCrystal(LCD *display);
#else
  BigCrystal(LiquidCrystal *display);
#endif
  BigCrystal(uint8_t rs, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

  /* Returns the width in columns of the specified character.
   * If the character cannot be printed big, then zero is returned.
   * Parameters:
   *   c: the character whose width is required
   * Returns:
   *   the width of the character, including the empty spacer column,
   *   or zero if the character cannot be displayed.
   */
  uint8_t widthBig(char c);

  /* Writes the specified character to the coordinate specified on the display.
   * Parameters:
   *     c: the character to display
   *   col: the column on the display where the left edge of the character starts
   *   row: the row on the display where the top of the character starts
   * Returns:
   *   the width of the character displayed, including the empty spacer column,
   *   or zero if the character cannot be displayed.
   */
  uint8_t writeBig(char c, uint8_t col, uint8_t row);

  /* Writes the specified string from left to right, starting at the specified
   * display coordinate. No bounds checks are made to ensure that the string
   * will fit on the display. On a four line or greater display, characters will
   * not wrap onto lower display rows.
   * Parameters:
   *    str: the String to display
   *    col: the column on the display where the left edge of the first character
   *         starts
   *    row: the row on the display where the top edge of characters start
   * Returns:
   *   the total width of all printed characters, including all empty spacer columns
   */
  uint8_t printBig(char *str, uint8_t col, uint8_t row);

  /* Delegate methods to underlying LCD instance */
  inline void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS) {
    _display->begin(cols, rows, charsize);
  }
  inline void clear() { _display->clear(); }
  inline void home() { _display->home(); }
  inline void noDisplay() { _display->noDisplay(); }
  inline void display() { _display->display(); }
  inline void noBlink() { _display->noBlink(); }
  inline void blink() { _display->blink(); }
  inline void noCursor() { _display->noCursor(); }
  inline void cursor() { _display->cursor(); }
  inline void scrollDisplayLeft() { _display->scrollDisplayLeft(); }
  inline void scrollDisplayRight() { _display->scrollDisplayRight(); }
  inline void leftToRight() { _display->leftToRight(); }
  inline void rightToLeft() { _display->rightToLeft(); }
  inline void autoscroll() { _display->autoscroll(); }
  inline void noAutoscroll() { _display->noAutoscroll(); }
  inline void createChar(uint8_t location, uint8_t charmap[]) { _display->createChar(location, charmap); }
  inline void setCursor(uint8_t col, uint8_t row) { _display->setCursor(col, row); }
  inline virtual size_t write(uint8_t value) { _display->write(value); }

  using Print::write;
private:
  void createCustomChars();
  uint8_t getWidthFromTableCode(uint8_t tableCode);
  const uint8_t* getTable(uint8_t tableCode);
  void getTableCodeAndIndex(char c, uint8_t &tableCode, uint8_t &index);
  void clearColumn(uint8_t row, uint8_t col);
  char toUpperCase(char c);
  bool supported(char c);
#ifndef LiquidCrystal_h // Using New LquidCrystal library
  LCD *_display;
#else
  LiquidCrystal *_display;
#endif

};
#endif
