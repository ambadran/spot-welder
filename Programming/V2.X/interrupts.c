/*
 * File:   interrupts.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:05 PM
 */

#include "includes.h"

void interrupts_init(void) {

  GIE = 1;
  PEIE = 1;
  CMIE = 1;
  TMR1IE = 1;

}

