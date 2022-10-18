project(Asteroid)

set(HEADERS
        components/AnimSpriteComponent.h
        components/BGSpriteComponent.h
        components/SpriteComponent.h
        components/CircleComponent.h
        components/InputComponent.h
        components/MoveComponent.h
        components/Component.h
        actors/Asteroid.h
        actors/Laser.h
        utils/Random.h
        actors/Actor.h
        actors/Ship.h
        Game.h

)

set(SOURCE_FILES
        components/AnimeSpriteComponent.cpp
        components/BGSpriteComponent.cpp
        components/SpriteComponent.cpp
        components/CircleComponent.cpp
        components/InputComponent.cpp
        components/MoveComponent.cpp
        components/Component.cpp
        actors/Asteroid.cpp
        actors/Laser.cpp
        actors/Actor.cpp
        utils/Random.cpp
        actors/Ship.cpp
        Game.cpp
        main.cpp
)


include_directories(asteroid ${COMMON_HEADERS} ${HEADERS})

add_executable(asteroid ${SOURCE_FILES})
target_link_libraries(asteroid ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
