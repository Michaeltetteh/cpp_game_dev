cmake_minimum_required(VERSION 3.2)

project(sdlgame)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(HEADERS_DIR 
    headers/Game.h
    headers/Pong.h
)

set(SOURCE_FILES
    src/main.cpp 
    src/Game.cpp
    src/Pong.cpp
)

include_directories(sdlgame ${HEADERS_DIR})

add_executable(sdlgame ${SOURCE_FILES})
target_link_libraries(sdlgame ${SDL2_LIBRARIES})
