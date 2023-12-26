/*
 * File:   timers.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:05 PM
 */

#include "includes.h"

// at frequency 4Mhz (the internal oscillator) 
// Timer1 should overflow every 0.52428 seconds
void timers1_init(void) {

  T1CONbits.T1CKPS = 0b11;  // Pre-scalar maximum -> 8
  T1OSCEN = 0;
  TMR1CS = 0;
  TMR1ON = 1;

}

void timer1_ISR(void) {



}


// executes &func_ptr after time in ms :D 
void add_timer1_task(uint16_t time, void (*func_ptr)()) {

  __delay_ms(2000);
  func_ptr();

}

// executes &func_ptr with its argument :D
void add_timer1_task_with_arg(uint16_t time, void (*func_ptr)(), uint8_t func_arg) {

  __delay_ms(2000);
  func_ptr(func_arg);

}
