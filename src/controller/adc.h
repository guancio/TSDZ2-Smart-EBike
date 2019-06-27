/*
 * TongSheng TSDZ2 motor controller firmware/
 *
 * Copyright (C) Casainho, 2018.
 *
 * Released under the GPL License, Version 3
 */

#ifndef _ADC_H
#define _ADC_H

#include "main.h"

void adc_init (void);
uint16_t ui16_adc_read_battery_current_10b (void);
uint16_t ui16_adc_read_battery_voltage_10b (void);
uint16_t ui16_adc_read_torque_sensor_10b (void);
uint16_t ui16_adc_read_throttle_10b (void);
uint8_t ui8_adc_read_throttle(void);

#endif /* _ADC_H */
