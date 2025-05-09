// Mason Crim
// Jacob Hoke

#include <avr/io.h>
#include "led.h"

void setLEDPosition(uint8_t pos) {
    DDRD = 0xFF;                            // Enable PORTD outputs
    DDRB |= (1 << PB0) | (1 << PB1);        // Enable PB0 and PB1 outputs

    PORTD = 0x00;
    PORTB &= ~((1 << PB0) | (1 << PB1));

    if (pos < 8) {
        PORTD = (1 << pos);
    } else if (pos < 10) {
        PORTB |= (1 << (pos - 8));
    }
}
