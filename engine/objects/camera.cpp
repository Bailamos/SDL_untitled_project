#include "engine/math/point.hpp"
#include "engine/objects/camera.hpp"
#include "engine/objects/transform.hpp"

Camera::Camera(Point position, int height, int width) : Transform(position.x, position.y, height, width){};

Point Camera::worldPositionToCameraPosition(Transform *transform)
{
    Point cameraPosition = this->getPosition();
    Point transformPosition = transform->getPosition();
    return Point(
        cameraPosition.x - transformPosition.x + this->width / 2,
        cameraPosition.y - transformPosition.y + this->height / 2);
};