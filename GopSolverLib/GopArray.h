#pragma once

#include "Point.h"

const int GRID_SIZE = 53;
const int GRID_MAX = GRID_SIZE / 2;

template<class T>
class GopArray
{
public:
	GopArray() { clear(); }

	T& operator[](Point p) { return data[GRID_MAX - p.y][GRID_MAX + p.x]; }
	T get(int x, int y) const { return data[GRID_MAX - y][GRID_MAX + x]; }
	void set(int x, int y, T value) { data[GRID_MAX - y][GRID_MAX + x] = value; }
	void clear()
	{
		for (int y = 0; y < GRID_SIZE; ++y)
			for (int x = 0; x < GRID_SIZE; ++x)
				data[y][x] = T();
	}

	T data[GRID_SIZE][GRID_SIZE];
};
