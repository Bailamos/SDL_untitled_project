#ifndef CAMERA_H
#define CAMERA_H

#include "engine/math/point.hpp"
#include "engine/objects/gameObject.hpp"

class Camera : public GameObject
{
public:
    Camera(Point position, int height, int width);
};

#endif