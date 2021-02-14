#include "headers/game.hpp"
#include <stdio.h>

void Game::start()
{
    while (mIsGameRunning)
    {
        this->handleInput();
        this->update();
        this->render();
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}

void Game::handleInput()
{
    //TODO
}

void Game::update()
{
    //TODO
}

void Game::render()
{
    SDL_RenderClear(this->renderer);
    for (auto &gameObject : this->gameObjects)
    {
        gameObject->render(this->renderer);
    }
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(this->renderer, 0, 0, 300, 300);
    SDL_RenderPresent(this->renderer);

    SDL_Delay(3000);
    this->mIsGameRunning = false;
}

bool Game::isGameRunning()
{
    return this->mIsGameRunning;
}

Game::Game()
{
    this->mIsGameRunning = false;
    this->renderer = renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    this->mIsGameRunning = true;
}
