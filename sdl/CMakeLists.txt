cmake_minimum_required(VERSION 3.2)
project(LearnSDL)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wpedantic")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(cmake/common.cmake)

macro(copy_files files)
    foreach(file ${files})
        message(STATUS "Copying resource ${file}")
        file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/Assets)
    endforeach()
endmacro()

copy_files(${CMAKE_CURRENT_SOURCE_DIR}/Assets/)


add_subdirectory(src/pong)
add_subdirectory(src/om)
add_subdirectory(src/asteroid)
