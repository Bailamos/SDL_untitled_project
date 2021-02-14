#include "vector"
#include "engine/headers/objects/gameObject.hpp"

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
    bool mIsGameRunning;
};