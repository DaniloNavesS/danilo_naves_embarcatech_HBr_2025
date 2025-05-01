add_executable(test_temp_sensor
    test_temp_sensor.c
    Unity/src/unity.c
    ../src/temp_sensor.c
)

target_include_directories(test_temp_sensor PRIVATE
    Unity/src
    ../include
)

target_link_libraries(test_temp_sensor pico_stdlib)

pico_enable_stdio_usb(test_temp_sensor 1)
pico_enable_stdio_uart(test_temp_sensor 0)