// Mason Crim
// Jacob Hoke

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "led.h"
#include "input.h"
#include "buzzer.h"
#include "sleep.h"

volatile uint8_t led_pos = 0;
volatile int8_t direction = 1;
uint32_t idle_counter = 0;

int main(void) {
    cli();
    initTimers();
    initADC();
    initButton();
    initBuzzer();
    sei();

    while (1) {
        uint16_t pot_val = readPot();
        OCR1A = 10000 + ((uint32_t)pot_val * 50000UL / 1023);

        idle_counter++;

        if (buttonflag) {
            buttonflag = 0;
            idle_counter = 0;

            if ((led_pos == 0 && direction == -1) || (led_pos == 9 && direction == 1)) {
                direction *= -1;
                playTone(1000, 100);  // Success sound
            } else {
                playTone(200, 100);   // Fail sound
            }
        }

        if (idle_counter > 50000UL) {
            enterSleep();
            idle_counter = 0;
        }
    }
}


