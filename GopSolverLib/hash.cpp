#include "stdafx.h"
#include "hash.h"

namespace std
{
#ifdef _WIN64
	const size_t PRIME = 1099511628211ULL;
	const size_t OFFSET = 14695981039346656037ULL;
#else
	const size_t PRIME = 16777619U;
	const size_t OFFSET = 2166136261U;
#endif

	size_t hash<Point>::operator()(const Point & p) const
	{
		size_t result = OFFSET;
		result = PRIME * (result ^ std::hash<int8_t>()(p.x));
		result = PRIME * (result ^ std::hash<int8_t>()(p.y));
		return result;
	}

	size_t hash<pair<Point, Point>>::operator()(const pair<Point, Point>& p) const
	{
		size_t result = OFFSET;
		result = PRIME * (result ^ std::hash<Point>()(p.first));
		result = PRIME * (result ^ std::hash<Point>()(p.second));
		return result;
	}

	size_t hash<GameAction>::operator()(const GameAction& action) const
	{
		size_t result = OFFSET;
		result = PRIME * result + std::hash<GameActionType>()(action.getType());
		result = PRIME * result + std::hash<Point>()(action.getLocation());
		result = PRIME * result + std::hash<int>()(action.getOrbIndex());
		result = PRIME * result + std::hash<bool>()(action.getToggleRun());
		result = PRIME * result + std::hash<bool>()(action.getChangeWand());
		result = PRIME * result + std::hash<bool>()(action.isNewAttract());
		return result;
	}

	size_t hash<Orb>::operator()(const Orb& orb) const
	{
		size_t result = OFFSET;
		result = PRIME * (result + hash<Point>()(orb.location));
		result = PRIME * (result + hash<Point>()(orb.target));
		return result;
	}

	size_t hash<Player>::operator()(const Player& player) const
	{
		size_t result = OFFSET;
		result = PRIME * (result + hash<Point>()(player.location));
		result = PRIME * (result + hash<int>()(player.currentOrb));
		result = PRIME * (result + hash<bool>()(player.delayAttractFromMoving));
		result = PRIME * (result + hash<bool>()(player.delayAttractFromPrototick));
		result = PRIME * (result + hash<bool>()(player.isAttracting));
		result = PRIME * (result + hash<int>()(player.forceAttractOrb));
		return result;
	}

	size_t hash<GameState>::operator()(const GameState& s) const
	{
		size_t result = OFFSET;
		result = PRIME * (result + hash<Player>()(s.player));
		for (auto& orb : s.orbs)
			result = PRIME * (result + hash<Orb>()(orb));
		return result;
	}
}
