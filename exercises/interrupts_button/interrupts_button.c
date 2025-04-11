#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
// Configuração display Oled
#define I2C_SDA 14
#define I2C_SCL 15
#include "ssd1306.h"
// Definicao do OLED
ssd1306_t oled;
// Configuração de botoes
#define BUTTON_A 5
#define BUTTON_B 6
// Global variables
uint count = 0;
uint count_pressed = 0;
// Timer structs
struct repeating_timer timer;
// Constantes
#define INTERVAL 1000

volatile bool interval = false;

// Buffer
char buffer[100];

// Funcoes
void update_display () {
    sprintf(buffer, "Pressionado: %d", count_pressed);
    ssd1306_clear(&oled);
    ssd1306_draw_string(&oled, 10, 20, 1, buffer);

    sprintf(buffer, "Tempo: %d", count);
    ssd1306_draw_string(&oled, 10, 40, 1, buffer);
    ssd1306_show(&oled);
}

bool timer_function(struct repeating_timer *t)
{
    update_display();
    if (count == 0)
    {   
        interval = false;
        return false;
    }

    count--;
    return true;
}

int main() {
    // Configuration de Serial
    stdio_init_all();
    // Configuration display OLED
    i2c_init(i2c1, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    // Configuration Buttons
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
    // Check the operation of the OLED display
    if (!ssd1306_init(&oled, 128, 64, 0x3C, i2c1))
    {
        printf("Parou aqui\n");
        return 1;
    }

    while (gpio_get(BUTTON_A) == 1)
    {
        ssd1306_clear(&oled);
        ssd1306_draw_string(&oled, 10, 20, 1, "Pressiona A");
        ssd1306_show(&oled);
    }

    while (true) {
        if(gpio_get(BUTTON_A) == 0 && interval != true) {
            count = 9;
            count_pressed = 0;
            interval = true;
            add_repeating_timer_ms(INTERVAL, timer_function, NULL, &timer);
        }

        if(gpio_get(BUTTON_B) == 0 && interval == true) {
            count_pressed++;
            update_display();
        }

        sleep_ms(50);
    }
}
