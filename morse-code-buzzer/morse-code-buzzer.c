/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "decoder.h"
#include <ctype.h>
#include <string.h>
#include "hardware/pwm.h"

const int BUZZER = 18;

uint32_t pwm_set_freq_duty(uint slice_num, uint chan,uint32_t f, int d) {
    uint32_t wrap = 0;

    // Write your solution here...

    return wrap;
}

const int DOT_DURATION = 150; // 0.15s
const int DASH_DURATION = 450; // 0.45s
const int GAP_DURATION = 300; // 0.3s
const int SPACE_DURATION = 1000; // 1s

int main () {
    stdio_init_all();

    // Assign GP18 to PWM
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    uint chan = pwm_gpio_to_channel(BUZZER);

    // Our defined function, which Assigns the pwm values
    // 3rd arguement = frequency, 4th argiuement = percentage duty cycle
    pwm_set_freq_duty(slice_num,chan, 250, 50);

    sleep_ms(10000);

    // Get the Morse code for the word
    char word[32] = "Hello";
    char code[32] = "";

    int i;
    for (i = 0; word[i] != 0; i++) {
        // Runs for each character in the word
        strcat(code, CharToCode(toupper(word[i])));
        char space = ' ';
        strncat(code, &space, 1);
    }

    for (i = 0; code[i] != 0; i++) {
        if (code[i] == '.') {
            // Dot
            pwm_set_enabled(slice_num, true);
            sleep_ms(DOT_DURATION);
            pwm_set_enabled(slice_num, false);
        }
        if (code[i] == '-') {
            // Dash
            pwm_set_enabled(slice_num, true);
            sleep_ms(DASH_DURATION);
            pwm_set_enabled(slice_num, false);
        }
        if (code[i] == ' ') {
            // Break in letters
            sleep_ms(SPACE_DURATION);
        }

        sleep_ms(GAP_DURATION);
    }

    return 0;
}