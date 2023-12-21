#include "stdio.h"
#include "stdint.h"

void lcd_set_D_pins(uint8_t Data) {
  if(Data & 1)
    D4 = 1;
  else
    D4 = 0;
  if(Data & 2)
    D5 = 1;
  else
    D5 = 0;
  if(Data & 4)
    D6 = 1;
  else
    D6 = 0;
  if(Data & 8)
    D7 = 1;
  else
    D7 = 0;
  port = value | (port&0b11110000) 
}

int main() {

  uint8_t value = 0b1010;
  uint8_t port = 0b10011001;

  port = value

  printf("%hhn\n", port);

  return 0;
}

