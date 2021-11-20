#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector"
#include "engine/colliders/collider.hpp"
#include "engine/math/point.hpp"

class Camera;

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
    void addChildren(GameObject *gameObject);
    void setPosition(int x, int y);
    Point getPosition();
    void test(Camera *camera);

private:
    Point position;
    int width, height;
    Collider *collider = NULL;
    SDL_Texture *texture = NULL;
    std::vector<GameObject *> children;
};

#endif