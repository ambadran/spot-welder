#ifndef CONFIG_H
#define CONFIG_H

/*** uC specific configs ***/
//internal oscillator
/* OSCF = (__bit)1; // 4MHz */
#define _XTAL_FREQ 4000000
/* ********************** */

/*** User configs ***/
#define DEFAULT_CHARGE_TIME 2000
#define DEFAULT_DISCHARGE_TIME 2000

#define DEBOUNCE_TIME 300
/* ********************** */

/*** compile checks ***/

/* ********************** */

#endif
