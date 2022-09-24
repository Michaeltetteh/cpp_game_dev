#ifndef RECT_H 
#define RECT_H

#include "Game.h"

class DrawRect: public Game
{
private:
    int thickness;

public:
    DrawRect();
    void UpdateGame() override;
    void GenerateOutput() override;
};

DrawRect::DrawRect() :thickness(15)
{
    Game game;
}

void DrawRect::UpdateGame()
{
    SDL_SetRenderDrawColor(mRenderer,0,0,255,255);
    SDL_RenderClear(mRenderer);
}

void DrawRect::GenerateOutput()
{
    SDL_Rect wall{10, 10, 100,thickness };
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(mRenderer,&wall);

    SDL_RenderPresent(mRenderer);
}



#endif