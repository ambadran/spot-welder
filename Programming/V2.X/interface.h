#ifndef INTERFACE_H
#define INTERFACE_H

#define MAXIMUM_NUM_THICKNESSES 2
typedef enum {

  THICKNESS_0_1MM,
  THICKNESS_0_15MM
    
} thickness_t;

const uint16_t thickness_charge_time_map[MAXIMUM_NUM_THICKNESSES] = { THICKNESS_0_1MM_CHARGE_TIME, THICKNESS_0_15MM_CHARGE_TIME };
const uint16_t thickness_discharge_time_map[MAXIMUM_NUM_THICKNESSES] = { THICKNESS_0_1MM_DISCHARGE_TIME, THICKNESS_0_15MM_DISCHARGE_TIME };

const char THICKNESS_0_1MM_MSG[16] =  ">0.1mm   0.15mm";
const char THICKNESS_0_15MM_MSG[16] = " 0.1mm  >0.15mm";
const char* choose_thickness_display[2] = {THICKNESS_0_1MM_MSG, THICKNESS_0_15MM_MSG};

typedef enum {

  THICKNESS_CONFIRMED,
  THICKNESS_NOT_CONFIRMED
    
} thickness_confirmed_state;

void interface_init(void);

void select_thickness_routine(void);
void allow_choose_thickness(void);
void allow_confirm_thickness(void);

void charge_discharge_routine(void);
void display_charging_state(void);
void display_charged_state(void);
void weld_routine(void);

void check_enter_for_exit(void);

#endif
