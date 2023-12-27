#ifndef TIMERS_H
#define TIMERS_H

#define PRELOAD(v) (65535 - v)

void timers1_init(void);
void timer1_ISR(void);

#endif
