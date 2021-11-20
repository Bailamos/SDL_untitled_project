#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "engine/math/point.hpp"

class Transform
{
protected:
    Point position;
    void setPosition(int x, int y);

public:
    int width, height;
    Transform();
    Transform(int x, int y, int width, int height);

    Point getPosition();
    Point move(int x, int y);
};

#endif