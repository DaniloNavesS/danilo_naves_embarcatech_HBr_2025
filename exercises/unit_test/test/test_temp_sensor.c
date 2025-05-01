#include "unity.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include "temp_sensor.h"

void setUp(void) {}
void tearDown(void) {}

void test_adc_to_temperature(void) {
    TEST_ASSERT_FLOAT_WITHIN(0.5, 27.0, adc_to_temperature(876));
    TEST_ASSERT_FLOAT_WITHIN(0.5, 30.0, adc_to_temperature(869));
}

int main(void) {
    stdio_init_all();

    sleep_ms(3000);

    UNITY_BEGIN();
    RUN_TEST(test_adc_to_temperature);
    UNITY_END();

    while (true) {
        tight_loop_contents();
    }

    return 0;
}
