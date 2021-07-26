#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "engine/colliders/collider.hpp"
#include "engine/math/point.hpp"

class GameObject
{
public:
    GameObject();
    GameObject(int x, int y);
    GameObject(int x, int y, Collider *collider, SDL_Texture *texture);
    GameObject(int x, int y, int width, int height, SDL_Texture *texture);
    ~GameObject();
    void onUpdate();
    void render(SDL_Renderer *renderer);
    SDL_Rect getDisplayRect();
    void setCollider(Collider *collider);

private:
    Point position;
    int width, height;
    Collider *collider = NULL;
    SDL_Texture *texture = NULL;
};

#endif