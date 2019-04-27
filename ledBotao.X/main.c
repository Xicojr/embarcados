#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    TRISA = 0b00000000;
    TRISB = 0b00000001;
    PORTA =0;
  /*
    while (1){
        if(RB0 == 0)
            RA0 = 1;
        else
            RA0 =0;
    }
*/
    int estado = 0;
    
    while(1){
        if(estado == 0){
            if(RB0 == 0){
                __delay_ms(500);
                RA1 = 1;
                __delay_ms(250);
                estado = 1;
            }
        }
        if(estado == 1){
            if(RB0 == 0){
                __delay_ms(500);
                RA0 = 1;
                __delay_ms(250);
                estado = 2;
            }
        }
        
        if(estado == 2){
            if(RB0 == 0){
                __delay_ms(500);
                RA1 = 0;
                RA0 = 0;
                __delay_ms(250);
                estado = 0;
            }
        }
    }
    
 }
