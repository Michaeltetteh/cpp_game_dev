project(pong)

set(HEADERS_DIR
        Game.h
        Pong.h
)

set(SOURCE_FILES
        Game.cpp
        Pong.cpp
        main.cpp
)

include_directories(pong ${COMMON_HEADERS} ${HEADERS_DIR})
add_executable(pong ${SOURCE_FILES})
target_link_libraries(pong ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})