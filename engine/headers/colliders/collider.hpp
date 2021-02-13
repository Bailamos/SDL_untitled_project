#include <SDL.h>

class Collider
{
public:
    virtual bool isPointInsideCollider(int centerX, int centerY) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
};