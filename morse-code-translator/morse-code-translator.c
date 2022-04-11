/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>
#include "decoder.h"

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

    const int RESET_BUTTON = 21;
    gpio_init(RESET_BUTTON);
    gpio_set_dir(RESET_BUTTON, GPIO_IN);

    const int ENTER_BUTTON = 22;
    gpio_init(ENTER_BUTTON);
    gpio_set_dir(ENTER_BUTTON, GPIO_IN);

    int isInputDown = 0; // 0 = up, 1 = down
    int isResetDown = 0; // 0 = up, 1 = down
    int isEnterDown = 0; // 0 = up, 1 = down
    
    struct Duration signal;

    char str[6] = "";
    
    while (true) {
        if (gpio_get(INPUT_BUTTON)) {
            if (isInputDown != 0) {
                // Button has been lifted
                isInputDown = 0;
                signal.end = time_us_32();
                signal.difference = signal.end - signal.start;
                // 1000000 microseconds = 1 second
                if (signal.difference < 330000) {
                    // Short Signal
                    char ch = '.';
                    strncat(str, &ch, 1);
                    printf("%c", ch);
                }
                else {
                    // Long Signal
                    char ch = '-';
                    strncat(str, &ch, 1);
                    printf("%c", ch);
                }
                // Reset the timers
                signal.start = 0;
                signal.end = 0;
                signal.difference = 0;
            }
        }
        else {
            if (isInputDown != 1) {
                // Button has been pressed
                isInputDown = 1;
                signal.start = time_us_32();
            }
        }

        // Reset Button: Resets the currently stored signals
        if (gpio_get(RESET_BUTTON)) {
            if (isResetDown != 0) {
                // Button has been lifted
                isResetDown = 0;
            }
        }
        else {
            if (isResetDown != 1) {
                // Button has been pressed
                isResetDown = 1;
                printf("\nStored Signals Reset\n");
                strcpy(str, "");
            }
        }

        // Enter Button: Decodes the stored signals
        if (gpio_get(ENTER_BUTTON)) {
            if (isEnterDown != 0) {
                // Button has been lifted
                isEnterDown = 0;
            }
        }
        else {
            if (isEnterDown != 1) {
                // Button has been pressed
                isEnterDown = 1;
                printf("\nDecoded letter: %c\n", DecodeString(str));
                strcpy(str, "");
            }
        }
    }
}
