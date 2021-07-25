#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "game.hpp"
#include "engine/objects/textureType.hpp"

void Game::initWorld()
{

    for (int i = 0; i < 1; i++)
    {
        SDL_Texture *texture = this->textureLoader->getTexture(Tree);
        GameObject *gameObject = new GameObject(1, 2, texture);
        this->gameObjects.push_back(gameObject);
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
    for (auto &gameObject : this->gameObjects)
    {
        gameObject->render(this->renderer);
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

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        printf("SDL_image could not initialize: %s\n", IMG_GetError());
    }
    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
    this->textureLoader = new TextureLoader(this->renderer);
    this->mIsGameRunning = true;
}

Game::~Game()
{
    delete this->textureLoader;
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    for (auto gameObject : this->gameObjects)
    {
        delete gameObject;
    }
}