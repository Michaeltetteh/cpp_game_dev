project(state_machine)

set(HEADERS
        components/AnimSpriteComponent.h
        components/BGSpriteComponent.h
        components/SpriteComponent.h
        components/CircleComponent.h
        components/InputComponent.h
        components/MoveComponent.h
        components/AIComponent.h
        components/Component.h
        components/AIState.h
        actors/Actor.h
        utils/Random.h
        utils/Logger.h
        Game.h

)

set(SOURCE_FILES
        components/AnimeSpriteComponent.cpp
        components/BGSpriteComponent.cpp
        components/SpriteComponent.cpp
        components/CircleComponent.cpp
        components/InputComponent.cpp
        components/MoveComponent.cpp
        components/AIComponent.cpp
        components/Component.cpp
        components/AIState.cpp
        actors/Actor.cpp
        utils/Random.cpp
        Game.cpp
        main.cpp
)


include_directories(state_machine ${COMMON_HEADERS} ${HEADERS})

add_executable(state_machine ${SOURCE_FILES})
target_link_libraries(state_machine ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
