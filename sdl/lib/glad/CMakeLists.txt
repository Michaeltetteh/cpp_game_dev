add_library(Glad STATIC glad.c glad.h khrplatform.h)

install(TARGETS Glad DESTINATION lib)
install(FILES glad.h DESTINATION include)