#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "hal_led.h"


void hal_led_toggle() {
    printf("Esta piscando\n");
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(500);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(500);
}