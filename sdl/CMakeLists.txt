cmake_minimum_required(VERSION 3.2)
project(LearnSDL)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wpedantic")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


macro(copy_files files)
    foreach(file ${files})
        message(STATUS "Copying resource ${file}")
        file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/Assets)
    endforeach()
endmacro()

copy_files(${CMAKE_CURRENT_SOURCE_DIR}/Assets/)


find_package(Git QUIET)
if(GIT_FOUND AND EXISTS ${PROJECT_SOURCE_DIR}/../.git)
    option(GIT_SUBMODULES "Check submodules during build" ON)
    if(GIT_SUBMODULES)
        message(STATUS "Updating submodules")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule --init failed with ${GIT_SUBMOD_RESULT}.")
        endif()
    endif()
endif()


if(NOT EXISTS ${PROJECT_SOURCE_DIR}/external/sdl/CMakeLists.txt)
    message(FATAL_ERROR "sdl submodule was not downloaded, GIT_SUBMODULES was turned off or failed.")
endif()

if(NOT EXISTS ${PROJECT_SOURCE_DIR}/external/sdl_image/CMakeLists.txt)
    message(FATAL_ERROR "sdl_image submodule was not downloaded, GIT_SUBMODULES was turned off or failed.")
endif()

set(Math_LIB_PATH ${PROJECT_SOURCE_DIR}/lib/Math)
set(Math_LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/)

set(RANDOM_LIB_PATH ${PROJECT_SOURCE_DIR}/lib/Random)
set(RANDOM_LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/)

set(GLAD_LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/)
set(GLAD_LIB_PATH ${PROJECT_SOURCE_DIR}/lib/glad)

set(Logger_LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/)

add_subdirectory(lib)

add_subdirectory(external/sdl)
add_subdirectory(external/sdl_image)

add_subdirectory(src/pong)
add_subdirectory(src/om)
add_subdirectory(src/asteroid)
add_subdirectory(src/AI)
add_subdirectory(src/opengl)
