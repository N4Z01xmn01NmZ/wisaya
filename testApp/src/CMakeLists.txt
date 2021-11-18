cmake_minimum_required(VERSION 3.16...3.21)

# Make executable app.
add_executable(${CLIENT_NAME})

# Add source files.
target_sources(${CLIENT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/testApp.cpp"
)

target_compile_definitions(${CLIENT_NAME}
    PRIVATE
        $<$<CONFIG:Debug>:WSY_CONFIG_DEBUG=1>
        $<$<CONFIG:Release>:WSY_CONFIG_RELEASE=1>
)

#Add include paths.
target_include_directories(${CLIENT_NAME}
    PRIVATE
        ${SPDLOG_PATH}/include
        ${ENGINE_INCLUDE_PATH}
        ${ENGINE_PATH} 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${CLIENT_NAME}
    PRIVATE
        ${ENGINE_NAME}
)
