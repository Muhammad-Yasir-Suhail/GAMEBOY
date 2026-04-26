#pragma once
#include "Point.h"
class Grid {
public:
    static int getWidth();
    static int getHeight();
    static int getBlockSize();
    static bool CheckBoundary(const Point& point);
};
