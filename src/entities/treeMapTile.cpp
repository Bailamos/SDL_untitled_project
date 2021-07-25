#include "TreeMapTile.hpp"
#include "engine/objects/textureType.hpp"
#include "src/constants.hpp"

TreeMapTile::TreeMapTile(int posX, int posY, TextureLoader *textureLoader)
    : GameObject::GameObject(posX, posY, MAP_TILE_WIDTH, MAP_TILE_HEIGHT, textureLoader->getTexture(Tree))
{
}
