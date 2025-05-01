#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "temp_sensor.h"

#define ADC_TEMPERATURE_CHANNEL 4

int main()
{
    stdio_init_all();
    adc_init();
    adc_set_temp_sensor_enabled(true); 
    adc_select_input(ADC_TEMPERATURE_CHANNEL);

    while (true) {
        uint16_t adc_value = adc_read();
        int temperature = adc_to_temperature(adc_value);
        printf("%d °C\n", temperature);
        sleep_ms(1000);
    }
}
