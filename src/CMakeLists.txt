cmake_minimum_required(VERSION 3.5)

# Project configuration
project(mnemonics LANGUAGES C)
set(SOURCES mnemonics.c)
set(EXECUTABLE mnemonicsplay)

# Executables
add_executable(${EXECUTABLE} ${SOURCES} playground.c)

# Compilation for GCC, Clang
if (CMAKE_C_COMPILER_ID MATCHES Clang OR ${CMAKE_C_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra -pedantic")
endif()
