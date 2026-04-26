#include "SnakeSegment.h"

SnakeSegment::SnakeSegment() : x(0), y(0) {}

SnakeSegment::SnakeSegment(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

int SnakeSegment::getPositionX() const {
    return x;
}
int SnakeSegment::getPositionY() const {
    return y;
}
void SnakeSegment::setPosition(const Point& point) {
    x = point.getX();
    y = point.getY();
}
