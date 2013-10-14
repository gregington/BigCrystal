#include "BigFont.h"
#include "BigCrystal.h"

BigCrystal::BigCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
    uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
    uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) :
    LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) {
  init();
}

BigCrystal::BigCrystal(uint8_t rs, uint8_t enable,
    uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
    uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) :
    LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) {
  init();
}

BigCrystal::BigCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
    uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) :
    LiquidCrystal(rs, rw, enable, d0, d1, d2, d3) {
  init();
}

BigCrystal::BigCrystal(uint8_t rs,  uint8_t enable,
    uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) :
    LiquidCrystal(rs, enable, d0, d1, d2, d3) {
  init();
}

/* Creates custom font shapes for LCD characters 0 through to 7
 * used in displaying big fonts
 */
void BigCrystal::init() {
  for (uint8_t i = 0; i < 8; i++) {
    uint8_t customChar[8];
    for (uint8_t j = 0; j < 8; j++) {
      customChar[j] = pgm_read_byte(BF_fontShapes + (i * 8) + j);
    }
    createChar(i, customChar);
  }
}

uint8_t BigCrystal::widthBig(char c) {
  if (!supported(c)) {
    return 0; // we don't support characters outside this range
  }
  char ch = toUpperCase(c);

  uint8_t tableCode;
  uint8_t index;
  getTableCodeAndIndex(ch, tableCode, index);

  uint8_t width = getWidthFromTableCode(tableCode);
  if (width == 0) {
    return 0;
  }

  return width + 1; // add one for space after character
}

uint8_t BigCrystal::writeBig(char c, uint8_t col, uint8_t row) {
  if (!supported(c)) {
    return 0; // we don't support characters outside this range
  }
  char ch = toUpperCase(c);

  uint8_t tableCode;
  uint8_t index;
  getTableCodeAndIndex(ch, tableCode, index);

  uint8_t* table = getTable(tableCode);
  uint8_t width = getWidthFromTableCode(tableCode);

  int tableOffset = (width * 2) * index;

  // Write first row
  setCursor(col, row);
  for (uint8_t i = 0; i < width; i++) {
    write(pgm_read_byte_near(table + tableOffset + i));
  }

  // Write second row
  setCursor(col, row + 1);
  for (uint8_t i = 0; i < width; i++) {
    write(pgm_read_byte_near(table + tableOffset + width + i));
  }

  // Clear last column
  clearColumn(col + width, row);

  return width + 1; // add one for the cleared column
}

uint8_t BigCrystal::printBig(char *str, uint8_t col, uint8_t row) {
  uint8_t width = 0;
  char *c = str;
  while (*c != '\0') {
    width += writeBig(*c, col + width, row);
    *c++;
  }
  return width;
}

void BigCrystal::getTableCodeAndIndex(char c, uint8_t& tableCode, uint8_t& index) {
  uint8_t tableAndIndex = pgm_read_byte_near(BF_characters + c - ' ');
  // Top 3 bits are the table, bottom 5 are index into table
  tableCode = (uint8_t) ((tableAndIndex & 0xE0) >> 5);
  index = (uint8_t) (tableAndIndex & 0x1F);
}

uint8_t* BigCrystal::getTable(uint8_t tableCode) {
  switch (tableCode) {
    case BF_WIDTH1_TABLE:
      return BF_width1;
    case BF_WIDTH2_TABLE:
      return BF_width2;
    case BF_WIDTH3_TABLE:
      return BF_width3;
    case BF_WIDTH4_TABLE:
      return BF_width4;
    case BF_WIDTH5_TABLE:
      return BF_width5;
    case BF_WIDTH3_SYMBOLS_TABLE:
      return BF_width3Symbols;
    default:
      return NULL;
  }
}

uint8_t BigCrystal::getWidthFromTableCode(uint8_t tableCode) {
  if (tableCode == BF_WIDTH3_SYMBOLS_TABLE) {
    return 3;
  }
  return tableCode;
}

bool BigCrystal::supported(char c) {
  return (c >= ' ' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char BigCrystal::toUpperCase(char c) {
  if (c >= 'a' && c <= 'z') {
    return c &0x5f;
  }
  return  c;
}

void BigCrystal::clearColumn(uint8_t col, uint8_t row) {
  setCursor(col, row);
  write(0x20);
  setCursor(col, row + 1);
  write(0x20);
}
