add_executable(maker-blink
        maker-blink.c
        )

# pull in common dependencies
target_link_libraries(maker-blink pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(maker-blink)

# add url via pico_set_program_url
example_auto_set_url(maker-blink)
