/*
 * File:   buttons.c
 * Author: mr-atom
 *
 * Created on December 20, 2023, 3:30 PM
 */

#include "includes.h"

// init method for buttons, mainly initializes TRIS registers
void buttons_init(void) {

  ARROW_KEY_TRIS = 1;
  ENTER_KEY_TRIS = 1;
  WELD_KEY_TRIS = 1;

}

// ignores button presses until _enable_button() is called
// by making the pin output by clearing the BUTTON_TRIS bit
void _disable_button(uint8_t port_pin) { 

  BUTTON_TRIS &= ~(1<<port_pin);  // button is now OUTPUT GPIO
  BUTTON_PORT &= ~(1<<port_pin);  // clearing button pin output

}

// registers button presses until _disable_button() is called
// by making the pin input, by setting the BUTTON_TRIS bit
void _enable_button(uint8_t port_pin) { 

  BUTTON_TRIS |= 1<<port_pin; // button is now INPUT GPIO

}


// read specific input button and return 0 or 1
// This function has button debounce software implementation
// where a timer task starts upon a button press to close
// inputs from timer until debounce period is finished
button_state_t read_button(uint8_t port_pin) {

  
  if ((BUTTON_PORT >> port_pin) & 0b1) {

    _disable_button(port_pin);
    push_task(&tasks, &_enable_button, DEBOUNCE_TIME, init_uint8_func_arg(port_pin));
    return BUTTON_PRESSED;

  } else {

    return BUTTON_NOT_PRESSED;

  }


}


