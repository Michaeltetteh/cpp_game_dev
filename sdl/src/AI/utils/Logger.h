#ifndef LOGGER_H
#define LOGGER_H

#include <SDL2/SDL_log.h>

#define NEWLINE     "\n"
#define LOG_INFO(message,...) SDL_Log(message NEWLINE, __VA_ARGS__);


#endif