#include <msp430.h>
#include <stdint.h>
#define redLED BIT0
#define greenLED BIT6 //BIT 6 because 1.6!!!!
#define bBoard BIT5
#define bBoardgrey BIT4


/**
 * main.c
 */
int main(void){
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	volatile unsigned int i;
	volatile unsigned int j;
	volatile  uint32_t k;

	//PM5CTL0 &= ~LOCKLPM5; // Disable GPIO power-on default high impedance mode

	P1DIR |= redLED; // Direct pin as output
	P1OUT &= ~redLED; // Turn LED Off

	P1DIR |= greenLED; // Direct pin as output
    P1OUT &= ~greenLED;


    P1DIR |= bBoard; // Direct pin as output
    P1OUT &= ~bBoard;

    P1DIR |= bBoardgrey; // Direct pin as output
    P1OUT &= bBoardgrey; //Turn LED on initially



	for(;;) {
	        //if we leave this line up here the lights will toggle back and fourth.
            //P1OUT ^= redLED;
	        // Delay loop
	        //Red light will flash twice(incease outer loop to increase reds before greens.) before the green flashes
	    for(i=0; i<2; i++) {
	            //makes the flash hold longer. (stays on for j: 0 - 100, then off for j: 0 - 100)
	       for(j = 0; j<10000; j++){

	       }
	       if(i != 0){
	         P1OUT ^= bBoard;
	       }
            P1OUT ^= redLED;
	    }

	    P1OUT ^= greenLED; // Toggle the LED


	    //creates a delay for our led to toggle.
        /*for(i=0; i<1000; i++) {
                //makes the flash hold longer. (stays on for j: 0 - 100, then off for j: 0 - 100)
            for(j = 0; j<10000; j++){

           }
            P1OUT ^= redLED;
        }
        */

	    //Create a long delay by increasing the size of the integer value to type 32bit (16bit only can be 2^16-1)
       /*for(k = 0; k<65000; k++){

       }*/


	}

}
