#include "Grid.h"
//Grid::Grid(int r, int c) :row(r), col(c) {}
bool Grid::CheckBoundary(Point& point) {
	if (point.getX() < 0 || point.getX() >= width || point.getY() < 0 || point.getY() >= height) {
		return 1;
	}
	else {
		return 0;
	}
}

