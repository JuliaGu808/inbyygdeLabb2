#include <avr/io.h>

#include "timer.h"

void timer_init() {
	// Init timer mode and prescaler
	TCCR0A = (1 << COM0A1) | (1 << COM0A0)|(1<<WGM00)|(1<<WGM01);  // pin 6 and fast PMW
	TCCR0B = (1 << CS01) | (1 << CS00);  // 64

	TCCR2A = (1<<WGM01);  // CTC
	TCCR2B = (1 << CS02) | (1 << CS00);  // 1024

	TCNT2 = 0;
	// OCR2A = (0.016s * 16000000Hz)/1024 = 250 = 0xFA
	OCR2A = 0xFA;
}



// void timer_init() {
// 	// Init timer mode and prescaler
// 	TCCR0A = (1 << COM0A1) | (1 << COM0A0)|(1<<WGM00)|(1<<WGM01);  // pin 6 and fast PMW
// 	TCCR0B = (1 << CS01) | (1 << CS00);  // 64
// }

// void timer_init() {
// 	// Load initial count value
// 	TCNT0 = 0;
// 	// Load compare match value
// 	// OCR0A = (0.01s * 16000000Hz)/1024 = 156 = 0x9C
// 	OCR0A = 0x9C;

// 	// OCR0A = (0.1s * 16000000Hz)/1024 = 1560 = 0x618
// 	// OCR0A = 0x618;

// 	// Init timer mode and prescaler
// 	TCCR0A = (1 << WGM01);
// 	TCCR0B = (1 << CS02) | (1 << CS00);
// }

