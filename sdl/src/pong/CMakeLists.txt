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
target_link_libraries(pong ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})