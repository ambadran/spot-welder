#ifndef CD_CONTROL_H
#define CD_CONTROL_H

// should be accessible from any file
uint16_t charge_time;
#define set_charge_time(v) (charge_time = v)
uint16_t discharge_time;
#define set_discharge_time(v) (discharge_time = v)

void CD_control_init(void);
void _start_charging(void);
void _end_charging(void);
void _start_discharging(void);
void _end_discharging(void);
void charge_CD(void);
void discharge_CD(void);

#endif
