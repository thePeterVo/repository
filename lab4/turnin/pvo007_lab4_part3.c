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

enum States {start, check1, check2, check3, open} state;
void Tick() {
	switch(state) {
		case start:
			state = check1;
			break;
		case check1:
			if(PINA == 0x04) {
				state = check2;
			}
			else {
				state = start;
			}
			break;
		case check2:
			if(PINA == 0x00) {
				state = check3;
			}
			else {
				state = check2;
			}
		case check3:
			if(PINA == 0x02) {
				state = open;
			}
			else if(PINA == 0x01) {
				state = start;
			}
			else {
				state = check3;
			}
			break;
		case open:
			if(PINA == 0x80) {
				state = start;
			}
			else {
				state = open;
			}
			break;
		default:
			break;
	}
	switch(state) {
		case start:
			PORTB = 0x00;
			break;
		case check1:
			break;
		case check2:
			break;
		case check3:
			break;
		case open:
			PORTB = 0x01;
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	state = start;
	while (1) {
		Tick();
    	}		
    	return 1;
}
