#pragma once

#include "GameState.h"
#include "GopArray.h"
#include "Point.h"

enum class Tile { Floor, Wall, Rock, Water, PanelW, PanelS, PanelSW, MiniPillar1, MiniPillar2, Invalid };
enum class PathMode { Sight, Orb, Player };

inline bool isInRange(int8_t x, int8_t y) { return x >= -GRID_MAX && x <= GRID_MAX && y >= -GRID_MAX && y <= GRID_MAX; }
inline bool isInRange(Point p) { return isInRange(p.x, p.y); }

class GameStateNode;

class GopBoard
{
public:
	static Tile get(int8_t x, int8_t y);
	static void clear();
	static void loadAltar(const char* data);
	static void loadAltarFromFile(std::string path);
	static bool isPassable(Point p, PathMode mode);
	static bool canMoveWest(Point p, PathMode mode);
	static bool canMoveSouth(Point p, PathMode mode);
	static bool canMove(Point p, Point d, PathMode mode, bool calculate = false);
	static Point getOrbOffset(Point diff, bool toPlayer = false);
	static Point nextOrbLocation(Point location, Point target);
	static bool canReach(Point p1, Point p2, bool repel = false);
	static int distanceToAltar(Point p);
	static int distanceToPoint(Point p1, Point p2);
	// Distance to any square that can reach this orb.
	static int distanceToReachable(Point p1, Point p2, bool repel = false);
	static bool isAdjacentToAltar(Point p);
	static bool isStateInGoal(const GameState& s);
	static std::deque<Point> getPlayerPath(Point p1, Point p2, bool clickOrb = false);
	static std::string gridStr();
	static bool willOrbScore(const Orb & orb);
	static const std::vector<Point>& getNeighbors(Point p, PathMode mode);

	static const int MAX_REACH_DISTANCE = 10;
	static const int MAX_REPEL_REACH_DISTANCE = MAX_REACH_DISTANCE - 2;

private:
	static void calculateTables();
	static GopArray<Tile> grid;
	static GopArray<std::vector<Point>> neighbors[3];
	static GopArray<int> distancesToAltarTable;
};