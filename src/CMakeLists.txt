file(GLOB SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.c*
    ${CMAKE_SOURCE_DIR}/src/ap/*.c*
    ${CMAKE_SOURCE_DIR}/src/ap/src/*.c*
    ${CMAKE_SOURCE_DIR}/src/bsp/*.c*
    ${CMAKE_SOURCE_DIR}/src/common/core/*.c*
    ${CMAKE_SOURCE_DIR}/src/hw/*.c*
    ${CMAKE_SOURCE_DIR}/src/hw/driver/*.c*
    ${CMAKE_SOURCE_DIR}/src/hw/driver/imu/*.c*
)

add_executable(${PRJ_NAME}
  ${SRC_FILES}
)


target_include_directories(${PRJ_NAME} PUBLIC
    ap
    ap/include
    bsp
    common
    common/core
    common/hw/include
    hw
)

target_compile_definitions(${PRJ_NAME} PRIVATE
    PICO_STDIO_STACK_BUFFER_SIZE=64 # use a small printf on stack buffer
)

target_link_libraries(${PRJ_NAME}
    FreeRTOS-Kernel-Heap4
    pico_stdlib
    pico_multicore
    hardware_clocks
    hardware_pll
    hardware_gpio
    hardware_i2c
    hardware_spi
    hardware_uart
    hardware_dma
    hardware_irq
)


pico_add_extra_outputs(${PRJ_NAME})
pico_enable_stdio_usb(${PRJ_NAME}  1)
pico_enable_stdio_uart(${PRJ_NAME} 0)

set_target_properties(${PRJ_NAME} PROPERTIES SUFFIX ".elf")
add_custom_command(TARGET ${PRJ_NAME} POST_BUILD
        COMMAND arm-none-eabi-size --format=berkeley --totals "$<TARGET_FILE:${PRJ_NAME}>"
        COMMENT "Invoking: Cross ARM GNU Print Size")