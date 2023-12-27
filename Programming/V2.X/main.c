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
  comparators_deinit();
  timers1_init();
  uart_init();
  lcd_init();
  buttons_init();
  CD_control_init();
  tasks_init();
  interface_init();

  // Main Routine
  while (1) {

    if(read_button(ARROW_KEY_PIN_NUM)) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Arrow key");
      __delay_ms(100); // without this the lcd will fuck up

      charge_CD();

    }

    if(read_button(ENTER_KEY_PIN_NUM)) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Enter key");
      __delay_ms(100); // without this the lcd will fuck up

      discharge_CD();

    }

    if(read_button(WELD_KEY_PIN_NUM)) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Weld key");
      __delay_ms(100); // without this the lcd will fuck up
                       //
    }


  
  }

  return ;
}


void __interrupt() ISR(void) {

  if(TMR1IF) {

    timer1_ISR();
    TMR1IF = 0;

  }

}
