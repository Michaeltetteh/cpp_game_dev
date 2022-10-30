#ifndef GAME_H 
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include <unordered_map>
#include <string>

class Game
{
public:
    Game();

    bool Initialize(); 

    void RunLoop();

    void Shutdown();

    std::vector<class Actor *> mActors;
    std::vector<class Actor *> mPendingActors;

    void AddActor(class Actor *actor);
    void RemoveActor(class Actor *actor);

    SDL_Texture *LoadTexture(const char* filename);
    SDL_Texture *GetTexture(const std::string &filename);

    void AddSprite(class SpriteComponent *sprite);
    void RemoveSprite(class SpriteComponent* sprite);

    void LoadData();
    void UnLoadData();

private:
    virtual void ProcessInput();
    virtual void UpdateGame();
    virtual void GenerateOutput();

    SDL_Window *mWindow;
    bool mUpdatingActors;

    std::unordered_map<std::string,SDL_Texture*> mTextures;
    std::vector<class SpriteComponent *> mSprites;


protected:
    bool mIsRunning;
    uint32_t mTicksCount;
    SDL_Renderer *mRenderer;
    int width;
    int height;

};

#endif