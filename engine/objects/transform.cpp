#include "engine/objects/transform.hpp"

Transform::Transform()
{
    this->height = 0;
    this->width = 0;
}

Transform::Transform(int x, int y, int height, int width)
{
    this->position = Point(x, y);
    this->height = height;
    this->width = width;
}

void Transform::setPosition(int x, int y)
{
    this->position.x = x;
    this->position.y = y;
}

Point Transform::getPosition()
{
    return this->position;
}

Point Transform::move(int x, int y)
{
    this->position.x += x;
    this->position.y += y;
}