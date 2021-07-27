#ifndef COLLIDER_H_
#define COLLIDER_H_
#include <SDL.h>
#include "engine/math/point.hpp"

class Collider
{
public:
    virtual bool isPointInsideCollider(int centerX, int centerY) = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
    virtual void renderBoundingBox(SDL_Renderer *renderer) = 0;
    virtual Point *getBoundingBox() = 0;
    virtual void setPosition(int x, int y) = 0;

private:
    Point boundingBox[2];
};
#endif