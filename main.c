#include "msp430x22x4.h"
int counter = 0;
void main(void){
	WDTCTL = WDTPW + WDTHOLD;
	P1OUT |= 0x08;              // Pull P1.2 high
	P1REN |= 0x08;				// Pull-up resistor
	P1DIR |= 0x01;              // Set P1.0 to output
	/*WDTCTL = WDTPW + WDTHOLD;   // Stop watchdog timer
	P1OUT |= 0x04;              // Pull P1.2 high
	P1REN |= 0x04;				// Pull-up resistor
	P1DIR |= 0x01;              // Set P1.0 to output
	P1DIR &= ~0x04;				// Set P1.2 to input
	P1OUT &= ~0x01;             // Set the red LED off
	P1IE  |= 0x04;				// P1.2 is the interrupt bit
	P1IES |= ~0x04; 			// Lo/Hi edge
	P1IFG &= ~0x04; 			// Interrupt flag bit cleared


	P2OUT |= 0x04;              // Pull P2.2 high
	P2REN |= 0x04;				// Pull-up resistor
	P2DIR &= ~0x04;              // Set P2 as input byte
	P2IE  |= 0x04;				// P2 is the interrupt bit
	P2IFG &= ~0x04;             // Interrupt flag bit cleared
	P2IES |= ~0x04;             // low-high

	P2DIR |= 0x01;              // Set P2.0 to output
	P2OUT &= ~0x01;

	__enable_interrupt();

	while(1);

}


//interrupt
#pragma vector=PORT1_VECTOR
#pragma vector=PORT2_VECTOR
__interrupt void my_handler (void){
	int count = 0;
	int T_valid = 20;
	while(count >= 0){
		if((~P1IN & BIT2)|(~P2IN & BIT2)){
			count++;
		}else{
			count = -1;
		}
		if(count > T_valid){
			while((~P1IN & BIT2)|(~P2IN & BIT2)){
				counter =  0;
				P1OUT ^= 0x01;
				P2OUT ^= 0x01;
				while(counter<250){
					counter++;
				}
			}
			count = -1;
			P1OUT &= ~0x01;
			P2OUT &= ~0x01;
		}
	}
	P1IFG = P1IFG & (~0x04); //clear the flag
	P2IFG = P2IFG & (~0x04); //clear the flag
	return;*/
}


