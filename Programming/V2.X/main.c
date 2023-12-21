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
  comparators_init();
  timers1_init();
  uart_init();
  lcd_init();
  buttons_init();
  CD_control_init();
  interface_init();

  // Main Routine
  while (1) {

    if(ARROW_KEY) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Arrow key");
      __delay_ms(300);
    }

    if(ENTER_KEY) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Enter key");
      __delay_ms(300);
    }

    if(WELD_KEY) {
      lcd_clear();
      lcd_set_cursor(1, 1);
      lcd_write_string("Weld key");
      __delay_ms(300);

    }


  
  }

  return ;
}


void __interrupt() ISR(void) {

  if(TMR1IF) {

    timer1_ISR();
    TMR1IF = 0;

  }

  if(CMIF) {

    comparators_ISR();
    CMIF = 0;

  }

}
