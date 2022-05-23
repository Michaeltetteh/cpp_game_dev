cmake_minimum_required(VERSION 3.22)
project(asteroid)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/Game.cpp
        src/Player.cpp
        src/Action.cpp
        src/Configuration.cpp)

set(HEADER_FILES
        headers/Game.hpp
        headers/Player.hpp
        headers/Action.hpp
        headers/ActionTarget.hpp
        headers/ActionTarget.tpl
        headers/ActionMap.hpp
        headers/ActionMap.tpl
        headers/ResourceManager.hpp
        headers/ResourceManager.tpl headers/Configuration.hpp headers/World.hpp)

add_executable(asteroid ${SOURCE_FILES}  ${HEADER_FILES})

include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(asteroid sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
