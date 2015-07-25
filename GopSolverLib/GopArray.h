#pragma once

#include "Point.h"

template <class T>
class int8_to_int
{
public:
	using type = T;
};

template<>
class int8_to_int<int8_t>
{
public:
	using type = int;
};

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
			{
				if (x != -GRID_MAX)
					ostr << delim;
				ostr << (int8_to_int<T>::type)get(x, y);
			}
			ostr << "\n";
		}
		return ostr.str();
	}

	T data[GRID_SIZE][GRID_SIZE];
};
