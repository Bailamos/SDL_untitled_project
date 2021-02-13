#include <stdio.h>
#include <vector>
#include "entity.hpp"
#include "hexagonalCollider.hpp"

int x = 0;

void displayScene(SDL_Renderer *renderer, std::vector<Entity *> entities)
{
  // Set background color
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  HexagonalCollider *collider = new HexagonalCollider(100, 100, 50);
  printf("Collider: %d\n", collider->isPointInsideCollider(1, 1));
  collider->draw(renderer);
  SDL_RenderPresent(renderer);
}

int main(int argc, char *args[])
{
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  std::vector<Entity *> entities;

  for (int i = 0; i < 100; i++)
  {
    Entity *ptrEntity = new Entity(i, i);
    entities.push_back(ptrEntity);
  };

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else
  {
    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
    if (window == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
      SDL_Event event;
      bool quit = false;
      while (!quit)
      {
        while (SDL_PollEvent(&event))
        {
          if (event.type == SDL_KEYDOWN)
          {
            switch (event.key.keysym.sym)
            {
            case SDLK_q:
              quit = true;
              break;
            }
          }
        }
        displayScene(renderer, entities);
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}