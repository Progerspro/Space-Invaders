#pragma once
#include "Load.h"
class Texture :
    public Load
{
private:
    std::map<std::string,SDL_Surface*> Texture_SurfaceContainer;

    SDL_Surface* Texture_Surface = nullptr;
    bool Success = true;
    
public:
    ~Texture();
    
    bool LoadSurface(std::string Path);
    void LoadTexture(std::string ID);
    SDL_Texture* GetTexture(std::string ID);
};

