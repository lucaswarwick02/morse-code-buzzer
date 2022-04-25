add_executable(morse-code-buzzer
        morse-code-buzzer.c
        decoder.c
        )

# pull in common dependencies
target_link_libraries(morse-code-buzzer pico_stdlib hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(morse-code-buzzer)

# add url via pico_set_program_url
example_auto_set_url(morse-code-buzzer)
