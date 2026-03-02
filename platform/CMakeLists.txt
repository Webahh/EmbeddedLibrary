add_library(emblib_platform STATIC
    stm32n6/startup.c
)

target_link_libraries(emblib_platform PUBLIC emblib_mcu_flags)

target_include_directories(emblib_platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)