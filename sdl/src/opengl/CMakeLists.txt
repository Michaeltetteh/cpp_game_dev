project(OpenGLAsteroid)


set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wpedantic")

file(GLOB HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/actors/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/components/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/EN/*.h"
)
file(GLOB SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/actors/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/components/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EN/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

include_directories(${PROJECT_NAME} ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})


target_include_directories(${PROJECT_NAME} 
        PRIVATE 
                ${Math_LIB_INCLUDE_PATH}
                ${Logger_LIB_INCLUDE_PATH}
                ${RANDOM_LIB_INCLUDE_PATH}
                ${GLAD_LIB_INCLUDE_PATH}
        PRIVATE
                ${LearnSDL_SOURCE_DIR}/external/glm
                ${LearnSDL_SOURCE_DIR}/lib/stb_image
        PUBLIC
                ${LearnSDL_SOURCE_DIR}/external/sdl/include
)
target_link_directories(${PROJECT_NAME} 
        PRIVATE 
                ${Math_LIB_PATH} 
                ${RANDOM_LIB_PATH}
                ${LearnSDL_SOURCE_DIR}/external/sdl
                ${LearnSDL_SOURCE_DIR}/lib/stb_image
                ${GLAD_LIB_PATH}
)

target_link_libraries(${PROJECT_NAME} 
        Math 
        Random
        SDL2::SDL2
        SDL2_image
        Glad
        stb_image
)