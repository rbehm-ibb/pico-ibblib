add_library(ibb_i2c
	i2cdevice.h i2cdevice.cpp
        i2cchannel.cpp
        i2cregister.h i2cregister.cpp
        i2cscan.h i2cscan.cpp
        )

# add_subdirectory(textRenderer)

target_link_libraries(ibb_i2c
        hardware_i2c
        pico_stdlib
        )
target_include_directories (ibb_i2c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
