cmake_minimum_required(VERSION 3.2)

project(Object_Model)
set(CMAKE_CXX_STANDARD 11)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src/om/bin)

set(HEADERS_DIR 
    ${SDL_IMAGE_INCLUDE}
        Game.h
        Actor.h
        Component.h
        Math.h
        SpriteComponent.h
        AnimSpriteComponent.h
        BGSpriteComponent.h
        Ship.h
)

set(SOURCE_FILES
        Game.cpp
        Actor.cpp
        Component.cpp
        Math.cpp
        SpriteComponent.cpp
        AnimeSpriteComponent.cpp
        BGSpriteComponent.cpp
        Ship.cpp
        main.cpp
)


macro(copy_files files)
    foreach(file ${files})
        message(STATUS "Copying resource ${file}")
        file(COPY ${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/Assets)
    endforeach()
endmacro()

macro(copy_resources dirs)
    foreach(dir ${dirs})
        string(REGEX REPLACE "/+$" "" dirclean "${dir}")
        message(STATUS "Copying resource ${dirclean}")
        file(COPY ${dirclean} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/)
    endforeach()
endmacro()

copy_resources(../../Assets/)
copy_files(${CMAKE_CURRENT_SOURCE_DIR}/../../Assets/)


include_directories(om ${HEADERS_DIR})

add_executable(om ${SOURCE_FILES})
target_link_libraries(om ${SDL2_LIBRARIES} ${SDL_IMAGE_LIBRARY})
