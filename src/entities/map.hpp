#ifndef MAP_H
#define MAP_H

#include "engine/objects/gameObject.hpp"
#include "engine/objects/textureLoader.hpp"

class Map : public GameObject
{
public:
    Map(int x, int y, TextureLoader *textureLoader);
};

#endif