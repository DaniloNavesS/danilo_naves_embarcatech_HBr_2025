#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define JOYSTICK_X 26
#define JOYSTICK_Y 27

int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(JOYSTICK_X);
    adc_gpio_init(JOYSTICK_Y);

    while (1) {
        adc_select_input(0);
        uint adc_y_raw = adc_read();
        adc_select_input(1);
        uint adc_x_raw = adc_read();
        printf("Valor X: %d", adc_x_raw);
        printf(" ");
        printf("Valor Y: %d\n", adc_y_raw);
        sleep_ms(50);
    }
}