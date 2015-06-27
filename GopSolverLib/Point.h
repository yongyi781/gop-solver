#pragma once

const int8_t GRID_SIZE = 53;
const int8_t GRID_MAX = GRID_SIZE / 2;

class Point
{
public:
	Point() { }
	Point(int8_t x, int8_t y) : x(x), y(y) { }

	Point operator+=(const Point& other);
	Point operator-=(const Point& other);

	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	Point operator-() const;
	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
	bool operator<(const Point& other) const;

	void offset(int8_t dx, int8_t dy);
	void offset(const Point& p);
	int distanceSquaredTo(const Point& other) const;
	int walkingDistanceTo(const Point& other) const;

	std::string toString() const;
	static Point parse(std::string str);

	int8_t x, y;

	static const Point zero, west, east, south, north, invalid;
	static const int OFFSETS_LENGTH = 8;
	static const Point offsets[OFFSETS_LENGTH];
	static const Point pointsAdjacentToAltar[16];
};
