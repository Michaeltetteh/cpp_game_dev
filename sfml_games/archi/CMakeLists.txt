cmake_minimum_required(VERSION 3.22)
project(archi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  main.cpp src/game.cpp)

set(HEADER_FILES headers/game.h)
add_executable(archi ${SOURCE_FILES}  ${HEADER_FILES})

include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(archi sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
