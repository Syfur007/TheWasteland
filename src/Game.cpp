#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture *playerTex;

SDL_Rect sourceR, destR;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        SDL_Log("SDL Initialized successfully.");
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
        if (window)
        {
            SDL_Log("Window created successfully.");
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_Log("Renderer created successfully.");
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    playerTex = TextureManager::LoadTexture("../../../assets/spaceship.png", renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update()
{
    destR.h = 99;
    destR.w = 129;
    destR.x = cnt;
    SDL_Log("CNT: %d", cnt++);
}

void Game::render()
{
    SDL_RenderClear(renderer);

    // Render stuff here
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    SDL_Log("Game cleaned.");
}
