/*
 * File:   interface.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:05 PM
 */

#include "includes.h"

// initializing variables
thickness_t choosen_thickness = DEFAULT_THICKNESS; 
thickness_confirmed_state thickness_confirmed = THICKNESS_NOT_CONFIRMED;

void interface_init(void) {

  // Displaying Welcome Message
  lcd_set_cursor(1, 2);
  lcd_write_string("Spot Welder V2");

  //TODO: un-comment this, after development
  /* push_extended_task(&tasks, WELCOME_MESSAGE_TIME, &select_thickness_routine); */
  push_task(&tasks, MAXIMUM_TMR_PERIOD-1, &select_thickness_routine);

}

void select_thickness_routine(void) {

  // display select thickness title
  lcd_set_cursor(1, 1);
  lcd_write_string("Thickness:      ");

  // display options
  lcd_set_cursor(2, 1);
  lcd_write_string(choose_thickness_display[choosen_thickness]);

  // continiously polling arrow and enter key until thickness_confirmed is THICKNESS_CONFIRMED
  push_task(&tasks, 20000, &allow_choose_thickness);
  push_task(&tasks, 35000, &allow_confirm_thickness);

}

void allow_choose_thickness(void) {

    if (read_arrow_button() == BUTTON_PRESSED) {

      // updating choosen thickness variable
      choosen_thickness = (choosen_thickness + 1) % MAXIMUM_NUM_THICKNESSES;

      // display options
      lcd_set_cursor(2, 1);
      lcd_write_string(choose_thickness_display[choosen_thickness]);

      // keep calling
      push_task(&tasks, 10000, &allow_choose_thickness);

    } else {

      if (thickness_confirmed == THICKNESS_NOT_CONFIRMED) {

        push_task(&tasks, 10000, &allow_choose_thickness);

      }

    }

}

void allow_confirm_thickness(void) {

  if (read_enter_button() == BUTTON_PRESSED) {

    // asserting thickness is confirmed to stop polling arrow button
    thickness_confirmed = THICKNESS_CONFIRMED;

    // User now choose thickness, updating charge and discharge values
    set_charge_time(thickness_charge_time_map[choosen_thickness]);
    set_discharge_time(thickness_discharge_time_map[choosen_thickness]);

    // Now calling
    lcd_clear();
    push_task(&tasks, 12000, &charge_discharge_routine);


  } else {

    push_task(&tasks, 15000, &allow_confirm_thickness);

  }

}

void charge_discharge_routine(void) {

  push_task(&tasks, 30000, &check_enter_for_exit);

  // display select charging state
  lcd_set_cursor(1, 1);
  lcd_write_string("   Charging..   ");
  /* lcd_set_cursor(2, 1); */
  /* lcd_write_string("                "); */

  charge_CD();
  push_task(&tasks, charge_time, &display_charged_state);

}

void display_charged_state(void) {

  // display select charging state
  lcd_set_cursor(1, 1);
  lcd_write_string("    Charged!    ");
  /* lcd_set_cursor(2, 1); */
  /* lcd_write_string("                "); */

  push_task(&tasks, 10000, &weld_routine);

}

void weld_routine(void) {

  if (read_weld_button() == BUTTON_PRESSED) {

    discharge_CD();
    push_task(&tasks, discharge_time, &charge_discharge_routine);

  } else {

    push_task(&tasks, 15000, &weld_routine);

  }

}

void check_enter_for_exit(void) {

  if (read_enter_button() == BUTTON_PRESSED) {

    // Soft Reset task module
    init_tasks(&tasks);
    init_func_queue(&func_queue);

    // start all over again
    interface_init();

  } else {

    push_task(&tasks, 30000, &check_enter_for_exit);

  }

}
