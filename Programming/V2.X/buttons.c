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

// Unfortunately, this MCU doesn't support calling pointer functions with arguments. 
// which is the Main way I call most functions in this project as it's handled by the tasks module
// Therefore I must define a button read/_enable/_disable function for every button i define :(
// ********************************* CHECK BUTTON BY ARGUMENT START ************************************* //

/* // ignores button presses until _enable_button() is called */
/* // by making the pin output by clearing the BUTTON_TRIS bit */
/* void _disable_button(uint8_t port_pin) { */ 

/*   BUTTON_TRIS &= ~(1<<port_pin);  // button is now OUTPUT GPIO */
/*   BUTTON_PORT &= ~(1<<port_pin);  // clearing button pin output */

/* } */

/* // registers button presses until _disable_button() is called */
/* // by making the pin input, by setting the BUTTON_TRIS bit */
/* void _enable_button(uint8_t port_pin) { */ 

/*   BUTTON_TRIS |= 1<<port_pin; // button is now INPUT GPIO */

/* } */


/* // read specific input button and return 0 or 1 */
/* // This function has button debounce software implementation */
/* // where a timer task starts upon a button press to close */
/* // inputs from timer until debounce period is finished */
/* button_state_t read_button(uint8_t port_pin) { */

  
/*   if ((BUTTON_PORT >> port_pin) & 0b1) { */

/*     _disable_button(port_pin); */
/*     push_task(&tasks, DEBOUNCE_TIME, &_enable_button); */
/*     return BUTTON_PRESSED; */

/*   } else { */

/*     return BUTTON_NOT_PRESSED; */

/*   } */


/* } */

// ********************************** CHECK BUTTON BY ARGUMENT END ************************************** //


// ********************************* CHECK BUTTON HARD-DEFINED START ************************************* //

// ignores button presses until _enable_button() is called
// by making the pin output by clearing the BUTTON_TRIS bit
void _disable_arrow_button(void) {

  BUTTON_TRIS &= ~(1<<ARROW_KEY_PIN_NUM);  // button is now OUTPUT GPIO
  BUTTON_PORT &= ~(1<<ARROW_KEY_PIN_NUM);  // clearing button pin output

}

// registers button presses until _disable_button() is called
// by making the pin input, by setting the BUTTON_TRIS bit
void _enable_arrow_button(void) {

  BUTTON_TRIS |= 1<<ARROW_KEY_PIN_NUM; // button is now INPUT GPIO

}

// read specific input button and return 0 or 1
// This function has button debounce software implementation
// where a timer task starts upon a button press to close
// inputs from timer until debounce period is finished
button_state_t read_arrow_button(void) {
  
  if ((BUTTON_PORT >> ARROW_KEY_PIN_NUM) & 0b1) {

    _disable_arrow_button();
    push_task(&tasks, DEBOUNCE_TIME, &_enable_arrow_button);
    return BUTTON_PRESSED;

  } else {

    return BUTTON_NOT_PRESSED;

  }

}

// ignores button presses until _enable_button() is called
// by making the pin output by clearing the BUTTON_TRIS bit
void _disable_enter_button(void) {

  BUTTON_TRIS &= ~(1<<ENTER_KEY_PIN_NUM);  // button is now OUTPUT GPIO
  BUTTON_PORT &= ~(1<<ENTER_KEY_PIN_NUM);  // clearing button pin output

}

// registers button presses until _disable_button() is called
// by making the pin input, by setting the BUTTON_TRIS bit
void _enable_enter_button(void) {

  BUTTON_TRIS |= 1<<ENTER_KEY_PIN_NUM; // button is now INPUT GPIO

}

// read specific input button and return 0 or 1
// This function has button debounce software implementation
// where a timer task starts upon a button press to close
// inputs from timer until debounce period is finished
button_state_t read_enter_button(void) {
  
  if ((BUTTON_PORT >> ENTER_KEY_PIN_NUM) & 0b1) {

    _disable_enter_button();
    push_task(&tasks, DEBOUNCE_TIME, &_enable_enter_button);
    return BUTTON_PRESSED;

  } else {

    return BUTTON_NOT_PRESSED;

  }

}

// ignores button presses until _enable_button() is called
// by making the pin output by clearing the BUTTON_TRIS bit
void _disable_weld_button(void) {

  BUTTON_TRIS &= ~(1<<WELD_KEY_PIN_NUM);  // button is now OUTPUT GPIO
  BUTTON_PORT &= ~(1<<WELD_KEY_PIN_NUM);  // clearing button pin output

}

// registers button presses until _disable_button() is called
// by making the pin input, by setting the BUTTON_TRIS bit
void _enable_weld_button(void) {

  BUTTON_TRIS |= 1<<WELD_KEY_PIN_NUM; // button is now INPUT GPIO

}

// read specific input button and return 0 or 1
// This function has button debounce software implementation
// where a timer task starts upon a button press to close
// inputs from timer until debounce period is finished
button_state_t read_weld_button(void) {
  
  if ((BUTTON_PORT >> WELD_KEY_PIN_NUM) & 0b1) {

    _disable_weld_button();
    push_task(&tasks, DEBOUNCE_TIME, &_enable_weld_button);
    return BUTTON_PRESSED;

  } else {

    return BUTTON_NOT_PRESSED;

  }

}

// ********************************** CHECK BUTTON HARD_DEFINED END ************************************** //
