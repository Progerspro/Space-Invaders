#include "stdafx.h"
#include "Player.h"


Player* Player::ThisInstance = nullptr;

Player::~Player()
{
}

Player* Player::Instance()
{
	if (ThisInstance == nullptr)
		ThisInstance = new Player;
	return ThisInstance;
}

void Player::Init(SDL_Renderer* P_Render)
{
	GameOBJ::Init(P_Render);
}

void Player::Load()
{

}
