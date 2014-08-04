#pragma once

#include <map>


class Load
{
private:
    bool IsSuccess;
    SDL_Renderer* LocalRender = nullptr;
    Load* ThisInstance = nullptr;
    Load();
protected:
    std::map<std::string, SDL_Texture*> TextureContainer;
public:
    
    ~Load();

    static Load* Instance();

    bool InitIMG(int Flag);
    bool InitTTF();
    bool Init(SDL_Renderer* Renderer);
    bool LoadTexture(std::string ID, SDL_Surface Surface);
    void GetTexture();
    void ShowTexture();

};

