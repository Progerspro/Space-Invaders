#include "stdafx.h"
#include "Texture.h"


Texture* Texture::Texture_Instance = nullptr;


Texture::~Texture()
{
}

Texture* Texture::Instance()
{
    if (Texture_Instance = nullptr)
    {
        Texture_Instance = new Texture;
    }
    return Texture_Instance;
}

bool Texture::LoadSurface(std::string Path)
{
    Texture_Surface = IMG_Load(Path.c_str());
    if (Texture_Surface == nullptr)
    {
        std::cerr << "Could not create surface because of Img_GetError =  " << IMG_GetError << std::endl;
        Success = false;
    }
    else
    {
        std::cout << "Success Creating Surface " << std::endl;
        Success = true;
    }
    return Success;
}



void Texture::PushTexture(std::string ID)
{
    Load::PushTexture(ID, Texture_Surface);
    SDL_FreeSurface(Texture_Surface);
    Texture_Surface = nullptr;
}

SDL_Texture* Texture::GetTexture(std::string ID)
{
    return Load::GetTexture(ID);
}
