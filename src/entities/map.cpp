#include "src/entities/map.hpp"
#include "src/entities/treeMapTile.hpp"
#include "src/constants.hpp"

Map::Map(int x, int y, TextureLoader *textureLoader) : GameObject(x, y)
{
    for (int j = 1; j <= 4; j++)
    {
        for (int i = 1; i <= 6; i++)
        {
            GameObject *tile;
            if (j % 2 == 0)
            {
                tile = new TreeMapTile(i * MAP_TILE_WIDTH - x, j * MAP_TILE_HEIGHT - y, textureLoader);
            }
            else
            {
                tile = new TreeMapTile(MAP_TILE_WIDTH / 2 + i * MAP_TILE_WIDTH - x, j * MAP_TILE_HEIGHT - y + 30, textureLoader);
            }
            this->addChildren(tile);
        }
    }
}