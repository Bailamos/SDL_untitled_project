#include <vector>
#include "engine/objects/gameObject.hpp"
#include "engine/colliders/hexagonalCollider.hpp"
#include "engine/objects/textureLoader.hpp"

class Game
{
public:
    Game();
    ~Game();
    void start();
    void handleInput();
    void update();
    void render();
    bool isGameRunning();

private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    TextureLoader *textureLoader;
    std::vector<GameObject *> gameObjects;
    bool mIsGameRunning;

    void initWorld();
};