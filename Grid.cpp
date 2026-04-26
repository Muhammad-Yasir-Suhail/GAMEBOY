#include "Grid.h"
#include "Point.h"
int Grid::getWidth() {
    return 800;
}

int Grid::getHeight() {
    return 600;
}

int Grid::getBlockSize() {
    return 20;
}

bool Grid::CheckBoundary(const Point& point) {
    return point.getX() < 0 || point.getX() >= getWidth() || point.getY() < 0 || point.getY() >= getHeight();
}
