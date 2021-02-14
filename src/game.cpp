#include "headers/game.hpp"
#include <stdio.h>

void Game::initWorld()
{
    for (int i = 1; i <= 1; i++)
    {
        Collider *collider = new HexagonalCollider(150 * i, 150, 50);
        this->world.push_back(collider);
    }
}

void Game::start()
{
    this->initWorld();
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
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_q:
                this->mIsGameRunning = false;
                break;
            }
        }
    }
}

void Game::update()
{
    //TODO
}

void Game::render()
{
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    for (auto &collider : this->world)
    {
        SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
        collider->render(this->renderer);
        SDL_SetRenderDrawColor(this->renderer, 0, 100, 0, 100);
        collider->renderBoundingBox(this->renderer);
    }
    SDL_RenderPresent(this->renderer);
}

bool Game::isGameRunning()
{
    return this->mIsGameRunning;
}

Game::Game()
{
    this->mIsGameRunning = false;

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
    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
    this->mIsGameRunning = true;
}
