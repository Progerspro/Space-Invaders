#include "stdafx.h"
#include "Text.h"




Text::~Text()
{
}

bool Text::Init(std::string Path_To_Font,int Font_Size)
{
    //Init ttf
    if (TTF_Init() == -1)
    {
        std::cerr << "Could not init ttf because of TTF_GetError =  " << TTF_GetError << std::endl;
        Success = false;
    }
    else
    {
        std::cout << " Success Init TTF " << std::endl;
        Success = true;
    }
    //Open Font

    Font = TTF_OpenFont(Path_To_Font.c_str(), Font_Size);
    if (Font == nullptr)
    {
        std::cerr << "Could not open Font because of TTF_GetError =  " << TTF_GetError << std::endl;
        Success = false;
    }
    else
    {
        std::cout << " Success Open Font " << std::endl;
        Success = true;
    }

    return Success;
}

bool Text::LoadSurfaceFromText(std::string Path,std::string MyText,SDL_Color TextColour = {0,0,0})
{
    Text_Surface = TTF_RenderText_Solid(Font, MyText.c_str(), TextColour);
    if (Text_Surface == nullptr)
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



void Text::LoadTexture(std::string ID)
{
    Load::LoadTexture(ID, Text_Surface);
   
    SDL_FreeSurface(Text_Surface);
    Text_Surface = nullptr;
}

SDL_Texture* Text::GetTexture(std::string ID)
{
    return Load::GetTexture(ID);
}

int Text::GetTextWidth(std::string ID)
{
    SDL_QueryTexture(GetTexture(ID), NULL, NULL, &Text_Width, NULL);
    return Text_Width;
}

int Text::GetTextHeight(std::string ID)
{
    SDL_QueryTexture(GetTexture(ID), NULL, NULL, NULL, &Text_Height);
    return Text_Height;
}
