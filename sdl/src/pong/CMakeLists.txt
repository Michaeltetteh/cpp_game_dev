project(pong)

set(HEADERS
        Game.h
        Pong.h
)

set(SOURCE_FILES
        Game.cpp
        Pong.cpp
        main.cpp
)

include_directories(pong ${HEADERS})
add_executable(pong ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} 
        PUBLIC
                ${LearnSDL_SOURCE_DIR}/external/sdl/include
)
target_link_directories(${PROJECT_NAME} 
        PRIVATE 
                ${LearnSDL_SOURCE_DIR}/external/sdl
)

target_link_libraries(${PROJECT_NAME} 
        SDL2::SDL2
)