project(Object_Model)

set(HEADERS_DIR
        Game.h
        Actor.h
        Component.h
        SpriteComponent.h
        AnimSpriteComponent.h
        BGSpriteComponent.h
        Ship.h
)

set(SOURCE_FILES
        Game.cpp
        Actor.cpp
        Component.cpp
        SpriteComponent.cpp
        AnimeSpriteComponent.cpp
        BGSpriteComponent.cpp
        Ship.cpp
        main.cpp
)


include_directories(om ${COMMON_HEADERS} ${HEADERS_DIR})
add_executable(om ${SOURCE_FILES})
target_link_libraries(om ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
