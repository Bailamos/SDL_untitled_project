#include "colliders/collider.hpp"
#include "math/point.hpp"

class GameObject
{
public:
    GameObject();
    GameObject(int x, int y);
    GameObject(int x, int y, Collider *collider, SDL_Texture *texture);
    ~GameObject();
    void onUpdate();
    void draw(SDL_Renderer *renderer);

private:
    Point position;
    Collider *collider;
    SDL_Texture *texture;
};