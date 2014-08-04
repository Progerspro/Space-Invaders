#include "stdafx.h"
#include "Load.h"





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



bool Load::LoadTexture(std::string ID,SDL_Surface Surface)
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

Load* Load::Instance()
{
    if (ThisInstance == nullptr)
    {
        ThisInstance = new Load;
    }
    return ThisInstance;
}


