/*
 * File:   CD_control.c
 * Author: mr-atom
 *
 * Created on December 20, 2023, 3:31 PM
 */

#include "includes.h"

// init for Capacitive Discharge bank control
void CD_control_init(void) {

  DISCHARGE_PIN_TRIS = 0;
  CHARGE_PIN_TRIS = 0;

}

void _start_charging(void) { CHARGE_PIN = 1; }
void _end_charging(void) { CHARGE_PIN = 0; }
void _start_discharging(void) { DISCHARGE_PIN = 1; }
void _end_discharging(void) { DISCHARGE_PIN = 0; }

// This function is responsible to charge the Capacitor Discharge bank
void charge_CD(void) {

  _start_charging();
  push_task(&tasks, &_end_charging, charge_time, void_func_arg);

}

// This function is responsible to discharge the Capacitor Discharge bank
void discharge_CD(void) {

  _start_discharging();
  push_task(&tasks, &_end_discharging, discharge_time, void_func_arg);

}
