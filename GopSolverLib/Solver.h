#pragma once

#include "GameState.h"
#include "GopBoard.h"

class GameStateNode
{
public:
	GameStateNode(GameState state, GameAction action, std::shared_ptr<GameStateNode> parent = nullptr, int cost = 0)
		: state(state), action(action), parent(parent), cost(cost)
	{
	}

	int getHeuristicCost() const;
	std::deque<std::pair<GameState, GameAction>> getPath() const;
	std::string getActions() const;

	static std::string getActions(std::deque<std::pair<GameState, GameAction>> path);

	GameState state;
	GameAction action;
	std::shared_ptr<GameStateNode> parent;
	int cost;
};

struct CompareNode : public std::binary_function<std::shared_ptr<GameStateNode>, std::shared_ptr<GameStateNode>, bool>
{
	bool operator()(const std::shared_ptr<GameStateNode>& lhs, const std::shared_ptr<GameStateNode>& rhs) const
	{
		return lhs->getHeuristicCost() > rhs->getHeuristicCost();
	}
};

class Solver
{
public:
	static bool isStateInGoal(const GameState& s);
	static std::vector<std::shared_ptr<GameStateNode>> solve(const GameState& initialState, int* pNumExpanded = nullptr, bool debug = false);
};
