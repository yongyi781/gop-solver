#pragma once

class Point;
class GameAction;
class Orb;
class Player;
class GameState;

namespace std
{
	template<> struct hash<Point>
	{
		size_t operator()(const Point p) const;
	};

	template<> struct hash<pair<Point, Point>>
	{
		size_t operator()(const pair<Point, Point> p) const;
	};

	template<> struct hash<GameAction>
	{
		size_t operator()(const GameAction& action) const;
	};

	template<> struct hash<Orb>
	{
		size_t operator()(const Orb& orb) const;
	};

	template<> struct hash<Player>
	{
		size_t operator()(const Player& player) const;
	};

	template<> struct hash<GameState>
	{
		size_t operator()(const GameState& s) const;
	};
}
