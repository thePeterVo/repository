/*	Author: pvo007
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned char overweight = 0x00;
	unsigned char notBalance = 0x00;
	while(1) {
		if((PINA + PINB + PINC) > 140) {
			overweight = 0x01;
		}
		if(PINA-PINC > 80) {
			notBalance = 0x02;
		}
		if(PINC-PINA > 80) {
			notBalance = 0x02;
		}

		PORTD = overweight | notBalance; //0b00010000 = approxweight is between 80 and 100 kg
		
	}
	return 0;
}
