cmake_minimum_required(VERSION 3.2)

project(sdlgame)
set(CMAKE_CXX_STANDARD 11)

include(cmake/common.cmake)

set(HEADERS_DIR 
    ${SDL_IMAGE_INCLUDE}
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
target_link_libraries(sdlgame ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
