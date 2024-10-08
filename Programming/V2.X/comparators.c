/*
 * File:   comparators.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:04 PM
 */

#include "includes.h"

void comparators_deinit(void) {

  CMCONbits.CM = 0b111; // temp shutdown

}

