cmake_minimum_required(VERSION 3.16...3.21)

# ---------------------------------------------------------------------------------------
# Start wisaya project
# ---------------------------------------------------------------------------------------

# Set app name.
set(ENGINE_NAME "wisaya")
set(CLIENT_NAME "testApp")
# Set directory path.
set(VENDOR_PATH         ${CMAKE_SOURCE_DIR}/vendor)
set(SPDLOG_PATH         ${VENDOR_PATH}/spdlog)
set(GLFW_PATH           ${VENDOR_PATH}/glfw)
set(ENGINE_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)
set(ENGINE_PATH         ${CMAKE_SOURCE_DIR}/src)
set(CLIENT_PATH         ${CMAKE_SOURCE_DIR}/${CLIENT_NAME})

# Set project.
project(${CLIENT_NAME}
    VERSION   0.1.0
    LANGUAGES C CXX
)

# Define executables and DLLs output directory.
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
${CMAKE_CURRENT_BINARY_DIR}/stage/${CMAKE_INSTALL_BINDIR}
)
endif()
# Define shared libraries output directory.
if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
${CMAKE_CURRENT_BINARY_DIR}/stage/${CMAKE_INSTALL_LIBDIR}
)
endif()
# Define static and import libraries output directory.
if(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${CMAKE_CURRENT_BINARY_DIR}/stage/${CMAKE_INSTALL_LIBDIR}
    )
endif()

# Surpress GLEW and GLFW process.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_UTILS OFF CACHE BOOL "" FORCE)

# ---------------------------------------------------------------------------------------
# Compiler config
# ---------------------------------------------------------------------------------------
if(NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD            11)
    set(CMAKE_C_STANDARD_REQUIRED   ON)
endif()
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD          17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# Make sure __cplusplus is defined when using msvc and enable parallel build
if(MSVC)
    string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus /MP")
endif()

set(CMAKE_C_EXTENSIONS   OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_SYSTEM_NAME MATCHES "CYGWIN" OR CMAKE_SYSTEM_NAME MATCHES "MSYS")
    set(CMAKE_C_EXTENSIONS   ON)
    set(CMAKE_CXX_EXTENSIONS ON)
endif()

# Add GLEW ,GLFW.
add_subdirectory(${GLFW_PATH})

# Add vendors.
add_subdirectory(${SPDLOG_PATH})
# Add Engine.
add_subdirectory(${ENGINE_PATH})
# Add Client.
add_subdirectory(${CLIENT_PATH}/src)
