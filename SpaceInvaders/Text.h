#pragma once
#include "Load.h"
class Text :
    public Load
{
private:
    bool Success;
    SDL_Surface* Text_Surface = nullptr;
    TTF_Font* Font = nullptr;
    int Text_Width, Text_Height;
public:
    ~Text();
    bool Init(std::string Path_To_Font, int Font_Size);
    bool LoadSurfaceFromText(std::string Path, std::string MyText, SDL_Color TextColour);
    bool LoadTexture(std::string ID);
    SDL_Texture* GetTexture(std::string ID);
  
    int GetTextWidth(std::string ID);
    int GetTextHeight(std::string ID);
};

