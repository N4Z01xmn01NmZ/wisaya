cmake_minimum_required(VERSION 3.16...3.21)

# Make shared library.
add_library(${ENGINE_NAME} SHARED)

# Add source files.
add_subdirectory(wisaya)
target_sources(${ENGINE_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/test.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/test.h"
)

target_compile_definitions(${ENGINE_NAME}
    PRIVATE
        WSY_DLL_EXPORT=1
        $<$<CONFIG:Debug>:WSY_CONFIG_DEBUG=1>
        $<$<CONFIG:Release>:WSY_CONFIG_RELEASE=1>
)

# Add include paths.
target_include_directories(${ENGINE_NAME}
    PRIVATE
        ${SPDLOG_PATH}/include
        ${ENGINE_INCLUDE_PATH}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link with third party libraries.
target_link_libraries(${ENGINE_NAME}
    PRIVATE
        spdlog
)
