#include "Alphabet.h"
#include "Letters.h"

int getLetterFromChar(char c)
{
  if (c >= 32 && c <= 126)
  {
    return c - 32;
  }
  return 95;
}

void printWord(char *phrase)
{
  int spacing = 6;
  int initShift = -8;
  unsigned char shiftedByte = B00000000;
  int addition = 0;

  for (int shift = initShift; shift + abs(initShift) < strlen(phrase) * spacing + 3 + abs(initShift); shift++)
  {
    for (int row = 7; row >= 0; row--)
    {
      for (int letter = 0; letter < strlen(phrase); letter++)
      {
        addition = shift - (letter * spacing);
        if (addition < -8 || addition > 8)
        {
          continue;
        }
        if (addition < 0)
        {
          shiftedByte |= alphabet[getLetterFromChar(phrase[letter])][row] >> abs(addition);
        }
        else
        {
          shiftedByte |= alphabet[getLetterFromChar(phrase[letter])][row] << addition;
        }
      }
      lc.setColumn(0, row, (shiftedByte * 0x0202020202ULL & 0x010884422010ULL) % 1023);
      shiftedByte = B00000000;
    }
    delay(delaytime);
  }
}

void printSymbol(int num_symbol)
{
  int spacing = 6;
  int initShift = -8;
  unsigned char shiftedByte = B00000000;
  int addition = 0;

  for (int shift = initShift; shift + abs(initShift) < spacing + 9 + abs(initShift); shift++)
  {
    for (int row = 7; row >= 0; row--)
    {
      addition = shift - spacing;
      if (addition < -8 || addition > 8)
      {
        continue;
      }
      if (addition < 0)
      {
        shiftedByte |= symbols[num_symbol][row] >> abs(addition);
      }
      else
      {
        shiftedByte |= symbols[num_symbol][row] << addition;
      }
      
      lc.setColumn(0, row, (shiftedByte * 0x0202020202ULL & 0x010884422010ULL) % 1023);
      shiftedByte = B00000000;
    }
    delay(delaytime);
  }
}

void printZodiac(int num_symbol)
{
  int spacing = 6;
  int initShift = -8;
  unsigned char shiftedByte = B00000000;
  int addition = 0;

  for (int shift = initShift; shift + abs(initShift) < spacing + 9 + abs(initShift); shift++)
  {
    for (int row = 7; row >= 0; row--)
    {
      addition = shift - spacing;
      if (addition < -8 || addition > 8)
      {
        continue;
      }
      if (addition < 0)
      {
        shiftedByte |= zodiac[num_symbol][row] >> abs(addition);
      }
      else
      {
        shiftedByte |= zodiac[num_symbol][row] << addition;
      }
      
      lc.setColumn(0, row, (shiftedByte * 0x0202020202ULL & 0x010884422010ULL) % 1023);
      shiftedByte = B00000000;
    }
    delay(delaytime);
  }
}

void printSymbols(char *symbolList)
{
  int spacing = 6;
  int initShift = -8;
  unsigned char shiftedByte = B00000000;
  int addition = 0;

  for (int shift = initShift; shift + abs(initShift) < strlen(symbolList) * spacing + 3 + abs(initShift); shift++)
  {
    for (int row = 7; row >= 0; row--)
    {
      for (int numSymbol = 0; numSymbol < strlen(symbolList); numSymbol++)
      {
        addition = shift - (numSymbol * spacing);
        if (addition < -8 || addition > 8)
        {
          continue;
        }
        if (addition < 0)
        {
          shiftedByte |= zodiac[numSymbol][row] >> abs(addition);
        }
        else
        {
          shiftedByte |= zodiac[numSymbol][row] << addition;
        }
      }
      lc.setColumn(0, row, (shiftedByte * 0x0202020202ULL & 0x010884422010ULL) % 1023);
      shiftedByte = B00000000;
    }
    delay(delaytime);
  }
}
