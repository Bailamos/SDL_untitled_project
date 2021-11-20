#include "engine/objects/camera.hpp"
#include "engine/objects/gameObject.hpp"

Camera::Camera(Point position, int height, int width) : GameObject(position.x, position.y, height, width, nullptr){};