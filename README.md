# Morse Code Buzzer

## Description

In this task you will make the buzzer (built into the Cytron Maker Pi Pico) output the morse code values for a given string. The fucntions for the morse code are provided, as well as the conversions, however the section in which you need to write is the function `pwm_set_freq_duty(uint slice_num, uint chan,uint32_t f, int d);`. The function is already called inside of `main();`, and your solution should call the following functions in order to turn the buzzer on using PWM: `pwm_set_clkdiv_int_frac`, `pwm_set_wrap`, `pwm_set_chan_level`.

## Source for Hints

[The Pico in C: Basic PWM](https://www.i-programmer.info/programming/hardware/14849-the-pico-in-c-basic-pwm.html)

## Task Classification

I have classified this task as a medium, due to the complexity of the code required for pwm. However, this task is not too difficult if you follow along the source I have provided in the above section, as it guides the user through PWM as well as the solution.