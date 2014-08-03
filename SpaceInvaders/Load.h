#pragma once

#include <map>


class Load
{
private:
    bool IsSuccess;
    SDL_Renderer* LocalRender = nullptr;
protected:
    std::map<std::string, SDL_Texture*> TextureContainer;
    std::map<std::string,SDL_Surface*> SurfaceContainer;
public:
    Load();
    ~Load();
    bool InitIMG(int Flag);
    bool InitTTF();
  
    bool GetRenderer(SDL_Renderer* Renderer);


    bool LoadTexture(std::string ID);
    void GetTexture();
    void ShowTexture();



};

