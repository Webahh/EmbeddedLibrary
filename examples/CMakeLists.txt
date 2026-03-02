add_executable(blinky
    blinky/main.c
)

target_link_libraries(blinky
    PRIVATE
        emblib_board
)

target_compile_options(blinky PRIVATE
    -mcpu=cortex-m55
    -ffunction-sections
    -fdata-sections
)

target_link_libraries(blinky PRIVATE emblib_mcu_flags)

target_link_options(blinky PRIVATE
    -mcpu=cortex-m55
    -mthumb
    -nostdlib
    -nostartfiles
    -nodefaultlibs
    -Wl,--gc-sections
	-T${CMAKE_SOURCE_DIR}/platform/stm32n6/linker.ld
)