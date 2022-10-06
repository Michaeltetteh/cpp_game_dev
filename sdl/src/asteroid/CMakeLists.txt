project(Asteroid)

set(HEADERS
        components/AnimSpriteComponent.h
        components/BGSpriteComponent.h
        components/SpriteComponent.h
        components/Component.h
        actors/Actor.h
        actors/Ship.h
        Game.h
)

set(SOURCE_FILES
        components/Component.cpp
        components/SpriteComponent.cpp
        components/AnimeSpriteComponent.cpp
        components/BGSpriteComponent.cpp
        actors/Actor.cpp
        actors/Ship.cpp
        Game.cpp
        main.cpp
)


include_directories(asteroid ${HEADERS_DIR})

add_executable(asteroid ${SOURCE_FILES})
target_link_libraries(asteroid ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
