#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdbool.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"


bool up = false;
uint8_t target = 0xFF;

void T0Delay(void)
{

	timer_init();
	// Wait until timer 0 compare match
	while ((TIFR2 & (1 << OCF2A)) == 0)
		;
	// Stop timer 0
	TCCR2B = 0;
	// Clear compare math flag
	TIFR2 = (1 << OCF2A);
}

uint8_t simple_ramp(void)
{
	if(target==0xFF) up=false;
	if(target==0x00) up=true;

	if(up) return target++;
	return target--;

}

void main (void) {
	uart_init();
	LED_init();
	timer_init();

	while (1) {

		OCR0A = simple_ramp();

		for (int i = 0; i < 10; i++)
				T0Delay();
	}
}



// //  T/C0: Pin6(OC0A) and Pin5(OC0B)
// uint8_t TOP = 0xFF;
// uint8_t BOTTOM = 0x00;

// void main(void)
// {
// 	uart_init();
// 	LED_init();
// 	timer_init();

// 	while (1)
// 	{
// 		become_weaker();
// 		become_stronger();
// 	}
// }

// void become_stronger(void)
// {
// 	for (int led = TOP; led > BOTTOM; --led)
// 	{
// 		OCR0A = led;
// 		_delay_ms(10);
// 	}
// }

// void become_weaker(void)
// {
// 	for (int led = 0; led < TOP; ++led)
// 	{
// 		OCR0A = led;
// 		_delay_ms(10);
// 	}
// }




// void main (void) {
// 	uart_init();
// 	LED_init();

// 	while (1) {
// 		PORTB |= 0b000001;
// 		// Delay (10 * 10ms)
// 		for (int i = 0; i < 10; i++)
// 			T0Delay();

// 		PORTB &= ~0b000001;
// 		// Delay (10 * 10ms)
// 		for (int i = 0; i < 10; i++)
// 			T0Delay();
// 	}
// }

// void T0Delay()
// {

// 	timer_init();
// 	while ((TIFR0 & (1 << OCF0A)) == 0)
// 		;
// 	// Stop timer 0
// 	TCCR0B = 0;
// 	// Clear compare math flag
// 	TIFR0 = (1 << OCF0A);
// }
