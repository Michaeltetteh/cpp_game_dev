cmake_minimum_required(VERSION 3.2)

project(pong)
set(CMAKE_CXX_STANDARD 11)


set(HEADERS_DIR 
    ${SDL_IMAGE_INCLUDE}
        Game.h
        Pong.h
)

set(SOURCE_FILES
        Game.cpp
        Pong.cpp
        main.cpp
)

include_directories(pong ${HEADERS_DIR})

add_executable(pong ${SOURCE_FILES})
target_link_libraries(pong ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
