project(Random)
add_library(Random STATIC Random.cpp Random.h)


target_include_directories(${PROJECT_NAME} PRIVATE ${Math_LIB_INCLUDE_PATH})
target_link_directories(${PROJECT_NAME} PRIVATE ${Math_LIB_PATH})

target_link_libraries(${PROJECT_NAME} Math)