add_library(emblib_platform STATIC
    stm32n6/startup.c
	stm32n6/system/platform_init.c
)

target_link_libraries(emblib_platform PUBLIC emblib_mcu_flags)

target_compile_definitions(emblib_platform PUBLIC STM32N657xx)

target_include_directories(emblib_platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32n6/include
	${CMAKE_SOURCE_DIR}/third_party/st/cmsis/core/Include
    ${CMAKE_SOURCE_DIR}/third_party/st/cmsis/device/Include
)