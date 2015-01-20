#include "stdafx.h"
#include "Solver.h"
#include "GopEngine.h"

double GameStateNode::getHeuristicCost() const
{
	return cost + state.getHeuristicCost(attractOnly);
}

std::deque<std::pair<GameState, GameAction>> GameStateNode::getPath() const
{
	std::deque<std::pair<GameState, GameAction>> d;
	const GameStateNode* curr = this;
	while (curr != nullptr)
	{
		d.emplace_front(curr->state, curr->action);
		curr = curr->parent.get();
	}
	return d;
}

std::string GameStateNode::getActions() const
{
	return getActions(getPath());
}

std::string GameStateNode::getActions(std::deque<std::pair<GameState, GameAction>> path)
{
	std::deque<GameAction> actions;
	for (auto& pair : path)
		actions.push_back(pair.second);
	actions.pop_front();	// Remove the initial idle.
	return GameAction::formatActions(actions);
}

std::vector<std::shared_ptr<GameStateNode>> Solver::solve(const GameState& initialState, bool attractOnly, int* pNumExpanded, bool debug)
{
	std::priority_queue<std::shared_ptr<GameStateNode>, std::vector<std::shared_ptr<GameStateNode>>, CompareNode> agenda;
	agenda.emplace(new GameStateNode(initialState, GameAction::idle(), attractOnly));
	std::unordered_map<GameState, int> visitedCosts;
	int minCost = INT_MAX;
	std::vector<std::shared_ptr<GameStateNode>> solutions;
	if (pNumExpanded != nullptr)
		*pNumExpanded = 0;

	while (!agenda.empty())
	{
		auto node = agenda.top();
		agenda.pop();

		if (pNumExpanded != nullptr)
			++*pNumExpanded;

		if (debug)
			OutputDebugStringA((std::to_string(node->cost) + "," + std::to_string((int)node->getHeuristicCost()) + ", " + node->getActions() + "\n").c_str());

		if (node->getHeuristicCost() > minCost)
			break;

		// If the orb target is adjacent to altar, then the orb will go into the altar for sure.
		if (GopEngine::isStateInGoal(node->state))
		{
			if (minCost >= node->cost)
			{
				minCost = node->cost;
				solutions.push_back(node);
				// We don't need to branch from a solved state.
				continue;
			}
		}

		auto playerLocation = node->state.player.location;
		auto orbs = node->state.orbs;

		std::vector<std::shared_ptr<GameStateNode>> nodesToAdd;

		// Idle for a tick
		nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::idle(), attractOnly, node, node->cost + 1, 1));

		// If orbs are about to score, the rest of the actions should be idle.
		if (!std::all_of(std::begin(orbs), std::end(orbs), [](const Orb& orb) { return GopEngine::willOrbScore(orb); }))
		{
			for (int i = 0; i < (int)orbs.size(); ++i)
			{
				nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, false, false, false), attractOnly, node, node->cost + 1, 1));
				nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, true, false, false), attractOnly, node, node->cost + 1, 1));
				nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, false, false, true), attractOnly, node, node->cost + 1, 1));
				nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, true, false, true), attractOnly, node, node->cost + 1, 1));
				if (!attractOnly)
				{
					nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, false, true, false), attractOnly, node, node->cost + 1, 1));
					nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, true, true, false), attractOnly, node, node->cost + 1, 1));
					nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, false, true, true), attractOnly, node, node->cost + 1, 1));
					nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::attract(i, true, true, true), attractOnly, node, node->cost + 1, 1));
				}
			}

			// All possible places to move, always running and not repelling

			// Toggle run if walking
			bool toggleRun = !node->state.player.run;
			// Change wand if repelling
			bool changeWand = node->state.player.repel;
			for (const Point& next : GopEngine::getNeighbors(playerLocation, PathMode::Player))
				for (const Point& next2 : GopEngine::getNeighbors(next, PathMode::Player))
					if (next2 != playerLocation)
						nodesToAdd.emplace_back(new GameStateNode(node->state, GameAction::move(next2, toggleRun, changeWand), attractOnly, node, node->cost + 1, 1));
		}

		for (const auto& nodeToAdd : nodesToAdd)
		{
			if (visitedCosts.count(nodeToAdd->state) == 0 || visitedCosts[nodeToAdd->state] > nodeToAdd->cost)
			{
				visitedCosts[nodeToAdd->state] = nodeToAdd->cost;
				agenda.push(nodeToAdd);
			}
		}
	}

	if (debug && pNumExpanded != nullptr)
		OutputDebugString((L"Expanded " + std::to_wstring(*pNumExpanded) + L" states\n").c_str());

	std::sort(std::begin(solutions), std::end(solutions), [](std::shared_ptr<GameStateNode> left, std::shared_ptr<GameStateNode> right) {
		auto leftPath = left->getPath();
		auto rightPath = right->getPath();
		// Prefer shorter solutions
		if (leftPath.size() != rightPath.size())
			return leftPath.size() < rightPath.size();

		// Prefer more idles at end
		int numIdlesLeft = 0, numIdlesRight = 0;
		while (leftPath.back().second.getType() == GameActionType::Idle)
		{
			++numIdlesLeft;
			leftPath.pop_back();
		}
		while (rightPath.back().second.getType() == GameActionType::Idle)
		{
			++numIdlesRight;
			rightPath.pop_back();
		}

		if (numIdlesLeft != numIdlesRight)
			return numIdlesLeft > numIdlesRight;

		// Then lexicographic
		return left->getActions() < right->getActions();
	});

	return solutions;
}
