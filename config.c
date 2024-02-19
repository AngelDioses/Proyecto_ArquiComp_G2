#include <xc.h>
#include <libpic30.h>
#include "config.h"
#include "reloj.h"
#include "xlcd.h"


void Configurar_Puertos(void) {
    
    TRISA = 0xFFFF; // Configura todo el puerto A como entrada
    TRISB = 0xFFF0; // Configura RB0 a RB3 como entrada (Dip Switches), el resto como salida
    
    int LeerDipSwitch(void) {
    return (PORTB & 0x0F); // Leer los primeros 4 bits de PORTB donde están los Dip Switches

    }
}
