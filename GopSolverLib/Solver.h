#pragma once

#include "GameState.h"
#include "GopEngine.h"

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

	int getHeuristicCost() const;
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

class Solver
{
public:
	static std::vector<std::shared_ptr<GameStateNode>> solve(const GameState& initialState, bool attractOnly = false, int* pNumExpanded = nullptr, bool debug = false);
};
