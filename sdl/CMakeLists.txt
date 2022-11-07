cmake_minimum_required(VERSION 3.2)
project(LearnSDL)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wpedantic")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(cmake/common.cmake)

macro(copy_files files)
    foreach(file ${files})
        message(STATUS "Copying resource ${file}")
        file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/Assets)
    endforeach()
endmacro()

copy_files(${CMAKE_CURRENT_SOURCE_DIR}/Assets/)


set(Math_LIB_PATH ${PROJECT_SOURCE_DIR}/lib/Math)
set(Math_LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/)

add_subdirectory(lib)

add_subdirectory(src/pong)
add_subdirectory(src/om)
add_subdirectory(src/asteroid)
add_subdirectory(src/AI)
