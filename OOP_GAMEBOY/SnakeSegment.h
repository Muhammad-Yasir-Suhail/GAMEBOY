#pragma once
#include "Point.h"
class SnakeSegment {
private:
    int x, y;
public:
    SnakeSegment();
    SnakeSegment(int xCoord, int yCoord);
    int getPositionX() const;
    int getPositionY() const;
    void setPosition(const Point& point); 
};
