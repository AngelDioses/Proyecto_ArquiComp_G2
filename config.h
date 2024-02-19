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

#define ANSELAbits (*((volatile unsigned char*)(&ANSELAbits)))
#define ANSELBbits (*((volatile unsigned char*)(&ANSELBbits)))

void Configurar_Puertos(void);
int LeerDipSwitch(void);

#endif /* CONFIG_H */

