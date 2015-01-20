#pragma once

#include <xutility>

class Point
{
public:
	Point() { }
	Point(int x, int y) : x(x), y(y) { }

	Point operator+=(const Point& other);
	Point operator-=(const Point& other);

	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	Point operator-() const;
	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
	bool operator<(const Point& other) const;

	void offset(int dx, int dy);
	void offset(const Point& p);
	int distanceSquaredTo(const Point& other) const;
	int walkingDistanceTo(const Point& other) const;

	std::string toString() const;
	static Point parse(std::string str);

	int x, y;

	static const Point zero, west, east, south, north, invalid;
	static const int OFFSETS_LENGTH = 8;
	static const Point offsets[OFFSETS_LENGTH];
	static const Point pointsAdjacentToAltar[16];
};

namespace std
{
	template<> struct hash<Point>
	{
		size_t operator()(const Point& p) const { return (31 + p.x) * 31 + p.y; }
	};

	template<> struct hash<pair<Point, Point>>
	{
		size_t operator()(const pair<Point, Point>& p) const { return (31 + hash<Point>()(p.first)) * 31 + hash<Point>()(p.second); }
	};
}
