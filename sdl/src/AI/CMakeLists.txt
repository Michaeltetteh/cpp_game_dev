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
        Game.cpp
        main.cpp
)


include_directories(${PROJECT_NAME} ${HEADERS})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


# link lib
target_include_directories(${PROJECT_NAME} 
        PRIVATE 
                ${Math_LIB_INCLUDE_PATH}
                ${Logger_LIB_INCLUDE_PATH}
                #${RANDOM_LIB_INCLUDE_PATH}
        PUBLIC
                ${LearnSDL_SOURCE_DIR}/external/sdl/include
)
target_link_directories(${PROJECT_NAME} 
        PRIVATE 
                ${Math_LIB_PATH}
        PRIVATE
                ${LearnSDL_SOURCE_DIR}/external/sdl
)

target_link_libraries(${PROJECT_NAME} 
        Math 
        SDL2::SDL2
        SDL2_image
)


