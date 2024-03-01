# https://cliutils.gitlab.io/modern-cmake/chapters/intro/dodonot.html

add_library(ibl_gpio gpioinit.cpp gpioinit.h )
target_link_libraries(ibl_gpio pico_stdlib )
target_include_directories (ibl_gpio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ibl_debug debug.cpp debug.h )
target_link_libraries(ibl_debug pico_stdlib pico_unique_id)
target_include_directories (ibl_debug PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ibl_formatting formatting.cpp formatting.h )
target_link_libraries(ibl_formatting pico_stdlib )
target_include_directories (ibl_formatting PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ibl_ledblink ledblink.cpp ledblink.h )
target_link_libraries(ibl_ledblink pico_stdlib hardware_pio )
target_include_directories (ibl_ledblink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ibl_cmdline cmdline.cpp cmdline.h )
target_link_libraries(ibl_cmdline pico_stdlib  )
target_include_directories (ibl_cmdline PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ibl_monofloptimer monofloptimer.cpp monofloptimer.h )
target_link_libraries(ibl_monofloptimer pico_stdlib hardware_pio )
target_include_directories (ibl_monofloptimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ibl_pioutil pioutil.cpp pioutil.h )
target_link_libraries(ibl_pioutil pico_stdlib hardware_pio )
target_include_directories (ibl_pioutil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory (i2c ibl_i2c)
add_subdirectory (uart ibl_uart )

add_library(ibl_ibqueue ibqueue.h )
target_link_libraries(ibl_ibqueue pico_stdlib )
target_include_directories (ibl_ibqueue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
