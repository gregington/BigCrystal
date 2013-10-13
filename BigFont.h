#ifndef BigFont_h
#define BigFont_h

#include <Arduino.h>

//************************************************************************
//*	A set of custom made large numbers for a 16x2 LCD using the
//*	LiquidCrystal librabry. Works with displays compatible with the
//*	Hitachi HD44780 driver.
//*
//*	orginal developed  by Michael Pilcher  2/9/2010
//*	there are 8 entries, 8 bytes per entry
//*	these are the building blocks to make the numbers
//*
//*	http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1265696343
//************************************************************************

#define BF_NOT_SUPPORTED 0
#define BF_WIDTH1_TABLE 0x01
#define BF_WIDTH2_TABLE 0x02
#define BF_WIDTH3_TABLE 0x03
#define BF_WIDTH4_TABLE 0x04
#define BF_WIDTH5_TABLE 0x05
#define BF_WIDTH3_SYMBOLS_TABLE 0x06

extern uint8_t BF_fontShapes[64] PROGMEM;
extern uint8_t BF_characters[59] PROGMEM;
extern uint8_t BF_width1[18] PROGMEM;
extern uint8_t BF_width2[8] PROGMEM;
extern uint8_t BF_width3[180] PROGMEM;
extern uint8_t BF_width3Symbols[18] PROGMEM;
extern uint8_t BF_width4[24] PROGMEM;
extern uint8_t BF_width5[20] PROGMEM;

#endif
