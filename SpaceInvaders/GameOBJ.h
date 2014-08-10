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
	static GameOBJ* ThisOBJ;
	
protected:
	SDL_Renderer* LocalRender;
	GameOBJ();
public:
	
	~GameOBJ();
    void Push_Objects(std::string Texture_P, std::string ID);
	static GameOBJ* Instance();
    //TODO: Load and draw textures 
  virtual void Init(SDL_Renderer* P_Render);
   virtual void Load(int x,int y,int Width,int Height, std::string TextureID);
   virtual void Draw();
   virtual void FrameDraw(int Raw=0,int Frame=0);
  // virtual void Clear();

};

