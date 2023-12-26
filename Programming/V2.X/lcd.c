/*
 * File:   lcd.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:05 PM
 */

#include "includes.h"

void lcd_cmd(uint8_t CMD) {
  // Select Command Register
  RS = 0;
  // Move The Command Data To lcd
  lcd_set_D_pins(CMD);
  // Send The EN Clock Signal
  EN = 1;
  __delay_us(LCD_EN_DELAY);
  EN = 0; 
}

void lcd_init(void) {

  // IO Pin Configurations
  LCD_DATA_TRIS = 0x00;

  // The Init. Procedure As Described In The Datasheet
  lcd_set_D_pins(0x00);
  __delay_ms(30);
  __delay_us(LCD_EN_DELAY);
  lcd_cmd(0x03);
  __delay_ms(5);
  lcd_cmd(0x03);
  __delay_us(150);
  lcd_cmd(0x03);
  lcd_cmd(0x02);
  lcd_cmd(0x02);
  lcd_cmd(0x08);
  lcd_cmd(0x00);
  lcd_cmd(0x0C);
  lcd_cmd(0x00);
  lcd_cmd(0x06);
  
  lcd_clear();

}

void lcd_clear() {
  lcd_cmd(0);
  lcd_cmd(1);
}

void lcd_set_cursor(uint8_t r, uint8_t c) {

  unsigned char Temp,Low4,High4;

  if(r == 1) {
    Temp = 0x80 + c - 1; //0x80 is used to move the cursor
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    lcd_cmd(High4);
    lcd_cmd(Low4);
  }

  if (r == 2) {
    Temp = 0xC0 + c - 1;
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    lcd_cmd(High4);
    lcd_cmd(Low4);
  }
}

void lcd_write_char(char Data) {
  char Low4,High4;
  Low4 = Data & 0x0F;
  High4 = Data & 0xF0;
  RS = 1;
  lcd_set_D_pins(High4>>4);
  EN = 1;
  __delay_us(LCD_EN_DELAY);
  EN = 0;
  __delay_us(LCD_EN_DELAY);
  lcd_set_D_pins(Low4);
  EN = 1;
  __delay_us(LCD_EN_DELAY);
  EN = 0;
  __delay_us(LCD_EN_DELAY);
}

void lcd_write_string(char *str) {
  int i;
  for(i=0;str[i]!='\0';i++)
    lcd_write_char(str[i]);
}

// NEVER USED
/* void lcd_SL() { */
/*   lcd_cmd(0x01); */
/*   lcd_cmd(0x08); */
/* } */

/* void lcd_SR() { */
/*   lcd_cmd(0x01); */
/*   lcd_cmd(0x0C); */
/* } */


