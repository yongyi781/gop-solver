#include "stdafx.h"
#include "GameAction.h"

std::string GameAction::toString() const
{
	std::string str;
	if (toggleRun)
		str += "{r}";
	if (changeWand)
		str += "{q}";
	if (newAttract)
		str += "*";

	switch (type)
	{
	case GameActionType::Idle:
		str += "-";
		break;
	case GameActionType::Move:
		str += location.toString();
		break;
	case GameActionType::Attract:
		str += (char)orbIndex + 'A';
		break;
	default:
		throw std::exception("Game action type out of range");
	}

	return str;
}

std::string GameAction::formatActions(const std::deque<GameAction>& actions)
{
	std::string s;
	if (actions.size() > 0)
	{
		int c = 1;
		std::string prev = actions[0].toString();
		for (size_t i = 1; i < actions.size(); i++)
		{
			std::string a = actions[i].toString();
			if (a == prev && !actions[i].toggleRun && !actions[i].changeWand && !actions[i].newAttract)
			{
				++c;
			}
			else
			{
				s += formatActionWithCount(prev, c);
				c = 1;
			}
			prev = a;
		}
		s += formatActionWithCount(prev, c);
	}
	return s;
}

GameAction GameAction::parse(std::string str)
{
	bool toggleRun = false, changeWand = false, newAttract = false;

	while (str[0] == '{' || str[0] == '*')
	{
		if (str[0] == '*')
		{
			newAttract = true;
			str = str.substr(1);
		}
		else
		{
			size_t j = str.find("}");
			std::string c = str.substr(1, j - 1);
			if (c == "r")
				toggleRun = true;
			else if (c == "q")
				changeWand = true;
			else
				throw std::exception("Unknown inter-tick action, expected {r} or {q}.");
			str = str.substr(j + 1);
		}
	}

	if (str == "-")
		return GameAction::idle(toggleRun, changeWand);

	if (str.size() == 1)
		return GameAction::attract(str[0] - 65, toggleRun, changeWand, newAttract);
	return GameAction::move(Point::parse(str), toggleRun, changeWand);
}

std::deque<GameAction> GameAction::parseActions(std::string str)
{
	std::deque<GameAction> actions;
	while (!str.empty())
	{
		size_t end = 0;
		while (str[end] == '{')
			end = str.find("}", end) + 1;

		if (str[end] == '(')
		{
			// Move action
			end = str.find(")", end) + 1;
		}
		else
		{
			end = str.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ-", end) + 1;
		}
		if (end == -1)
		{
			throw std::exception("Invalid action string");
			break;
		}

		GameAction action = GameAction::parse(str.substr(0, end));
		actions.push_back(action);
		str = str.substr(end);

		if (str[0] == '[')
		{
			end = str.find(']');
			int count = std::min(10000, atoi(str.substr(1, end - 1).c_str()));
			while (--count > 0)
				actions.push_back(action.copy(true));
			str = str.substr(end + 1);
		}
	}
	return actions;
}
