#include "src/entities/map.hpp"
#include "src/entities/treeMapTile.hpp"
#include "src/constants.hpp"

Map::Map(int x, int y, TextureLoader *textureLoader) : GameObject(x, y)
{
    this->addChildren(new TreeMapTile(0, 0, textureLoader));
    this->addChildren(new TreeMapTile(100, 0, textureLoader));
}