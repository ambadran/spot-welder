/*
 * File:   comparators.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:04 PM
 */

#include "includes.h"

void comparators_init(void) {

  CMCONbits.CM = 0b111; // temp shutdown

}

void comparators_ISR(void) {



}
