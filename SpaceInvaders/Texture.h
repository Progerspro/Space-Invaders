#pragma once
#include "Load.h"
class Texture :
    public Load
{
private:
    std::map<std::string,SDL_Surface*> Texture_SurfaceContainer;
public:
    Texture();
    ~Texture();
    
};

