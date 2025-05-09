// Mason Crim
// Jacob Hoke

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "buzzer.h"

void initBuzzer(void) {
    DDRB |= (1 << PB3); // OC2A
    TCCR2A = (1 << COM2A0) | (1 << WGM21);
    TCCR2B = (1 << CS21); // prescaler 8
}

void playTone(uint16_t freq, uint16_t duration) {
    OCR2A = (F_CPU / (2 * 8 * freq)) - 1;
    _delay_ms(duration);
    OCR2A = 0;
}