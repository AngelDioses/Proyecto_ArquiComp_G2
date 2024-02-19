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

#define TRISB0 TRISBbits.TRISB0
#define TRISB1 TRISBbits.TRISB1
#define TRISB2 TRISBbits.TRISB2
#define TRISB3 TRISBbits.TRISB3
#define TRISB4 TRISBbits.TRISB4
#define TRISB5 TRISBbits.TRISB5
#define TRISB6 TRISBbits.TRISB6
#define TRISB7 TRISBbits.TRISB7
#define TRISB8 TRISBbits.TRISB8

void XLCDInit(void);
void WriteCmdXLCD(unsigned char);
void WriteDataXLCD(char);
void putsXLCD(const char *);
void XLCDgotoXY (char, char);
void DelayXLCD(void);

#endif /* XLCD_H */

