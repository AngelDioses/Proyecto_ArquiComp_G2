#include <xc.h>
#include <stdio.h>
#include <libpic30.h>
#include <math.h>
#include "config.h"
#include "xlcd.h"
#include "reloj.h"

// Definición de constantes para la calibración de los sensores
#define LM35_VCC 5.0 // Voltaje de alimentación del LM35
#define LM35_ADC_MAX 1023 // Valor máximo del ADC (10 bits)
#define LM35_TEMPERATURE_MAX 100.0 // Temperatura máxima en grados Celsius

// Definición de constantes para la comunicación UART
#define UART_BUFFER_SIZE 50 // Tamaño del búfer UART

#define __delay_ms;

// Variables globales
char uart_buffer[UART_BUFFER_SIZE];

void UART_Init(void);
void ADC_Init(void);
void Delay1Sec(void);
void MeasureAndDisplayValues(void);
float ConvertADCToTemperature(int adc_value);
void ProcessDipSwitch(int dip_switch_state);


void Delay1Sec(void) {
    __delay_ms(1000); 
}

int main(void) {
    Configurar_Puertos();
    Configurar_Oscilador();
    XLCDInit();
    UART_Init();
    ADC_Init();
    
    while(1) {
        // Leer el valor del dip switch
        int dip_switch_value = PORTB & 0x0F;
        
        // Procesar el valor del dip switch
        ProcessDipSwitch(dip_switch_value);
        
        // Retardo de 1 segundo
        Delay1Sec();
    }
    return 0;
}

void UART_Init(void){
    // Configurar pines para comunicación UART
    TRISAbits.TRISA8 = 0; // TX como salida
    TRISAbits.TRISA7 = 1; // RX como entrada

    // Configurar velocidad de transmisión
    U1BRG = BRGVAL;
    
    // Habilitar módulo UART
    U1MODEbits.UARTEN = 1;
    
    // Habilitar transmisor UART
    U1STAbits.UTXEN = 1;
}

void ADC_Init(void){
    // Configurar pines para entrada analógica
    ADPCFG = 0xFFF;
    
    // Configurar ADC
    AD1CON1bits.FORM = 0;
    AD1CON1bits.SSRC = 0b111;
    AD1CON1bits.ASAM = 1;
    AD1CON2 = 0;
    AD1CON3bits.ADRC = 0;
    AD1CON3bits.ADCS = 0b111111;
    AD1CHS123 = 0;
    AD1CON1bits.ADON = 1;
}

void MeasureAndDisplayValues(void) {
    float temperature_celsius;
    int adc_value;
    
    // Medir temperatura con LM35
    adc_value = ADC1BUF0;
    temperature_celsius = ConvertADCToTemperature(adc_value);
    
    // Mostrar temperatura en LCD
    XLCDgotoXY(1, 0);
    sprintf(uart_buffer, "%.2f C", temperature_celsius);
    putsXLCD(uart_buffer);
    
    // Enviar temperatura por UART
    sprintf(uart_buffer, "%.2f C\n", temperature_celsius);
    putsXLCD(uart_buffer);
}

float ConvertADCToTemperature(int adc_value) {
    float voltage;
    float temperature_celsius;
    
    // Calcular voltaje a partir del valor del ADC
    voltage = (adc_value * LM35_VCC) / LM35_ADC_MAX;
    
    // Calcular temperatura a partir del voltaje
    temperature_celsius = (voltage / 10.0) * LM35_TEMPERATURE_MAX;
    
    return temperature_celsius;
}

void ProcessDipSwitch(int dip_switch_value) {
    switch(dip_switch_value) {
        case 1:
            ProcessDipSwitch1();
            break;
        case 2:
            ProcessDipSwitch2();
            break;
        case 3:
            ProcessDipSwitch3();
            break;
        case 4:
            ProcessDipSwitch4();
            break;
        default:
            ProcessNoDipSwitchActivated();
            break;
    }
}


void ProcessDipSwitch1(void) {
    // Lógica para procesar el primer dip switch (Ruido)
    // Aquí puedes leer el valor del sensor de sonido y mostrarlo en el LCD, enviarlo por UART, etc.
    float sound_level; // Variable para almacenar el nivel de sonido
    // Código para leer el sensor de sonido y guardar el valor en sound_level
    XLCDgotoXY(1, 0);
    sprintf(uart_buffer, "Ruido: %.2f", sound_level);
    putsXLCD(uart_buffer);
    // Aquí podrías enviar sound_level por UART si es necesario
}

void ProcessDipSwitch2(void) {
    // Lógica para procesar el segundo dip switch (Temperatura)
    // Aquí puedes leer el valor del sensor de temperatura y mostrarlo en el LCD, enviarlo por UART, etc.
    float temperature_celsius; // Variable para almacenar la temperatura en grados Celsius
    // Código para leer el sensor de temperatura y guardar el valor en temperature_celsius
    XLCDgotoXY(1, 0);
    sprintf(uart_buffer, "Temperatura: %.2f C", temperature_celsius);
    putsXLCD(uart_buffer);
    // Aquí podrías enviar temperature_celsius por UART si es necesario
}

void ProcessDipSwitch3(void) {
    // Lógica para procesar el tercer dip switch (Luz)
    // Aquí puedes leer el valor del sensor de luz y mostrarlo en el LCD, enviarlo por UART, etc.
    int light_intensity; // Variable para almacenar la intensidad de luz
    // Código para leer el sensor de luz y guardar el valor en light_intensity
    XLCDgotoXY(1, 0);
    sprintf(uart_buffer, "Luz: %d", light_intensity);
    putsXLCD(uart_buffer);
    // Aquí podrías enviar light_intensity por UART si es necesario
}

void ProcessDipSwitch4(void) {
    // Lógica para procesar el cuarto dip switch (Calidad de aire)
    // Aquí puedes leer el valor del sensor de calidad de aire y mostrarlo en el LCD, enviarlo por UART, etc.
    int air_quality; // Variable para almacenar la calidad de aire
    // Código para leer el sensor de calidad de aire y guardar el valor en air_quality
    XLCDgotoXY(1, 0);
    sprintf(uart_buffer, "Calidad de aire: %d", air_quality);
    putsXLCD(uart_buffer);
    // Aquí podrías enviar air_quality por UART si es necesario
}

void ProcessNoDipSwitchActivated(void) {
    // Mensaje de "GRUPO 2" cuando no se haya activado ningún dip switch
    XLCDgotoXY(1, 0);
    putsXLCD("GRUPO 2");
}
