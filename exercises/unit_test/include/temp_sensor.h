#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <stdint.h>

float adc_to_temperature(uint16_t adc_value);

#endif