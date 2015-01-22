#pragma once

#include "GameAction.h"

class Orb
{
public:
	Orb(Point location = Point::invalid, Point target = Point::invalid);

	bool operator==(const Orb& other) const;
	bool operator!=(const Orb& other) const;

	std::string toString() const;

	Point location;
	Point target;
};

class Player
{
public:
	Player(Point location = Point::invalid);

	bool operator==(const Player& other) const;

	void stopAttracting();
	void freeze();
	void stepMove(bool isSecondAttract = false);

	std::string toString() const;

	Point location = Point::invalid;
	bool run = true;
	bool repel = false;
	int currentOrb = -1;
	bool delayAttractFromMoving = false;
	bool delayAttractFromPrototick = false;
	std::deque<Point> movePath;
	bool isAttracting = false;
	int forceAttractOrb = -1;
	int holdLength = 0;
	// The below are not tested for in equality.
	// To prevent moving twice
	bool hasMovedThisTick = false;
	Point lastMoveTarget = Point::invalid;
	Point lastAttractTarget = Point::invalid;
	Point lastOrbClickLocation = Point::invalid;
	GameAction action = GameAction::idle();
	GameAction previousAction = GameAction::idle();
};

class GameState
{
public:
	GameState() {}
	GameState(Player player, std::vector<Orb> orbs);

	// Tests where two game states are equal.
	bool operator==(const GameState& other) const;
	bool operator!=(const GameState& other) const;

	std::string toString() const;

	// Stops all movement, and optionally orb movements.
	void freeze(bool freezeOrbs = true);
	// Steps one tick.
	void step();
	void stepOrb(Orb& orb);
	void stepPlayer(Player& player);
	void stepAttract(Player& player, bool isSecondAttract = false);
	void forceAttractNextTick(Player& player, int orbIndex);
	void attractSuccess(Player& player, int orbIndex);
	bool needsToMoveForOrb(const Orb & orb) const;
	int getHeuristicCostSingleOrb(const Orb & orb, bool attractOnly) const;
	int getTwoTickHoldCost(int distances[], int currentOrb, bool prototick) const;
	int getHeuristicCost(bool attractOnly) const;

	// Single player for now
	Player player;
	std::vector<Orb> orbs;
};

namespace std
{
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
