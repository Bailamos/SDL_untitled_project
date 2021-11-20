#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector"
#include "engine/colliders/collider.hpp"
#include "engine/math/point.hpp"
#include "engine/objects/transform.hpp"

class Camera;

class GameObject : public Transform
{
public:
    GameObject();
    GameObject(int x, int y);
    GameObject(int x, int y, Collider *collider, SDL_Texture *texture);
    GameObject(int x, int y, int width, int height, SDL_Texture *texture);
    ~GameObject();
    void onUpdate();
    void render(SDL_Renderer *renderer, Camera *camera);
    SDL_Rect getDisplayRect(Camera *camera);
    void setCollider(Collider *collider);
    void setPosition(int x, int y);
    void addChildren(GameObject *gameObject);

private:
    Collider *collider = NULL;
    SDL_Texture *texture = NULL;
    std::vector<GameObject *> children;
};

#endif