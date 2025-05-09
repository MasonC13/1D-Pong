// Mason Crim
// Jacob Hoke

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "led.h"
#include "input.h"

extern volatile uint8_t led_pos;
extern volatile int8_t direction;

void initTimers(void) {
    // Timer0 for button
    TCCR0B = (1 << CS02) | (1 << CS00); // Prescale 1024
    TIMSK0 = (1 << TOIE0); // Overflow interrupt

    // Timer1 Walking LED
    TCCR1B = (1 << WGM12) | (1 << CS12); // Prescaler 256
    TIMSK1 = (1 << OCIE1A);
}

ISR(TIMER0_OVF_vect) {
    debounceButton();
}

// Pause at edges until button press
ISR(TIMER1_COMPA_vect) {
    if ((led_pos == 0 && direction == -1) || (led_pos == 9 && direction == 1)) {
        return;
    }

    led_pos += direction;

    if (led_pos > 9) led_pos = 9;
    if (led_pos < 0) led_pos = 0;

    setLEDPosition(led_pos);
}


