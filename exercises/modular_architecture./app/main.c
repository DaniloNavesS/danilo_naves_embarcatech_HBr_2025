#include <stdio.h>
#include "pico/stdlib.h"

#include "led_embutido.h"
#include "hal_led.h"

int main () {
    stdio_init_all();
    uint init = inicializar_driver();

    if(init != 0) {
        printf("Erro na inicializacao");
    }

    while (true)
    {
        hal_led_toggle();
        sleep_ms(1000);
        tight_loop_contents();
    }
    
}