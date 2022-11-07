project(Object_Model)

set(HEADERS
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


include_directories(${PROJECT_NAME} ${HEADERS})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})


# link Math lib
target_include_directories(${PROJECT_NAME} PRIVATE ${Math_LIB_INCLUDE_PATH})
target_link_directories(${PROJECT_NAME} PRIVATE ${Math_LIB_PATH})

target_link_libraries(${PROJECT_NAME} Math)