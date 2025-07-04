cmake_minimum_required(VERSION 4.0)

set(VCPKG_MANIFEST_MODE ON)
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")
set(VCPKG_BIN_DIR "${CMAKE_SOURCE_DIR}/${CMAKE_PREFIX_PATH}/bin")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "DEBUG: Running CMake from: ${CMAKE_SOURCE_DIR}")
message(STATUS "DEBUG: VPKG_BIN_DIR: ${VCPKG_BIN_DIR}")

if(UNIX)
    set(CMAKE_INSTALL_RPATH ${VCPKG_BIN_DIR})
    set(CMAKE_BUILD_RPATH ${VCPKG_BIN_DIR})
    message(STATUS "DEBUG: CMAKE_INSTALL_RPATH: ${CMAKE_INSTALL_RPATH}")
    message(STATUS "DEBUG: CMAKE_BUILD_PATH: ${CMAKE_BUILD_RPATH}")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(audio-learning VERSION 1.0.0)

file(GLOB INCLUDE "include/*.h")
file(GLOB SOURCES "src/*.cpp")

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${INCLUDE} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)

if(EXISTS ${VCPKG_BIN_DIR})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy_directory 
        ${VCPKG_BIN_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()