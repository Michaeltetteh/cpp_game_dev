cmake_minimum_required(VERSION 3.2)

project(Object_Model)
set(CMAKE_CXX_STANDARD 11)


set(HEADERS_DIR 
    ${SDL_IMAGE_INCLUDE}
        Game.h
        Actor.h
        Component.h
        Math.h
        SpriteComponent.h
        AnimSpriteComponent.h
)

set(SOURCE_FILES
        Game.cpp
        Actor.cpp
        Component.cpp
        Math.cpp
        SpriteComponent.cpp
        AnimeSpriteComponent.cpp
)

include_directories(om ${HEADERS_DIR})

add_executable(om ${SOURCE_FILES})
target_link_libraries(om ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
