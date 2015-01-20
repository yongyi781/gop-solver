#pragma once

#include <deque>
#include <string>
#include "Point.h"

enum class GameActionType { Idle, Move, Attract };

// An immutable struct representing an action that a player can take.
class GameAction
{
public:
	GameAction() : GameAction(GameActionType::Idle) {}
	static GameAction idle(bool toggleRun = false, bool changeWand = false) { return GameAction(GameActionType::Idle, Point::invalid, 0, toggleRun, changeWand); }
	static GameAction move(Point location, bool toggleRun = false, bool changeWand = false) { return GameAction(GameActionType::Move, location, 0, toggleRun, changeWand); }
	static GameAction attract(int orbIndex, bool toggleRun = false, bool changeWand = false, bool isNewAttract = true) { return GameAction(GameActionType::Attract, Point::invalid, orbIndex, toggleRun, changeWand, isNewAttract); }

	bool operator==(const GameAction& other) const
	{
		return type == other.type
			&& location == other.location
			&& orbIndex == other.orbIndex
			&& toggleRun == other.toggleRun
			&& changeWand == other.changeWand
			&& newAttract == other.newAttract;
	}

	GameActionType getType() const { return type; }
	Point getLocation() const { return location; }
	int getOrbIndex() const { return orbIndex; }
	bool getToggleRun() const { return toggleRun; }
	bool getChangeWand() const { return changeWand; }
	bool isNewAttract() const { return newAttract; }

	GameAction copy(bool discardSettings = false) const
	{
		if (discardSettings)
			return GameAction(type, location, orbIndex);
		return GameAction(type, location, orbIndex, toggleRun, changeWand, newAttract);
	}

	GameAction copyWithSettings(bool toggleRun, bool changeWand, bool newAttract) const
	{
		return GameAction(type, location, orbIndex, toggleRun, changeWand, newAttract);
	}

	size_t hash() const
	{
		return std::hash<GameActionType>()(type) + 31 * (
			31 + std::hash<Point>()(location) + 31 * (
			31 + std::hash<int>()(orbIndex) + 31 * (
			31 + std::hash<bool>()(toggleRun) + 31 * (
			31 + std::hash<bool>()(changeWand) + 31 * (
			31 + std::hash<bool>()(newAttract))))));
	}

	std::string toString() const;

	static std::string formatActions(const std::deque<GameAction>& actions);
	// Parse a single action
	static GameAction parse(std::string str);
	static std::deque<GameAction> parseActions(std::string str);

private:
	GameAction(GameActionType type, Point location = Point::invalid, int orbIndex = 0, bool toggleRun = false, bool changeWand = false, bool isNewAttract = false)
		: type(type), location(location), orbIndex(orbIndex), toggleRun(toggleRun), changeWand(changeWand), newAttract(isNewAttract)
	{
	}

	// actionStr is either -, (a,b), A, B, or C.
	static std::string formatActionWithCount(std::string actionStr, int count)
	{
		std::string str1;
		for (int i = 0; i < count; i++)
			str1 += actionStr;
		std::string str2 = actionStr + "[" + std::to_string(count) + "]";
		return str1.size() < str2.size() ? str1 : str2;
	}

	GameActionType type;
	Point location;
	int orbIndex;
	bool toggleRun;
	bool changeWand;
	bool newAttract;
};
