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
 	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;

    /* Insert your solution below */
	unsigned short weight = 0x0000;
	while (1) {
		weight = (PIND << 1) | (PINB & 0x01);
		if(weight >= 0x0046) {
			PORTB = 0x02;
		}
		else if((weight > 0x0005) && (weight < 0x46)) {
			PORTB = 0x04;
		}
		else if(weight < 0x0005) {
			PORTB = 0x00;
		}
	}
	return 1;
}
