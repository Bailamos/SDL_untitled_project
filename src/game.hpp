#include "vector"
#include "engine/objects/gameObject.hpp"
#include "engine/colliders/hexagonalCollider.hpp"

class Game
{
public:
    Game();
    void start();
    void handleInput();
    void update();
    void render();
    bool isGameRunning();

private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    std::vector<GameObject *> gameObjects;
    std::vector<Collider *> world;
    bool mIsGameRunning;

    void initWorld();
};