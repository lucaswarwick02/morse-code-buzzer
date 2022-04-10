/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

int main() {
    const int SIZE = 24;
    const uint LEDS[24] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 26, 27, 28};
    const int BUTTON = 20;
    for (int i = 0; i < SIZE; i++) {
        gpio_init(LEDS[i]);
        gpio_set_dir(LEDS[i], GPIO_OUT);
    }
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    while (true) {
        if (gpio_get(BUTTON)) {
            for (int i = 0; i < SIZE; i++) {
                gpio_put(LEDS[i], 0);
            }
        }
        else {
            for (int i = 0; i < SIZE; i++) {
                gpio_put(LEDS[i], 1);
            }
        }
    }
}
