#include "treeMapTile.hpp"
#include "engine/objects/textureType.hpp"
#include "engine/colliders/hexagonalCollider.hpp"
#include "src/constants.hpp"
#include "math.h"

TreeMapTile::TreeMapTile(int posX, int posY, TextureLoader *textureLoader)
    : GameObject::GameObject(posX, posY, MAP_TILE_WIDTH, MAP_TILE_HEIGHT, textureLoader->getTexture(Tree))
{
    Collider *collider = new HexagonalCollider(posX, posY, 0.5 * MAP_TILE_HEIGHT);
    this->setCollider(collider);
}
