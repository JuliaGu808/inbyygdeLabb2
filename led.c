#include <avr/io.h>
#include "led.h"


void LED_init() {
	PORTD&=~(1<<PD6); // pin 6
	//set PD6 as output
	DDRD|=(1<<PD6);
}


// void LED_init() {
// 	DDRB |= 0b000001; // PIN 8
// }
