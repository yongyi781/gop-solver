#include "stdafx.h"
#include "Point.h"

Point Point::operator+=(const Point& other) { x += other.x; y += other.y; return *this; }
Point Point::operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
Point Point::operator-=(const Point& other) { x -= other.x; y -= other.y; return *this; }
Point Point::operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
Point Point::operator-() const { return Point(-x, -y); }
bool Point::operator==(const Point& other) const { return x == other.x && y == other.y; }
bool Point::operator!=(const Point& other) const { return x != other.x || y != other.y; }
bool Point::operator<(const Point& other) const { return y == other.y ? x < other.x : y < other.y; }

void Point::offset(int dx, int dy) { x += dx; y += dy; }
void Point::offset(const Point& p) { offset(p.x, p.y); }
int Point::distanceSquaredTo(const Point& other) const { return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y); }
int Point::walkingDistanceTo(const Point& other) const { return std::max(abs(x - other.x), abs(y - other.y)); }

std::string Point::toString() const
{
	if (*this == Point::invalid)
		return "()";
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

Point Point::parse(std::string str)
{
	if (str[0] == '(')
		str = str.substr(1, str.size() - 2);
	std::istringstream iss{ str };
	int x, y;
	iss >> x;
	iss.ignore(1);
	iss >> y;
	return{ x, y };
}

const Point Point::zero = Point(0, 0);
const Point Point::west = Point(-1, 0);
const Point Point::east = Point(1, 0);
const Point Point::south = Point(0, -1);
const Point Point::north = Point(0, 1);
const Point Point::invalid = Point(INT_MIN, INT_MIN);
const Point Point::offsets[OFFSETS_LENGTH] = { west, east, south, north, west + south, west + north, east + south, east + north };
const Point Point::pointsAdjacentToAltar[16] = { Point(-2, -2), Point(-1, -2), Point(0, -2), Point(1, -2), Point(2, -2), Point(-2, -1), Point(2, -1), Point(-2, 0), Point(2, 0), Point(-2, 1), Point(2, 1), Point(-2, 2), Point(-1, 2), Point(0, 2), Point(1, 2), Point(2, 2) };
