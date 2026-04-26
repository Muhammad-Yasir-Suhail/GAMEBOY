#pragma once

#ifndef GRID_H
#define GRID_H

#include "Point.h"

	class Grid
	{
		
		static const int BlockSize = 10;
		static const int width = 850;
		static const int height = 600;
		

	public:
		Grid(){}
		Grid(int r, int c);
		static bool CheckBoundary(Point& point);
		

		
		static int getWidth() {
			return width;
		}
		static int getHeight() {
			return height;
		}
		static int getBlockSize() {
			return BlockSize;
		}
	};






#endif 



