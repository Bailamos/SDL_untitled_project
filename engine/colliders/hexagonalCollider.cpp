#include "engine/colliders/hexagonalCollider.hpp"
#include "engine/math/geometryHelpers.hpp"
#include "math.h"
#include "SDL_image.h"

HexagonalCollider::HexagonalCollider()
{
}

HexagonalCollider::HexagonalCollider(int centerX, int centerY, int length)
{
    vertexes = new Point[6];
    this->sideLength = length;

    this->setPosition(centerX, centerY);
}

void HexagonalCollider::setPosition(int x, int y)
{
    const int h = sqrt(3) * this->sideLength / 2;

    vertexes[0] = Point(x, y - this->sideLength);
    vertexes[1] = Point(x + h, y - (this->sideLength / 2));
    vertexes[2] = Point(x + h, y + (this->sideLength / 2));
    vertexes[3] = Point(x, y + this->sideLength);
    vertexes[4] = Point(x - h, y + (this->sideLength / 2));
    vertexes[5] = Point(x - h, y - (this->sideLength / 2));

    Point boundingBoxTopLeft = Point(x - h, y - this->sideLength);
    Point boundingBoxBottomRight = Point(x + h, y + this->sideLength);
    this->boundingBox[0] = boundingBoxTopLeft;
    this->boundingBox[1] = boundingBoxBottomRight;
}

bool HexagonalCollider::isPointInsideCollider(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        Point v1 = vertexes[i];
        Point v2 = vertexes[(i + 1) % 6];
        const bool isPointInsideCollider = GEOMETRY_HELPERS::isPointInTriangle(
            Point(x, y),
            Point(this->centerX, this->centerY),
            v1,
            v2);

        if (isPointInsideCollider)
        {
            return true;
        }
    }
    return false;
}

void HexagonalCollider::render(SDL_Renderer *renderer)
{
    SDL_FPoint points[7];
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i = 0; i < 6; i++)
    {
        points[i] = SDL_FPoint();
        points[i].x = (float)this->vertexes[i].x;
        points[i].y = (float)this->vertexes[i].y;
    }
    points[6] = points[0];
    SDL_RenderDrawLinesF(renderer, points, 7);
    this->renderBoundingBox(renderer);
}

void HexagonalCollider::renderBoundingBox(SDL_Renderer *renderer)
{
    SDL_RenderDrawLine(renderer, boundingBox[0].x, boundingBox[0].y, boundingBox[1].x, boundingBox[0].y);
    SDL_RenderDrawLine(renderer, boundingBox[1].x, boundingBox[0].y, boundingBox[1].x, boundingBox[1].y);
    SDL_RenderDrawLine(renderer, boundingBox[1].x, boundingBox[1].y, boundingBox[0].x, boundingBox[1].y);
    SDL_RenderDrawLine(renderer, boundingBox[0].x, boundingBox[1].y, boundingBox[0].x, boundingBox[0].y);
}

Point *HexagonalCollider::getBoundingBox()
{
    return this->boundingBox;
}