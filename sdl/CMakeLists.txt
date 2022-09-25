cmake_minimum_required(VERSION 3.2)

project(sdlgame)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(HEADERS_DIR 
    src/om/Game.h
    src/om/Actor.h
    src/om/Component.h
    src/pong/Pong.h
)

set(SOURCE_FILES
    src/om/Game.cpp
    src/om/Actor.cpp
    src/pong/Pong.cpp
    src/main.cpp 
)

include_directories(sdlgame ${HEADERS_DIR})

add_executable(sdlgame ${SOURCE_FILES})
target_link_libraries(sdlgame ${SDL2_LIBRARIES})
