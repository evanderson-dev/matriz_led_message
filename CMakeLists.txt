# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(matriz_led_message C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable with multiple source files
add_executable(matriz_led_message
    main.c
    neopixel.c
    font.c
)

# Set program name and version
pico_set_program_name(matriz_led_message "matriz_led_message")
pico_set_program_version(matriz_led_message "0.1")

# Generate PIO header
pico_generate_pio_header(matriz_led_message ${CMAKE_CURRENT_LIST_DIR}/ws2818b.pio)

# Enable/disable output over UART/USB (mantido como estava)
pico_enable_stdio_uart(matriz_led_message 0)
pico_enable_stdio_usb(matriz_led_message 1)

# Add the standard library and required hardware libraries
target_link_libraries(matriz_led_message
    pico_stdlib
    hardware_pio
    hardware_clocks
)

# Add include directories
target_include_directories(matriz_led_message PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Generate extra outputs (e.g., .uf2 file)
pico_add_extra_outputs(matriz_led_message)