#pragma once
#include "GameOBJ.h"
class Player :
	public GameOBJ
{
private:
	static Player* ThisInstance;
	
public:

	
	SDL_Renderer* ren;
	
	~Player();
	static Player* Instance();
	void Init(SDL_Renderer* P_Render);
	void Load();
	void Update();
	void FrameDraw();
};

