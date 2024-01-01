#ifndef CONFIG_H
#define CONFIG_H

/*** uC specific configs ***/
//internal oscillator
/* OSCF = (__bit)1; // 4MHz */
#define _XTAL_FREQ 4000000
#define MAXIMUM_TMR_PERIOD 65535
/* ********************** */

/*** User configs ***/
// VERY IMP: please note that all time values are in cycles value, use equation from datasheet to directly set a preloading value to wanted time (not matter how big)
#define THICKNESS_0_1MM_CHARGE_TIME 65000
#define THICKNESS_0_1MM_DISCHARGE_TIME 37500

#define THICKNESS_0_15MM_CHARGE_TIME 65000
#define THICKNESS_0_15MM_DISCHARGE_TIME 50000

#define DEFAULT_THICKNESS THICKNESS_0_1MM

// Software Debounce time for all buttons
#define DEBOUNCE_TIME 50000 // 300 ms

// VERY IMPORTANT, controls the maximum number of tasks we can deal with simultaneously
// current there is only 5 time-related functions, the 3 buttons and the charge and the discharge functions
#define MAXIMUM_TASK_NUM 20 


// Interface stuff
#define WELCOME_MESSAGE_TIME  125000  // 1 second
                                      //

/* ********************** */

/*** compile checks ***/

/* ********************** */

#endif
