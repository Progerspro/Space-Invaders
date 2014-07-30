#pragma once
class Game
{
public:
	Game();
	~Game();
	void Init();
	void Render();
	void Update();
	void HandleEvents();
	void Quit();
};

