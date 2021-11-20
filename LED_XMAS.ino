#include "Alphabet.h"
# include "Letters.h"

unsigned long delaytime = 50;
LedControl lc = LedControl(12, 11, 10, 1);
/* pin 12 is connected to the DataIn ; pin 11 is connected to the CLK ; pin 10 is connected to LOAD */
//SoftwareSerial ESP8266(8, 9);

void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 0.1);
  lc.clearDisplay(0);
}

void loop()
{         
    /*char phrase[] = "MERRY Christmas !";
    printWord(phrase);*/
    //printSymbol(0); printSymbol(1);
    /*int i;
    for (i=0; i<12; i++)
    {
      printZodiac(i);
    }*/
    char symbolList[] = {zodiac[1], zodiac[3], zodiac[8]};
    printSymbols(symbolList);
}
