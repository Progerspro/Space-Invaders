#pragma once
#include "Load.h"
class Texture :
    public Load
{
private:
    std::map<std::string,SDL_Surface*> Texture_SurfaceContainer;
    SDL_Surface* Texture_Surface = nullptr;
    bool Success = true;
    static Texture* Texture_Instance;
public:
    ~Texture();
   static Texture* Instance();
   void Init(SDL_Renderer* Render);
   bool InitIMG(int Flag);
    bool LoadSurface(std::string Path);
    void PushTexture(std::string ID);
    SDL_Texture* GetTexture(std::string ID);
};

