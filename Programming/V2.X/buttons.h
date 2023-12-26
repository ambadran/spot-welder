#ifndef BUTTONS_H
#define BUTTONS_H

void buttons_init(void);
void _disable_button(uint8_t port_pin);
void _enable_button(uint8_t port_pin);
uint8_t read_button(uint8_t port_pin);

#endif
