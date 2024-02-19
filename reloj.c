#include <xc.h>
#include <libpic30.h>
#include "reloj.h"
#include "config.h"
#include "xlcd.h"

void Configurar_Oscilador(void){
    OSCCONbits.NOSC = 0b001;
    CLKDIVbits.PLLPRE = 0;
    PLLFBD = 38;
    CLKDIVbits.PLLPOST = 0;

    while(!OSCCONbits.LOCK);
}
