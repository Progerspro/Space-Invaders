#include "stdafx.h"
#include "Load.h"



Load* Load::ThisInstance = nullptr;


Load::Load()
{
}

Load::~Load()
{
}





bool Load::InitTTF()
{
    if (TTF_Init() == -1)
    {
        std::cerr << "Could not init TTF with TTF_GetError = " << TTF_GetError() << std::endl;
        IsSuccess = false;
    }
    else
    {
        std::cout << "Successful TTF Init!" << std::endl;
        IsSuccess = true;
    }
    return IsSuccess;
}

bool Load::Init(SDL_Renderer* Renderer)
{
    LocalRender = Renderer;
    if (LocalRender == nullptr)
    {
        std::cerr << "Could not get the Renderer" << std::endl;
        IsSuccess = false;
    }
    else
    {
        std::cout << "Renderer initialized successful!" << std::endl;
        IsSuccess = true;
    }
    return IsSuccess;
}



bool Load::PushTexture(std::string ID,SDL_Surface* Surface)
{
	SurfaceContainer[ID] = Surface;
    TextureContainer[ID] = SDL_CreateTextureFromSurface(LocalRender, SurfaceContainer[ID]);
    if (TextureContainer[ID] == NULL)
    {
        std::cerr << "Could not load texture because it's load nothing from Surface" << std::endl;
        IsSuccess = false;
    }
    else
    {
        std::cerr << "Texture load success!" << std::endl;
        IsSuccess = true;
    }
    return IsSuccess;
}

SDL_Texture* Load::GetTexture(std::string ID)
{
  

    Return_Temp_Texture = TextureContainer[ID];
    if (Return_Temp_Texture == nullptr)
    {
        std::cerr << "Could not take taxture with ID = " << ID << std::endl;
    }
    else
    {
        std::cout << "Success taking texture with ID = " << ID << std::endl;
        return Return_Temp_Texture;
    }
}

Load* Load::Instance()
{
    if (ThisInstance == nullptr)
    {
        ThisInstance = new Load();
    }
    return ThisInstance;
}

SDL_Renderer* Load::GetRender()
{
    return LocalRender;
}

