project(OpenGLAsteroid)

set(HEADERS
        components/AnimSpriteComponent.h
        components/BGSpriteComponent.h
        components/SpriteComponent.h
        components/CircleComponent.h
        components/InputComponent.h
        components/MoveComponent.h
        components/Component.h
        VertexArrayBuffer.h
        actors/Asteroid.h
        actors/Laser.h
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
        VertexArrayBuffer.cpp
        actors/Asteroid.cpp
        actors/Laser.cpp
        actors/Actor.cpp
        actors/Ship.cpp
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
                ${RANDOM_LIB_INCLUDE_PATH}
                ${GLAD_LIB_INCLUDE_PATH}

        PUBLIC
                ${LearnSDL_SOURCE_DIR}/external/sdl/include
)
target_link_directories(${PROJECT_NAME} 
        PRIVATE 
                ${Math_LIB_PATH} 
                ${RANDOM_LIB_PATH}
                ${LearnSDL_SOURCE_DIR}/external/sdl
                ${GLAD_LIB_PATH}
)

target_link_libraries(${PROJECT_NAME} 
        Math 
        Random
        SDL2::SDL2
        SDL2_image
        Glad
)