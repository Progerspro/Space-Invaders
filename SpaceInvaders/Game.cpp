#include "stdafx.h"
#include "Game.h"


Game::Game()
{
    IsRunning = true;
}


Game::~Game()
{
}

bool Game::GameRunning()
{
    return IsRunning;
}


void Game::Init(std::string WindowTitle, int PosX, int PosY, int Width, int Height, int Flag)
{
    
    if (SDL_INIT_EVERYTHING > 0)
    {
        std::cerr << "Could not init Everything because of the SDL_GetError = " << SDL_GetError << std::endl;
    }
    else
    {
        std::cout << "Init Everything Success!" << std::endl;
        P_Window = SDL_CreateWindow(WindowTitle.c_str(), PosX, PosY, Width, Height, Flag);
        if (P_Window == nullptr)
        {
            std::cerr << "Could not Create Window because of SDL_GetError = " << SDL_GetError << std::endl;
        }
        else
        {
            std::cout << "Success Creating Window!" << std::endl;
            P_Renderer = SDL_CreateRenderer(P_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (P_Renderer == nullptr)
            {
                std::cerr << "Could not Create Renderer because of SDL_GetError = " << SDL_GetError << std::endl;
            }
            else
            {
                std::cout << "Success Creating Renderer!" << std::endl;
                Load::Instance()->Init(P_Renderer);
            }
        }
    }

}

void Game::Render()
{
    if (SDL_SetRenderDrawColor(P_Renderer, 255, 255, 255, 255) == -1)
        std::cerr << "Could not SetRenderDrawColor! because of SDL_GetError = " << SDL_GetError << std::endl;
    //TODO: Make The rendering for everything here

}

void Game::Update()
{
}

void Game::HandleEvents()
{
    if(SDL_PollEvent(&Event) !=0)
    {
        if (Event.type == SDL_QUIT)
            IsRunning = false;
    }
}

void Game::Quit()
{
    SDL_DestroyWindow(P_Window);
    SDL_DestroyRenderer(P_Renderer);
    P_Window = nullptr;
    P_Renderer = nullptr;
    SDL_Quit();
}