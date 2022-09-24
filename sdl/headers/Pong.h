#ifndef PONG_H 
#define PONG_H

#include "Game.h"

struct Vec2
{
    Vec2(float a,float b):x(a),y(b){}

    float x;
    float y;
};


class Pong: public Game
{
private:
    int thickness;
    Vec2 _player;
    Vec2 topBar;

public:
    Pong();
    void UpdateGame() override;
    void GenerateOutput() override;
};

Pong::Pong() :thickness(15),_player(700.0f,300.0f),topBar(1.0f,10.0f)
{
    Game game;
}

void Pong::UpdateGame()
{
    SDL_SetRenderDrawColor(mRenderer,0,0,255,255);
    SDL_RenderClear(mRenderer);
}

void Pong::GenerateOutput()
{
    int w_thickness = 80;
    const SDL_Rect wall{
        static_cast<int>(topBar.x - thickness/2),
        static_cast<int>(topBar.y - thickness/2), 
        1024,
        thickness
    };
    const SDL_Rect player{
        static_cast<int>(_player.y - thickness/2),
        static_cast<int>(_player.x - thickness/2),
        100,
        thickness
    };
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(mRenderer,&wall);
    SDL_RenderFillRect(mRenderer,&player);

    SDL_RenderPresent(mRenderer);
}



#endif