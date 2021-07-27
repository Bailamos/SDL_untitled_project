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
    if (this->texture != NULL)
    {
        SDL_Rect displayRect = getDisplayRect();
        SDL_RenderCopy(renderer, this->texture, NULL, &displayRect);
    }

    if (this->collider != NULL)
    {
        this->collider->render(renderer);
    }

    for (auto child : children)
    {
        child->render(renderer);
    }
}

SDL_Rect GameObject::getDisplayRect()
{
    const int top = this->position.y - height / 2;
    const int left = this->position.x - width / 2;
    return {left, top, width, height};
}

void GameObject::setCollider(Collider *collider)
{
    this->collider = collider;
}

void GameObject::setPosition(int x, int y)
{
    this->position.x = x;
    this->position.y = y;
    this->collider->setPosition(x, y);
}

void GameObject::addChildren(GameObject *gameObject)
{
    const int newPositionX = this->position.x + gameObject->position.x;
    const int newPositionY = this->position.y + gameObject->position.y;

    gameObject->setPosition(newPositionX, newPositionY);

    this->children.push_back(gameObject);
}