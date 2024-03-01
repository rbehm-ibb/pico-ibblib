add_library(ibb_simple_uart
	 uartbase.h uartbase.cpp simpleuart.h simpleuart.cpp 
        )

target_link_libraries(ibb_simple_uart
        hardware_uart hardware_irq
        pico_stdlib
        )
target_include_directories (ibb_simple_uart PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ibb_uart_line
	 uartbase.h uartbase.cpp uartline.h uartline.cpp 
        )

target_link_libraries(ibb_uart_line
        hardware_uart hardware_irq
        pico_stdlib
        )
target_include_directories (ibb_uart_line PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

