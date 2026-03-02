# cmake/embedded_flags.cmake
add_library(emblib_mcu_flags INTERFACE)

target_compile_options(emblib_mcu_flags INTERFACE
  -mcpu=cortex-m55
  -mthumb
  -ffunction-sections
  -fdata-sections
)

target_link_options(emblib_mcu_flags INTERFACE
  -mcpu=cortex-m55
  -mthumb
  -Wl,--gc-sections
)