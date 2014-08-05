// SpaceInvaders.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Load.h"
using namespace std;

const int SCREEN_WIDTH = 500, SCREEN_HEIGHT = 600;

int main(int argc, char* argv[])
{
    Game game;
    
	cout << "Starting Space Invaders!" << endl;
    game.Init("Space Invaders", 40, 40, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    while (game.GameRunning())
    {
        game.HandleEvents();
        game.Update();
        game.Render();
    }
    game.Quit();
	return 0;
}

