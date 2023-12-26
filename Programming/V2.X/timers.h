#ifndef TIMERS_H
#define TIMERS_H

void timers1_init(void);

void timer1_ISR(void);

void add_timer1_task(uint16_t time, void (*func_ptr)());

void add_timer1_task_with_arg(uint16_t time, void (*func_ptr)(), uint8_t func_arg);

#endif
