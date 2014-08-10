#include "stdafx.h"
#include "GameOBJ.h"

GameOBJ* GameOBJ::ThisOBJ = nullptr;

GameOBJ::GameOBJ()
{
}


GameOBJ::~GameOBJ()
{
}

void GameOBJ::Push_Objects(std::string Texture_P,std::string ID)
{
    Texture::Instance()->LoadSurface(Texture_P);
    Texture::Instance()->PushTexture(ID);
}

void GameOBJ::Load(int x, int y, int Width, int Height, std::string TextureID)
{
    m_x = x;
    m_y = y;
    m_Width = Width;
    m_Height = Height;
    m_TextureID = TextureID;
    Obj = Texture::Instance()->GetTexture(TextureID);
}

void GameOBJ::Draw()
{
    SDL_Rect Src_Rect,Dest_Rect;
    Src_Rect.x = 0;
    Src_Rect.y = 0;
    Dest_Rect.w = Src_Rect.w = m_Width;
    Dest_Rect.h = Src_Rect.h = m_Height;
    Dest_Rect.x = m_x;
    Dest_Rect.y = m_y;
    SDL_RenderCopy(LocalRender, Obj, &Src_Rect, &Dest_Rect);
}

GameOBJ* GameOBJ::Instance()
{
	if (ThisOBJ == nullptr)
		ThisOBJ = new GameOBJ;
	return ThisOBJ;
}

void GameOBJ::Init(SDL_Renderer* P_Render)
{
	LocalRender = P_Render;
	Texture::Instance()->Init(P_Render);
}

void GameOBJ::FrameDraw(int Raw,int Frame)
{
	SDL_Rect Src_Rect, Dest_Rect;
	Src_Rect.x = m_Width * Frame;
	Src_Rect.y = m_Height * (Raw - 1);
	Dest_Rect.w = Src_Rect.w = m_Width;
	Dest_Rect.h = Src_Rect.h = m_Height;
	Dest_Rect.x = m_x;
	Dest_Rect.y = m_y;
	SDL_RenderCopyEx(LocalRender, Obj, &Src_Rect, &Dest_Rect,0,0,SDL_FLIP_NONE);
}
