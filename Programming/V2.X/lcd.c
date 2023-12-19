/*
 * File:   lcd.c
 * Author: mr-atom
 *
 * Created on December 19, 2023, 3:05 PM
 */

#include "includes.h"

void lcd_SL() {

  lcd_CMD(0x01);
  lcd_CMD(0x08);

}

void lcd_SR() {

  lcd_CMD(0x01);
  lcd_CMD(0x0C);

}

void lcd_CMD(unsigned char CMD) {
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
  lcd_CMD(0x03);
  __delay_ms(5);
  lcd_CMD(0x03);
  __delay_us(150);
  lcd_CMD(0x03);
  lcd_CMD(0x02);
  lcd_CMD(0x02);
  lcd_CMD(0x08);
  lcd_CMD(0x00);
  lcd_CMD(0x0C);
  lcd_CMD(0x00);
  lcd_CMD(0x06);

}

void lcd_Clear() {
  lcd_CMD(0);
  lcd_CMD(1);
}

void lcd_Set_Cursor(unsigned char r, unsigned char c) {

  unsigned char Temp,Low4,High4;

  if(r == 1) {
    Temp = 0x80 + c - 1; //0x80 is used to move the cursor
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    lcd_CMD(High4);
    lcd_CMD(Low4);
  }

  if (r == 2) {
    Temp = 0xC0 + c - 1;
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    lcd_CMD(High4);
    lcd_CMD(Low4);
  }
}

void lcd_Write_Char(char Data) {
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

void lcd_Write_String(char *str) {
  int i;
  for(i=0;str[i]!='\0';i++)
    lcd_Write_Char(str[i]);
}

