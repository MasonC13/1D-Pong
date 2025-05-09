// Mason Crim
// Jacob Hoke

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

// Function to turn of all LEDs
void enterSleep(void) {
    PORTD = 0x00;
    PORTB &= ~((1 << PB0) | (1 << PB1));

    
    set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Set sleep mode to power down
    sleep_enable();

    cli(); // Clear interrupts
    sleep_bod_disable();
    sei();
    sleep_cpu();          // Go to sleep

    sleep_disable();      // Clear sleep mode
}


