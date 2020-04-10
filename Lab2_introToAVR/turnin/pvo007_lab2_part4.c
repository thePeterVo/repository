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
	unsigned char carA = 0x00;
	unsigned char carB = 0x00;
	unsigned char carC = 0x00;
	unsigned short totalweight = 0x0000;
	while(1) {
		carA = PINA;
		carB = PINB;
		carC = PINC;
		
		totalweight = PINA + PINB + PINC;
		if(abs((PINA - PINC)) >= 0x50) {
			notBalance = 0x02;
		}
		if(totalweight >= 0x008C) {
			overweight = 0x01;
		}
				
		PORTD = overweight | notBalance; //0b00010000 = approxweight is between 80 and 100 kg
		
	}
	return 0;
}
