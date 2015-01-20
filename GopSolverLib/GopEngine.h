#pragma once

#include <deque>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <string>
#include "GameState.h"
#include "GopArray.h"
#include "Point.h"

enum class Tile { Floor, Wall, Rock, Water, PanelW, PanelS, PanelSW, MiniPillar1, MiniPillar2, Invalid };
enum class PathMode { Sight, Orb, Player };

inline bool isInRange(int x, int y) { return x >= -GRID_MAX && x <= GRID_MAX && y >= -GRID_MAX && y <= GRID_MAX; }
inline bool isInRange(Point p) { return isInRange(p.x, p.y); }

class GameStateNode;

class GopEngine
{
public:
	static Tile get(int x, int y);
	static void clear();
	static void loadAltar(const char* data);
	static void loadAltarFromFile(std::string path);
	static bool isPassable(Point p, PathMode mode);
	static bool canMoveWest(Point p, PathMode mode);
	static bool canMoveWest(int x, int y, PathMode mode);
	static bool canMoveSouth(Point p, PathMode mode);
	static bool canMoveSouth(int x, int y, PathMode mode);
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
	static std::vector<std::shared_ptr<GameStateNode>> solve(const GameState& initialState, bool attractOnly = false, int* pNumExpanded = nullptr, bool debug = false);

	static const int MAX_REACH_DISTANCE = 10;
	static const int MAX_REPEL_REACH_DISTANCE = MAX_REACH_DISTANCE - 2;

private:
	static void calculateTables();
	static GopArray<Tile> grid;
	static GopArray<std::vector<Point>> neighbors[3];
	static GopArray<int> distancesToAltarTable;
};

class GameStateNode
{
public:
	GameState state;
	GameAction action;
	std::shared_ptr<GameStateNode> parent;
	int cost;
	bool attractOnly;

	GameStateNode(GameState state, GameAction action, bool attractOnly = false, std::shared_ptr<GameStateNode> parent = nullptr, int cost = 0, int numSteps = 0)
		: state(state), action(action), parent(parent), cost(cost), attractOnly(attractOnly)
	{
		for (int i = 0; i < numSteps; i++)
		{
			this->state.player.action = action;
			this->state.step();
			// Update new attract
			this->action = this->state.player.action;
		}
	}

	double getHeuristicCost() const;
	std::deque<std::pair<GameState, GameAction>> getPath() const;
	std::string getActions() const;

	static std::string getActions(std::deque<std::pair<GameState, GameAction>> path);
};

struct CompareNode : public std::binary_function<std::shared_ptr<GameStateNode>, std::shared_ptr<GameStateNode>, bool>
{
	bool operator()(const std::shared_ptr<GameStateNode>& lhs, const std::shared_ptr<GameStateNode>& rhs) const
	{
		return lhs->getHeuristicCost() > rhs->getHeuristicCost();
	}
};
