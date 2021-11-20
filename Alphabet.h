#ifndef _ALPHABET_H_
# define _ALPHABET_H_

# include <stdlib.h>
# include <string.h>
# include "Arduino.h"
# include "LedControl.h"

int getLetterFromChar(char);
void printWord(char *);
void printSymbol(int num_symbol);
void printZodiac(int num_symbol);
void printSymbols(char *symbolList);

extern unsigned long delaytime;
extern LedControl lc;

#endif /* !_ALPHABET_H_ */
