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

enum class HoldState : uint8_t { None, Tap, Hold };

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
	HoldState holdState = HoldState::None;
	// The below are not tested for in equality.
	Point lastMoveTarget = Point::invalid;
	Point lastAttractTarget = Point::invalid;
	Point lastOrbClickLocation = Point::invalid;
	GameAction action = GameAction::idle();
	GameAction previousAction = GameAction::idle();
	// To prevent moving twice
	bool hasMovedThisTick = false;
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
	int getHeuristicCostSingleOrb(const Orb & orb) const;
	int getTwoTickHoldCost(int distances[], int currentOrb, bool prototick) const;
	int getHeuristicCost() const;

	// Single player for now
	Player player;
	std::vector<Orb> orbs;
};
