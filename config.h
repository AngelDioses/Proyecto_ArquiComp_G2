#ifndef CONFIG_H
#define CONFIG_H

#include <xc.h>
#include <libpic30.h>
#include <p33FJ32MC204.h>

#define FOSC 8000000L
#define FCY (FOSC/2)

#define BAUDRATE 9600
#define BRGVAL ((FCY/BAUDRATE)/16) - 1

#define DEBUG 0

// Definiciones de pines LCD
#define RS_PIN LATABITS.LATA0
#define RW_PIN LATABITS.LATA1
#define E_PIN LATABITS.LATA2

#define TRISD_VALUE 0x0000
#define TRISF_VALUE 0x0000

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
#define TRISB9 TRISBbits.TRISB9 // Para dipswitch 1
#define TRISB10 TRISBbits.TRISB10 // Para dipswitch 2
#define TRISB11 TRISBbits.TRISB11 // Para dipswitch 3
#define TRISB12 TRISBbits.TRISB12 // Para dipswitch 4

#define ANSELAbits (*((volatile unsigned char*)(&ANSELAbits)))
#define ANSELBbits (*((volatile unsigned char*)(&ANSELBbits)))

void Configurar_Puertos(void);
int LeerDipSwitch(void);

#endif /* CONFIG_H */

