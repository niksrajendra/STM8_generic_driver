#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

extern uint16_t globalCounter;

void timer4_init(void);

void timerUs(uint16_t value);
void timerMs(uint16_t value);
void timerS(uint16_t value);

#endif // TIMER_H
