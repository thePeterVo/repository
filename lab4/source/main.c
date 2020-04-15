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

enum States {start, state1, state2, state3, state4} state;
void Tick {
	switch(state) {
		case Start:
			state = state1;
			break;
		case state1:
			if(PINA == 0x01) {
				state = state2;
			}
			else {
				state = state1;
			}
			break;
		case state2:
			if(PINA == 0x03) {
				state = state4;
			}
			else if(PINA == 0x00) {
				state = state1;
			}
			else {
				state = state2;
			}
			break;
		case state3:
			if(PINA & 0x01) {
				state = state4;
			}
			else {
				state = state3;
			}
			break;
		case state4:
			if(~PINA & 0x01) {
				state = state1;
			}
			else {
				state = state4;
			}
			break;
	}
	switch(state) {
		case start:
			PORTC = 0x07;
			break;
		case state1:
			PORTB = 0x01;
			break;
		case state2:
			PORTB = 0x02;
			break;
		case state3:
			PORTB = 0x02;
			break;
		case state4:
			PORTB = 0x01;
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
