#pragma once

#include <map>


class Load
{
private:
    bool IsSuccess;
    
   static Load* ThisInstance;
    
    SDL_Texture* Return_Temp_Texture = nullptr;
protected:
    std::map<std::string, SDL_Texture*> TextureContainer;
	std::map<std::string, SDL_Surface*> SurfaceContainer;
    SDL_Renderer* LocalRender = nullptr;
    Load();
public:
    
    ~Load();

    static Load* Instance();
    SDL_Renderer* GetRender();
    
    bool InitTTF();
    bool Init(SDL_Renderer* Renderer);
    bool PushTexture(std::string ID, SDL_Surface* Surface);
    SDL_Texture* GetTexture(std::string ID);
    

};

