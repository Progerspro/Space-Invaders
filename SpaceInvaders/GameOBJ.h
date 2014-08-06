#pragma once

#include "Texture.h"

class GameOBJ
{
private:
    int m_x, m_y;
    int m_Width, m_Height;
    std::string m_TextureID;
    int m_CurrentFrame;
    int m_CurrentRaw; 
    SDL_Texture* Obj = nullptr;

public:
	GameOBJ();
	~GameOBJ();
    void Push_Objects(std::string Texture_P, std::string ID);
    //TODO: Load and draw textures 
    void Load(int x,int y,int Width,int Height, std::string TextureID);
    void Draw();
    void FrameDraw();
    void Clear();

};

