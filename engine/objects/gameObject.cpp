#include "engine/headers/objects/gameObject.hpp"
#include "engine/headers/math/point.hpp"

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
    //TODO;
    this->collider->render(renderer);
}
