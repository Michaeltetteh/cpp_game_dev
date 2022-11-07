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


include_directories(${PROJECT_NAME} ${HEADERS})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# sdl lib
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})

# link Math lib
target_include_directories(${PROJECT_NAME} PRIVATE ${Math_LIB_INCLUDE_PATH})
target_link_directories(${PROJECT_NAME} PRIVATE ${Math_LIB_PATH})

target_link_libraries(${PROJECT_NAME} Math)


