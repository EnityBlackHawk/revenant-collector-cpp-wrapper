macro(enable_minimal_debug_simbols target_name tp_debug_symbols)
    target_compile_options(example-rev PRIVATE -g1)
    if (tp_debug_symbols STREQUAL "SEPARATE")

        add_custom_command(
                TARGET ${target_name} POST_BUILD
                COMMAND ${CMAKE_OBJCOPY} ARGS --only-keep-debug $<TARGET_FILE:${target_name}> $<TARGET_FILE:${target_name}>.debug
                COMMAND ${CMAKE_OBJCOPY} ARGS --strip-debug $<TARGET_FILE:${target_name}>
                COMMAND ${CMAKE_OBJCOPY} ARGS --add-gnu-debuglink=$<TARGET_FILE:${target_name}>.debug $<TARGET_FILE:${target_name}>
        )
    endif()
endmacro()