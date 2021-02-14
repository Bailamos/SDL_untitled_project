#include "objects/gameObject.hpp"
#include "math/point.hpp"

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

void GameObject::draw(SDL_Renderer *renderer)
{
    //TODO;
    this->collider->draw(renderer);
}
