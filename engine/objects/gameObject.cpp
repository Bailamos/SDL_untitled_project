#include "SDL_image.h"
#include "string"
#include "engine/objects/gameObject.hpp"
#include "engine/objects/camera.hpp"

GameObject::GameObject()
{
    this->collider = NULL;
}

GameObject::GameObject(int x, int y) : GameObject()
{
    GameObject();
    this->position = Point(x, y);
}

GameObject::GameObject(int x, int y, Collider *collider, SDL_Texture *texture) : GameObject()
{
    this->position = Point(x, y);
    this->collider = collider;
    this->texture = texture;
}

GameObject::GameObject(int x, int y, int width, int height, SDL_Texture *texture) : GameObject()
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

void GameObject::render(SDL_Renderer *renderer, Camera *camera)
{
    if (this->texture != NULL)
    {
        SDL_Rect displayRect = getDisplayRect(camera);
        SDL_RenderCopy(renderer, this->texture, NULL, &displayRect);
    }

    // if (this->collider != NULL)
    // {
    //     this->collider->render(renderer);
    // }

    for (auto child : children)
    {
        child->render(renderer, camera);
    }
}

SDL_Rect GameObject::getDisplayRect(Camera *camera)
{
    Point worldPostion = camera->worldPositionToCameraPosition(this);
    const int top = worldPostion.y - height / 2;
    const int left = worldPostion.x - width / 2;
    return {left, top, width, height};
}

void GameObject::setCollider(Collider *collider)
{
    this->collider = collider;
}

void GameObject::setPosition(int x, int y)
{
    Transform::setPosition(x, y);

    if (this->collider != NULL)
    {
        this->collider->setPosition(x, y);
    }
}

void GameObject::addChildren(GameObject *gameObject)
{
    gameObject->setPosition(
        this->position.x + gameObject->position.x,
        this->position.y + gameObject->position.y);
    for (auto children : gameObject->children)
    {
        children->setPosition(
            children->position.x + this->position.x,
            children->position.y + this->position.y);
    }
    this->children.push_back(gameObject);
}
