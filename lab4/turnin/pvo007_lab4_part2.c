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
#include "RIMS.h"

enum States {start, state1, up, down, state4, state5} state;
void Tick {
	switch(state) {
		case Start:
			state = state1;
			break;
		case state1:
			if((~PINA & 0x03) == 0x03) {
				state = state5;
			}
			else if((~PINA & 0x03) == 0x02) {
				state = down;
			}
			else if((~PINA & 0x03) == 0x01) {
				state = up;
			else {
				state = state1;
			}
			break;
		case up:
			state = state4;
			break;
		case down:
			state = state4;
			break;
		case state4:
			if(((~PINA & 0x03) == 0x01) || ((~PINA & 0x03) == 0x02)) {
				state = state4;
			}
			else if((~PINA & 0x03) == 0x03) {
				state = state5;
			}
			else {
				state = state1;
			}
			break;
		case state5:
			if(((~PINA & 0x03) == 0x01) || ((~PINA & 0x03) == 0x02)) {
				state = state5;
			}
			else {
				state = state1;
			}
			break;
		default:
			break;
	}
	switch(state) {
		case start:
			PORTC = 0x07;
			break;
		case state1:
			break;
		case up:
			if(PORTC > 0x08) {
				PORTC = 0x09;
			}
			else {
				PORTC = PORTC + 0x01;
			}
			break;
		case down:
			if(PORTC < 1) {
				PORTC = 0x00;
			}
			else {
				PORTC = PORTC - 0x01;
			}
			break;
		case state4:
			break;
		case state5:
			PORTC = 0x00;
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	state = Start;
	while (1) {
		Tick();
    	}		
    	return 1;
}
