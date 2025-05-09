// Mason Crim
// Jacob Hoke

#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

extern volatile uint8_t buttonflag;

void initADC(void);
void initButton(void);
uint16_t readPot(void);
void debounceButton(void);

#endif
