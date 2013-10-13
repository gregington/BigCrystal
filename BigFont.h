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


extern uint8_t	gBigFontShapeTable[64] PROGMEM;

extern uint8_t	gBigFontAsciiTable[354] PROGMEM;

extern uint8_t	gBigFontAsciiTableWide[50] PROGMEM;
#endif