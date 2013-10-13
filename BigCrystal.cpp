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

void BigCrystal::init() {
  for (int i = 0; i < 8; i++) {
    uint8_t customChar[8];
    for (int j = 0; j < 8; j++) {
      customChar[j] = pgm_read_byte(gBigFontShapeTable + (i * 8) + j);
    }
    createChar(i, customChar);
  }
}

uint8_t BigCrystal::bigWidth(char c) {
  if (c == 0x20) {
    return(2);
  }	else if (c < 0x20) {
		return(0);
	}

  char ch = c & 0x5f; // Change to upper case

  if (ch == 'M' || ch == 'W') {
    return 6;
  } else if (ch == 'N' || ch == 'Q' || ch == 'V') {
    return 5;
  } else if (ch <= 'Z') {
    return 4;
  }
  return 0;
}

uint8_t BigCrystal::bigWrite(char c, uint8_t col, uint8_t row) {
  uint8_t width = bigWidth(c);
  if (width == 0) {
    // We can't print this character, so just return
    return width;
  }

  // Width includes spacing column, take this off to draw
  uint8_t charWidth = width - 1;

  char ch;
  if (c >= 'a' && c <= 'z') {
    ch = c & 0x5f;
  } else {
    ch = c;
  }

  // Work out if we have a special character and need to go to the special character index
  int specialIndex = getSpecialIndex(ch);

  if (specialIndex < 0) {
    bigWriteRegular(ch, col, row);
  } else {
    bigWriteSpecial(specialIndex, col, row, width);
  }
}

int8_t BigCrystal::getSpecialIndex(char c) {
  switch (c) {
    case 'M':
      return 0;
    case 'N':
      return 1;
    case 'Q':
      return 2;
    case 'V':
      return 3;
    case 'W':
      return 4;
    default:
      return -1;
  }
}

void BigCrystal::bigWriteRegular(char c, uint8_t col, uint8_t row) {
  int offset = 6 * (c - 0x20);

  // Write first row
  setCursor(col, row);
  for (int i = 0; i < 3; i++) {
    write(pgm_read_byte(gBigFontAsciiTable + offset + i));
  }

  // Write second row
  setCursor(col, row + 1);
  for (int i = 0; i < 3; i++) {
    write(pgm_read_byte(gBigFontAsciiTable + offset + 3 + i));
  }

  // Clear last row
  clearColumn(col + 3, row);
}

void BigCrystal::bigWriteSpecial(uint8_t index, uint8_t col, uint8_t row,
                                 uint8_t width) {
  Serial.println("bigWriteSpecial");
  int offset = 10 * index;

  // Write the first row
  setCursor(col, row);
  for (int i = 0; i < width; i++) {
    write(pgm_read_byte(gBigFontAsciiTableWide + offset + i));
  }

  // Write the second row
  setCursor(col, row + 1);
  for (int i = 0; i < width; i++) {
    write(pgm_read_byte(gBigFontAsciiTableWide + offset + 5 + i));
  }

  // Clear last row
  clearColumn(col + width - 1, row);
}

void BigCrystal::clearColumn(uint8_t col, uint8_t row) {
  setCursor(col, row);
  write(0x20);
  setCursor(col, row + 1);
  write(0x20);
}
