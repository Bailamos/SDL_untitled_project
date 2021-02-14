#include "vector"
#include "objects/gameObject.hpp"

class Game
{
public:
    Game();
    void start();
    void addGameObject(GameObject *gameObject);
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