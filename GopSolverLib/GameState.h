#pragma once

#include "GameAction.h"

class Orb
{
public:
	Orb(Point location = Point::invalid, Point target = Point::invalid) : location(location), target(target) { }

	bool operator==(const Orb& other) const { return location == other.location && target == other.target; }
	bool operator!=(const Orb& other) const { return !(*this == other); }

	std::string toString() const
	{
		return "{" + location.toString() + "->" + target.toString() + "}";
	}

	Point location;
	Point target;
};

class Player
{
public:
	Player(Point location = Point::invalid) : location(location) { }

	bool operator==(const Player& other) const
	{
		return location == other.location
			&& run == other.run
			&& repel == other.repel
			&& currentOrb == other.currentOrb
			&& delayAttractFromMoving == other.delayAttractFromMoving
			&& delayAttractFromPrototick == other.delayAttractFromPrototick
			&& isAttracting == other.isAttracting
			&& forceAttractOrb == other.forceAttractOrb
			&& holdLength == other.holdLength;
	}

	std::string toString() const
	{
		return "{" + location.toString() + ",d:" + std::to_string(delayAttractFromMoving) + "}";
	}

	void stopAttracting();
	void freeze();
	void stepMove();

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
	int getTwoTickHoldCost(int distances[], int currentOrb, bool prototick) const;
	bool needsToMoveForOrb(const Orb & orb) const;
	double getHeuristicCostSingleOrb(const Orb & orb, bool attractOnly) const;
	double getHeuristicCost(bool attractOnly) const;

	// Single player for now
	Player player;
	std::vector<Orb> orbs;
};

namespace std
{
	template<> struct hash<GameAction>
	{
		inline size_t operator()(const GameAction& action) const
		{
			return action.hash();
		}
	};

	template<> struct hash<Orb>
	{
		inline size_t operator()(const Orb& orb) const
		{
			return hash<Point>()(orb.location) + 31 * (31 + hash<Point>()(orb.target));
		}
	};

	template<> struct hash<Player>
	{
		inline size_t operator()(const Player& player) const
		{
			return hash<Point>()(player.location) + 31 * (
				31 + hash<bool>()(player.run) + 31 * (
				31 + hash<bool>()(player.repel) + 31 * (
				31 + hash<int>()(player.currentOrb) + 31 * (
				31 + hash<bool>()(player.delayAttractFromMoving) + 31 * (
				31 + hash<bool>()(player.delayAttractFromPrototick) + 31 * (
				31 + hash<bool>()(player.isAttracting) + 31 * (
				31 + hash<int>()(player.forceAttractOrb) + 31 * (
				31 + hash<int>()(player.holdLength)))))))));
		}
	};

	template<> struct hash<GameState>
	{
		inline size_t operator()(const GameState& s) const
		{
			size_t h = hash<Player>()(s.player);
			for (auto& orb : s.orbs)
				h = (h + 31) * 31 + hash<Orb>()(orb);
			return h;
		}
	};
}
