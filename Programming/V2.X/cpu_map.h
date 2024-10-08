#ifndef CPU_MAP_H
#define CPU_MAP_H

/* **** LCD PINs **** */
#define LCD_DATA_TRIS TRISB
#define LCD_DATA PORTB
#define D4 RB0
#define D5 RB1
#define D6 RB2
#define D7 RB3
#define EN RB4
#define RS RB5
/* ****************** */

/* *** CD_control pins*** */
#define CHARGE_PIN_TRIS TRISB6
#define CHARGE_PIN RB6
#define DISCHARGE_PIN_TRIS TRISB7
#define DISCHARGE_PIN RB7
/* ********************** */

/* **** button pins**** */
#define BUTTON_TRIS TRISA
#define BUTTON_PORT PORTA

#define ARROW_KEY_TRIS TRISA5
#define ARROW_KEY RA5
#define ARROW_KEY_PIN_NUM 5

#define ENTER_KEY_TRIS TRISA6
#define ENTER_KEY RA6
#define ENTER_KEY_PIN_NUM 6

#define WELD_KEY_TRIS TRISA7
#define WELD_KEY RA7
#define WELD_KEY_PIN_NUM 7
/* ******************** */



#endif
