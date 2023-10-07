cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(PRJ_NAME wearable_hid)

set(PICO_SDK_PATH "${CMAKE_SOURCE_DIR}/src/lib/pico-sdk")
set(FREERTOS_KERNEL_PATH "${CMAKE_SOURCE_DIR}/FreeRTOS-Kernel")

include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include(${CMAKE_SOURCE_DIR}/FreeRTOS_Kernel_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
project(PRJ_NAME C CXX ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()


add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        -g3
        -O0
        )

add_subdirectory(src)