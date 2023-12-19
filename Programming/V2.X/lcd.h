#ifndef LCD_H
#define LCD_H

#define LCD_EN_DELAY 500
#define lcd_set_D_pins(v) (LCD_DATA = v)

void lcd_SL(void);
void lcd_SR(void);
void lcd_CMD(unsigned char CMD);
void lcd_Clear(void);
void lcd_init(void);
void lcd_Set_Cursor(unsigned char r, unsigned char c);
void lcd_Write_Char(char Data);
void lcd_Write_String(char *str);

#endif
