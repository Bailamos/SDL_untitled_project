#include "SDL_image.h"
#include "string"
#include "engine/objects/gameObject.hpp"

GameObject::GameObject()
{
}

GameObject::GameObject(int x, int y)
{
    this->position = Point(x, y);
}

GameObject::GameObject(int x, int y, Collider *collider, SDL_Texture *texture)
{
    this->position = Point(x, y);
    this->collider = collider;
    this->texture = texture;
}

GameObject::GameObject(int x, int y, int width, int height, SDL_Texture *texture)
{
    this->position = Point(x, y);
    this->width = width;
    this->height = height;
    this->collider = collider;
    this->texture = texture;
}

GameObject::~GameObject()
{
    delete this->collider;
}

void GameObject::onUpdate()
{
    // TODO;
}

void GameObject::render(SDL_Renderer *renderer)
{
    SDL_Rect displayRect = getDisplayRect();
    SDL_RenderCopy(renderer, this->texture, NULL, &displayRect);
}

SDL_Rect GameObject::getDisplayRect()
{
    int top = this->position.y - height / 2;
    int left = this->position.x - width / 2;
    return {left, top, width, height};
}