#include <stdio.h>
#include <pico/stdlib.h>
#include "pico/cyw43_arch.h"

#include "led_embutido.h"

int inicializar_driver() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        return -1;
    }

    return 0;
}