#include "stdafx.h"
#include "hash.h"
#include "Point.h"
#include "GameState.h"

namespace std
{
#ifdef _WIN64
	const size_t PRIME = 1099511628211ULL;
	const size_t OFFSET = 14695981039346656037ULL;
#else
	const size_t PRIME = 16777619U;
	const size_t OFFSET = 2166136261U;
#endif

	size_t hash<Point>::operator()(Point p) const
	{
		return ((p.y + GRID_MAX) * 53) + (p.x + GRID_MAX);
	}

	size_t hashPairOfPoints(Point p1, Point p2)
	{
		return (hash<Point>()(p1) * 2809) + hash<Point>()(p2);
	}

	size_t hash<pair<Point, Point>>::operator()(pair<Point, Point> p) const
	{
		return hashPairOfPoints(p.first, p.second);
	}

	size_t hash<GameAction>::operator()(const GameAction& action) const
	{
		size_t result = OFFSET;
		result = PRIME * (result ^ (size_t)action.getType());
		result = PRIME * (result ^ std::hash<Point>()(action.getLocation()));
		result = PRIME * (result ^ (size_t)action.getOrbIndex());
		result = PRIME * (result ^ (size_t)action.getToggleRun());
		result = PRIME * (result ^ (size_t)action.getChangeWand());
		result = PRIME * (result ^ (size_t)action.isNewAttract());
		return result;
	}

	size_t hash<Orb>::operator()(const Orb& orb) const
	{
		return hashPairOfPoints(orb.location, orb.target);
	}

	size_t hash<Player>::operator()(const Player& player) const
	{
		size_t result = OFFSET;
		result = PRIME * (result ^ hash<Point>()(player.location));
		result = PRIME * (result ^ (size_t)player.currentOrb);
		result = PRIME * (result ^ (size_t)player.delayAttractFromMoving);
		result = PRIME * (result ^ (size_t)player.delayAttractFromPrototick);
		result = PRIME * (result ^ (size_t)player.forceAttractOrb);
		result = PRIME * (result ^ (size_t)player.repel);
		result = PRIME * (result ^ (size_t)player.holdState);
		return result;
	}

	size_t hash<GameState>::operator()(const GameState& s) const
	{
		size_t result = OFFSET;
		result = PRIME * (result ^ hash<Player>()(s.player));
		for (auto& orb : s.orbs)
			result = PRIME * (result ^ hash<Orb>()(orb));
		return result;
	}
}
