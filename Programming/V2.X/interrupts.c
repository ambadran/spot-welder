/*
 * File:   interrupts.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:05 PM
 */

#include "includes.h"

void interrupts_init(void) {

  // setting internal oscillator to 4Mhz
  // I really don't want to make a specific file for this, so will write it here
  OSCF = 1;

  // interrupt enable bits
  GIE = 1;
  PEIE = 1;
  CMIE = 0;
  TMR0IE = 0;
  TMR1IE = 1;
  TMR2IE = 0;

}

