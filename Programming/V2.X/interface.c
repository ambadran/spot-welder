/*
 * File:   interface.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:05 PM
 */

#include "includes.h"

void interface_init(void) {

  lcd_set_cursor(1, 1);
  lcd_write_string("  test1");
  lcd_set_cursor(2, 1);
  lcd_write_string("   test2");

}
