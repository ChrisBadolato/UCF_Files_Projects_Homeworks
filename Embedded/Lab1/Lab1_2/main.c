//  Christopher Badolato
//  9/9/20
//  EEL 4742L-0011

#include <msp430.h>
#include <stdint.h>
#define redLED BIT0
#define greenLED BIT7 //BIT 6 because 1.6!!!!

/**
 * main.c
 */
int main(void){
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    volatile unsigned int i;
    volatile unsigned int j;

    PM5CTL0 &= ~LOCKLPM5; // Disable GPIO power-on default high impedance mode

    P1DIR |= redLED; // Direct pin as output
    P1OUT &= ~redLED; // Turn LED Off

    P9DIR |= greenLED; // Direct pin as output
    P9OUT &= ~greenLED; // turn green LED off
        //Toggle Red LED
        //Have the green LED toggle twice before the RED toggles.
    for(;;) {
        P1OUT ^= redLED;
        for(j = 0; j < 2; j++){
            for(i = 0; i<20000; i++) {}
                //Toggle the green LED
            P9OUT ^= greenLED;
        }
    }
}


