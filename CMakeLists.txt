# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(gy85 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add library.
add_library(gy85 src/gy85.cpp)

# Add the standard include files to the build
target_include_directories(gy85 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(gy85
        pico_stdlib
        hardware_i2c
)

# Add executable. Default name is the project name, version 0.1
add_executable(gy85_example gy85_example.cpp )

pico_set_program_name(gy85_example "gy85_example")
pico_set_program_version(gy85_example "0.1")

pico_enable_stdio_uart(gy85_example 0)
pico_enable_stdio_usb(gy85_example 1)



# Add the standard include files to the build
target_include_directories(gy85_example PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
  ${CMAKE_CURRENT_LIST_DIR}/include
)
# Add the standard library to the build
target_link_libraries(gy85_example
        gy85
        pico_stdlib
        hardware_i2c)

pico_add_extra_outputs(gy85_example)

