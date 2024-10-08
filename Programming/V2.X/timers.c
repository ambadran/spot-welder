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



