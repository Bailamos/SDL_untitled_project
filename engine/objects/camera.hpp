#ifndef CAMERA_H
#define CAMERA_H

#include "engine/objects/transform.hpp"

class Point;

class Camera : public Transform
{
public:
    Camera(Point position, int height, int width);

    Point worldPositionToCameraPosition(Transform *transform);
};

#endif