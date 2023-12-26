#ifndef CD_CONTROL_H
#define CD_CONTROL_H

extern uint16_t charge_time = DEFAULT_CHARGE_TIME;
extern uint16_t discharge_time = DEFAULT_DISCHARGE_TIME;

void CD_control_init(void);
void _start_charging(void);
void _end_charging(void);
void _start_discharging(void);
void _end_discharging(void);
void charge_CD(void);
void discharge_CD(void);

#endif
