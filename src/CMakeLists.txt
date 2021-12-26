cmake_minimum_required(VERSION 3.16...3.21)

# Make shared library.
add_library(${ENGINE_NAME} SHARED)

# Add source files.
add_subdirectory(wisaya)

target_compile_definitions(${ENGINE_NAME}
    PRIVATE
        WSY_DLL_EXPORT=1
        $<$<CONFIG:Debug>:WSY_CONFIG_DEBUG=1>
        $<$<CONFIG:Release>:WSY_CONFIG_RELEASE=1>
)

# PCH support
option(KDV_BUILD_USING_PCH "Build using pre-compile header support" ON)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND KDV_BUILD_USING_PCH) # support for PCHs in CMake was added in 3.16
    message(STATUS "Compiling using pre-compiled header support")
    target_precompile_headers(${ENGINE_NAME} PUBLIC Wisaya_pch.hpp) # With PUBLIC they will be used by targets using this target
    set(CMAKE_PCH_INSTANTIATE_TEMPLATES ON)
else()
    message(STATUS "Disabled pre-compiled header support")
endif(CMAKE_VERSION VERSION_GREATER_EQUAL 3.16 AND KDV_BUILD_USING_PCH)

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
