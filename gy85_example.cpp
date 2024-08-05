#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "gy85/gy85.hpp"

// I2C defines
#define I2C_PORT i2c0
#define I2C_SDA 4
#define I2C_SCL 5

int main()
{
    stdio_init_all();

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_PORT, 400*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    gpio_put(PICO_DEFAULT_LED_PIN, 1);

    sleep_ms(200);

    gy85 sensor;
    
    int res = sensor.init();

    if (res != PICO_OK)
    {
        while (true)
        {
            printf("Error initializing gy85\n");
            sleep_ms(1000);
        }
        
    }

    sensor.calibrate(20);

    gpio_put(PICO_DEFAULT_LED_PIN, 0);

    int status = 0;

    while (1)
    {
        sensor.read();

        printf("Accel: %f %f %f\n", sensor.get_accel().x, sensor.get_accel().y, sensor.get_accel().z);
        printf("Gyro: %f %f %f\n", sensor.get_gyro().x, sensor.get_gyro().y, sensor.get_gyro().z);
        printf("Mag: %f %f %f\n", sensor.get_mag().x, sensor.get_mag().y, sensor.get_mag().z);

        status = !status;
        gpio_put(PICO_DEFAULT_LED_PIN, status);

        sleep_ms(30);
    }

    return 0;
}
