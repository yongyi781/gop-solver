#pragma once

#include "Point.h"

template<class T>
class GopArray
{
public:
	GopArray() { clear(); }

	T& operator[](Point p) { return data[GRID_MAX - p.y][GRID_MAX + p.x]; }
	T get(int8_t x, int8_t y) const { return data[GRID_MAX - y][GRID_MAX + x]; }
	void set(int8_t x, int8_t y, T value) { data[GRID_MAX - y][GRID_MAX + x] = value; }
	void clear()
	{
		for (int y = 0; y < GRID_SIZE; ++y)
			for (int x = 0; x < GRID_SIZE; ++x)
				data[y][x] = T();
	}

	std::string toString(std::string delim = "")
	{
		std::ostringstream ostr;
		for (int8_t y = GRID_MAX; y >= -GRID_MAX; --y)
		{
			for (int8_t x = -GRID_MAX; x <= GRID_MAX; ++x)
				ostr << (int)get(x, y) << delim;
			ostr << "\n";
		}
		return ostr.str();
	}

	T data[GRID_SIZE][GRID_SIZE];
};
