cmake_minimum_required(VERSION 3.20)

project(EmbeddedLibrary LANGUAGES C CXX ASM)

option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Build tests (host)" OFF)

set(EMBLIB_PLATFORM "stm32n6" CACHE STRING "Platform (e.g. stm32n6)")
set(EMBLIB_BOARD "stm32n6570_dk" CACHE STRING "Board (e.g. stm32n6570_dk)")

message(STATUS "Platform: ${EMBLIB_PLATFORM}")
message(STATUS "Board: ${EMBLIB_BOARD}")

add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(platform)
add_subdirectory(boards)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

if(BUILD_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()

