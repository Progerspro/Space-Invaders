#pragma once
class GameOBJ
{
private:
    int x, y;
    int Width, Height;
    std::string TextureID;
    int CurrentFrame;
    int CurrentRaw;

public:
	GameOBJ();
	~GameOBJ();
    //TODO: Load and draw textures 
    void Draw();
    void FrameDraw();

};

