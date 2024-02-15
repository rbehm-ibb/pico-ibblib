# https://cliutils.gitlab.io/modern-cmake/chapters/intro/dodonot.html

add_library(gpiolib gpioinit.cpp gpioinit.h )
target_link_libraries(gpiolib pico_stdlib )
target_include_directories (gpiolib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(debuglib debug.cpp debug.h )
target_link_libraries(debuglib pico_stdlib pico_unique_id)
target_include_directories (debuglib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(formatting formatting.cpp formatting.h )
target_link_libraries(formatting pico_stdlib )
target_include_directories (formatting PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ledblink ledblink.cpp ledblink.h )
target_link_libraries(ledblink pico_stdlib hardware_pio )
target_include_directories (ledblink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(cmdline cmdline.cpp cmdline.h )
target_link_libraries(cmdline pico_stdlib  )
target_include_directories (cmdline PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(monofloptimer monofloptimer.cpp monofloptimer.h )
target_link_libraries(monofloptimer pico_stdlib hardware_pio )
target_include_directories (monofloptimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(pioutil pioutil.cpp pioutil.h )
target_link_libraries(pioutil pico_stdlib hardware_pio )
target_include_directories (pioutil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(i2c i2cchannel.h i2cchannel.cpp i2cdevice.h i2cdevice.cpp )
target_link_libraries(i2c pico_stdlib hardware_i2c )
target_include_directories (i2c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(simple_uart ibqueue.h uart/uartbase.h uart/uartbase.cpp uart/simpleuart.h uart/simpleuart.cpp )
target_link_libraries(simple_uart pico_stdlib hardware_uart hardware_irq )
target_include_directories (simple_uart PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/uart)

add_library(uart_line uart/uartbase.h uart/uartbase.cpp uart/uartline.h uart/uartline.cpp )
target_link_libraries(uart_line pico_stdlib hardware_uart hardware_irq )
target_include_directories (uart_line PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/uart)
