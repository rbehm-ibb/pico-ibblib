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
