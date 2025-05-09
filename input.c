// Mason Crim
// Jacob Hoke

#include <avr/io.h>
#include <avr/interrupt.h>
#include "input.h"

volatile uint8_t buttonflag = 0;

void initButton(void) {
    DDRC &= ~(1 << PC0);        // PC0 as input
    PORTC |= (1 << PC0);        // Enable pull-up resistor

    // Enable Timer0 overflow for debounce
    TCCR0B = (1 << CS02) | (1 << CS00); // Prescaler 1024
    TIMSK0 = (1 << TOIE0);              // Enable overflow interrupt

    
    PCICR |= (1 << PCIE1);      // Enable PCINT
    PCMSK1 |= (1 << PCINT8);    // Enable PCINT8 (PC0)
}

void debounceButton(void) {
    static uint8_t prev_state = 1;
    uint8_t current_state = (PINC & (1 << PC0)) >> PC0;

    if (prev_state == 1 && current_state == 0) {
        buttonflag = 1;
    }

    prev_state = current_state;
}

ISR(PCINT1_vect) {
    buttonflag = 1;
}

void initADC(void) {
    ADMUX = (1 << REFS0) | (1 << MUX0); // AVcc as ref, PC1
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Enable ADC
}

uint16_t readPot(void) {
    ADCSRA |= (1 << ADSC);              // Start conversion
    while (ADCSRA & (1 << ADSC));       // Wait for conversion to finish
    return ADC;
}


