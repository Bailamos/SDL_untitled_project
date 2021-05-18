#include "engine/colliders/collider.hpp"
#include "engine/math/point.hpp"

class HexagonalCollider : public Collider
{
public:
    HexagonalCollider();
    HexagonalCollider(int centerX, int centerY, int length);
    bool isPointInsideCollider(int x, int y);
    void render(SDL_Renderer *renderer);
    void renderBoundingBox(SDL_Renderer *renderer);
    Point *getBoundingBox();

private:
    Point boundingBox[2];
    int centerX, centerY;
    Point *vertexes;
    int sign(Point p1, Point p2, Point p3);
    bool isPointInTriangle(Point pt, Point v1, Point v2, Point v3);
};