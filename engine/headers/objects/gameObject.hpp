#include "engine/headers/colliders/collider.hpp"
#include "engine/headers/math/point.hpp"

class GameObject
{
public:
    GameObject();
    GameObject(int x, int y);
    GameObject(int x, int y, Collider *collider, SDL_Texture *texture);
    ~GameObject();
    void onUpdate();
    void render(SDL_Renderer *renderer);

private:
    Point position;
    Collider *collider = NULL;
    SDL_Texture *texture = NULL;
};