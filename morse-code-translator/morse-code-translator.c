/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>
#include "decoder.h"

char DecodeString (char key[]);

struct Duration {
    // All 3 members are measured in microseconds
    uint32_t start;
    uint32_t end;
    uint32_t difference;
};

int main() {
    stdio_init_all();

    const int INPUT_BUTTON = 20;
    gpio_init(INPUT_BUTTON);
    gpio_set_dir(INPUT_BUTTON, GPIO_IN);

    const int BACK_BUTTON = 21;
    gpio_init(BACK_BUTTON);
    gpio_set_dir(BACK_BUTTON, GPIO_IN);

    int isDown = 0; // 0 = up, 1 = down
    
    struct Duration signal;

    char str[5] = "";
    
    while (true) {
        if (gpio_get(INPUT_BUTTON)) {
            // Up
            if (isDown != 0) {
                // Button has been lifted
                isDown = 0;
                signal.end = time_us_32();
                signal.difference = signal.end - signal.start;
                // 1000000 microseconds = 1 second
                if (signal.difference < 330000) {
                    // Short Signal
                    //printf("%c%c%c", DecodeString(".-"), DecodeString("-..."), DecodeString("-.-."));
                    char ch = '.';
                    strncat(str, &ch, 1);
                }
                else {
                    // Long Signal
                    //printf("%c%c%c", DecodeString("-..."), DecodeString(".--"), DecodeString(".-"));
                    char ch = '-';
                    strncat(str, &ch, 1);
                }
                printf("%s", str);
                // Reset the timers
                signal.start = 0;
                signal.end = 0;
                signal.difference = 0;
            }
        }
        else {
            // Down
            if (isDown != 1) {
                // Button has been pressed
                isDown = 1;
                signal.start = time_us_32();
            }
        }
    }
}
