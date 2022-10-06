find_package(SDL2  REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SDL_IMAGE_INCLUDE "/usr/local/Cellar/sdl2_image/2.6.2/include/" CACHE PATH "path to sdl_image" ) 
set(SDL_IMAGE_LIBRARY "/usr/local/Cellar/sdl2_image/2.6.2/lib/libSDL2_image-2.0.0.dylib" CACHE FILEPATH "sdl_image lib path" )


set(COMMON_HEADERS 
    ${SDL_IMAGE_INCLUDE}
    "../lib/math/Math.h"
    "../lib/math/Math.cpp"
)


