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
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char fuel = 0x00;
	unsigned char light = 0x00;

	while (1) {
		fuel = PINA;
		if(fuel >= 0x0D) {
			light = 0x3F;
		}
		else if(fuel >= 0x0A) {
			light = 0x3E;
		}
		else if(fuel >= 0x07) {
			light = 0x3C;
		}
		else if(fuel >= 0x05) {
			light = 0x38;
		}
		else if(fuel >= 0x03) {
			light = 0x70;
		}
		else if(fuel >= 0x00) {
			light = 0x60;
		}
		
		PORTC = light;
    	}
    	return 1;
}
