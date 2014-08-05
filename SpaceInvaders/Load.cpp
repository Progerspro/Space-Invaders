#include "stdafx.h"
#include "Load.h"



Load* Load::ThisInstance = nullptr;


Load::Load()
{
}

Load::~Load()
{
}

bool Load::InitIMG(const int Flag)
{
    static bool IsRepeatCall = false;

    if (IsRepeatCall == true)
        IMG_Quit();

    if (IMG_Init(Flag) == 0)
    {
        std::cerr << "Could not init image with flag = " << Flag << "\nWith Img_GetError = " << IMG_GetError() << std::endl;
        IsSuccess = false;
    }
    else
    {
        std::cout << "Successful Image Init with flag = " << Flag << std::endl;
        IsRepeatCall = true;
        IsSuccess = true;
    }
    return IsSuccess;
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



bool Load::LoadTexture(std::string ID,SDL_Surface* Surface)
{
    TextureContainer[ID] = SDL_CreateTextureFromSurface(LocalRender, Surface);
    if (TextureContainer[ID] == nullptr)
    {
        std::cerr << "Could not load texture because it's load nothing from SurfaceContainer" << std::endl;
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
    SDL_DestroyTexture(Return_Temp_Texture);
    Return_Temp_Texture = nullptr;

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


