#pragma once
class Game
{
public:
    Game();
    ~Game();
    void Init(std::string WindowTitle);
    void Render();
    void Update();
    void HandleEvents();
    void Quit();
};

