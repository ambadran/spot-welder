/*
 * File:   main.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:04 PM
 */

#include "includes.h"

void main(void) {

  // inits / deinits
  interrupts_init();
  comparators_init();
  GPIO_init();
  timers1_init();
  uart_init();
  lcd_init();
  interface_init();

  // Main Routine
  while (1) {

  

  }

  return ;
}


void __interrupt() ISR(void) {

  if(TMR1IF) {

    timer1_ISR();
    TMR1IF = 0;

  }

  if(CMIF) {

    comparators_ISR();
    CMIF = 0;

  }

}
