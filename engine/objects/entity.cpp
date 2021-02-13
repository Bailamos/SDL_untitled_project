#include "objects/entity.hpp"
#include <stdio.h>

Entity::Entity(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Entity::toString()
{
    printf("Coordinates of Entity are: %i, %i", this->x, this->y);
}