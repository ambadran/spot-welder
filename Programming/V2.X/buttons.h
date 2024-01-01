#ifndef BUTTONS_H
#define BUTTONS_H

typedef enum {
    BUTTON_PRESSED,
    BUTTON_NOT_PRESSED
} button_state_t;

void buttons_init(void);
/* void _disable_button(uint8_t port_pin); */
/* void _enable_button(uint8_t port_pin); */
/* button_state_t read_button(uint8_t port_pin); */

void _disable_arrow_button(void);
void _enable_arrow_button(void);
button_state_t read_arrow_button(void);

void _disable_enter_button(void);
void _enable_enter_button(void);
button_state_t read_enter_button(void);

void _disable_weld_button(void);
void _enable_weld_button(void);
button_state_t read_weld_button(void);

#endif
