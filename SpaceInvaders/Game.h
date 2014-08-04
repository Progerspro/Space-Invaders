#pragma once
#include "Load.h"
class Game
{
private:
    SDL_Event Event;
    SDL_Renderer* P_Renderer = nullptr;
    SDL_Window* P_Window = nullptr;
    bool IsRunning;
public:
    Game();
    ~Game();

    bool GameRunning();


    void Init(std::string WindowTitle, int PosX, int PosY, int Width, int Height, int Flag);
    void Render();
    void Update();
    void HandleEvents();
    void Quit();
};

