#ifndef BigCrystal_h
#define BigCrystal_h

#include "BigCrystal.h"
#include "BigFont.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

class BigCrystal : public LiquidCrystal {
public:
  BigCrystal(uint8_t rs, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
  BigCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
  BigCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
  BigCrystal(uint8_t rs, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

  uint8_t widthBig(char c);
  uint8_t writeBig(char c, uint8_t col, uint8_t row);
private:
  void init();
  uint8_t getWidthFromTableCode(uint8_t tableCode);
  uint8_t* getTable(uint8_t tableCode);
  void getTableCodeAndIndex(char c, uint8_t &tableCode, uint8_t &index);
  void clearColumn(uint8_t row, uint8_t col);
  char toUpperCase(char c);
  bool supported(char c);
};
#endif
