#include "src/entities/map.hpp"
#include "src/entities/treeMapTile.hpp"
#include "src/constants.hpp"

Map::Map(int x, int y, TextureLoader *textureLoader) : GameObject(x, y)
{
    for (int i = 0; i < 3; i++)
    {
        GameObject *tile = new TreeMapTile(0, 0 - MAP_TILE_HEIGHT * i, textureLoader);
        this->addChildren(tile);
    }
}