/*
 * File:   main.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:04 PM
 */

#include "includes.h"

void main(void) {

  // ** inits / deinits ** //
  
  // MCAL layers
  interrupts_init();
  comparators_deinit();
  timers1_init();
  uart_init();

  // HAL layer
  lcd_init();
  buttons_init();
  CD_control_init();

  // Middle (RTOS) layer
  tasks_module_init();

  // Application layer
  interface_init();

  // Main Routine
  while (1) {

    // Executing functions in current function queue
    while(func_queue.size != 0) { 

      pop_func_q(&func_queue)(); 

    }
  
  }

  return ;
}


void __interrupt() ISR(void) {

  if(TMR1IF) {

    pop_task_push_func_queue_update_TMR(&tasks, &func_queue);
    TMR1IF = 0;

  }

}
