#ifndef MAPTREETILE_H
#define MAPTREETILE_H

#include "engine/objects/gameObject.hpp"
#include "engine/objects/textureLoader.hpp"

class TreeMapTile : public GameObject
{
public:
    TreeMapTile(int posX, int posY, TextureLoader *textureLoader);
};

#endif