/*
 * File:   CD_control.c
 * Author: mr-atom
 *
 * Created on December 20, 2023, 3:31 PM
 */

#include "includes.h"

void CD_control_init(void) {

  DISCHARGE_PIN_TRIS = 0;
  CHARGE_PIN_TRIS = 0;

}
