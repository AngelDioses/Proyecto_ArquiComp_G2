#ifndef XLCD_H
#define XLCD_H

#include <xc.h>
#include <libpic30.h>
#include "config.h"

// Definiciones de pines de control de LCD
#define RS_PIN LATBbits.LATB0
#define RW_PIN LATBbits.LATB1
#define E_PIN LATBbits.LATB2

#define LCD_DATA_PORT LATA
#define LCD_TRIS TRISA

void XLCDInit(void);
void WriteCmdXLCD(unsigned char);
void WriteDataXLCD(char);
void putsXLCD(const char *);
void XLCDgotoXY (char, char);
void DelayXLCD(void);

#endif /* XLCD_H */

