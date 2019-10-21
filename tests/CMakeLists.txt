cmake_minimum_required(VERSION 3.7)

# Project configuration
project(mnemonics LANGUAGES C)

# CHECK unit testing location
set(CHECK_INSTALL_DIR "C:/Program Files/check")

# minimum C
set(CMAKE_C_STANDARD 11)

# DEBUG
set(CMAKE_BUILD_TYPE Debug)

# Enable Coverage Tests
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage -O0")

# Show all warning messages
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_subdirectory(src)

enable_testing()

add_subdirectory(tests)

# Add build target to generate Coverage Test Report to all compiled object files
find_program(GCOV gcov)
find_program(LCOV lcov)
find_program(GENHTML genhtml)
if(NOT GCOV)
  message(FATAL_ERROR "gcov not found!")
endif()
if(NOT LCOV)
  message(FATAL_ERROR "lcov not found!")
endif()
if(NOT GENHTML)
  message(FATAL_ERROR "genhtml not found!")
endif()

set(SOURCES mnemonics.c dictionary.c)

find_package(OpenSSL)

set(EXECUTABLE mnemonicsplay)
set(EXAMPLE_PROGRAM example)

add_custom_target(gcov
  COMMAND mkdir -p Coverage
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Testing
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_command(TARGET gcov POST_BUILD
  COMMAND find ${CMAKE_BINARY_DIR} -type f -name *.c.o -exec ${GCOV} {} "\;"
  COMMAND echo "Coverage reports generated."
  COMMAND echo "You can find them on ${CMAKE_BINARY_DIR}/Coverage"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Coverage
  COMMENT "Coverage Reports Generated"
)

add_custom_target(lcov
  COMMAND mkdir -p Coverage
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Testing
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)


# Executables
add_executable(${EXECUTABLE} ${SOURCES} playground.c)
target_link_libraries(${EXECUTABLE} OpenSSL::Crypto)

add_executable(${EXAMPLE_PROGRAM} ${SOURCES} example.c)
target_link_libraries(${EXAMPLE_PROGRAM} OpenSSL::Crypto)

# Compilation for GCC, Clang
if (CMAKE_C_COMPILER_ID MATCHES Clang OR ${CMAKE_C_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra -pedantic")
endif()

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES Coverage)
