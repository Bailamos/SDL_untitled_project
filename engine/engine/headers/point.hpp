#ifndef POINT_H_
#define POINT_H_

struct Point {
    int x;
    int y;

    Point() {
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

#endif