#include <xc.h>
#include <libpic30.h>
#include "config.h"
#include "xlcd.h"

#define __delay_ms;
#define __delay_us;

void XLCDInit(void) {
    LCD_TRIS = 0; // Configurar todo el puerto como salida
    RS_PIN = 0; // RS_PIN como salida
    RW_PIN = 0; // RW_PIN como salida
    E_PIN = 0;  // E_PIN como salida
    
    WriteCmdXLCD(0b00110000);
    __delay_ms(5);
    WriteCmdXLCD(0b00110000);
    __delay_us(100);
    WriteCmdXLCD(0b00110000);
    __delay_us(40);
    WriteCmdXLCD(0b00111000);
    __delay_us(40);
    WriteCmdXLCD(0b00001100);
    __delay_us(40);
    WriteCmdXLCD(0b00000110);
    __delay_us(40);
    WriteCmdXLCD(0b00000001);
    __delay_ms(2);
}

void WriteCmdXLCD(unsigned char cmd) {
    RS_PIN = 0;
    RW_PIN = 0; // Si es escritura, RW_PIN debe ser cero
    LCD_DATA_PORT = cmd;
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    DelayXLCD();
}

void WriteDataXLCD(char data) {
    RS_PIN = 1;
    RW_PIN = 0; // Si es escritura, RW_PIN debe ser cero
    LCD_DATA_PORT = data;
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    DelayXLCD();
}

void putsXLCD(const char *data) {
    while(*data) {
        WriteDataXLCD(*data++);
    }
}

void XLCDgotoXY (char x, char y) {
    char address;
    if (y != 1) {
        address = 0x40;
    } else {
        address = 0;
    }
    address += x - 1;
    WriteCmdXLCD(0x80 | address);
}

void DelayXLCD(void) {
    __delay_us(100);
}

