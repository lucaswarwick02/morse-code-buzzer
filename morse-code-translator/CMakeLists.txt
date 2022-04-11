add_executable(morse-code-translator
        morse-code-translator.c
        decoder.c
        )

# pull in common dependencies
target_link_libraries(morse-code-translator pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(morse-code-translator)

# add url via pico_set_program_url
example_auto_set_url(morse-code-translator)
