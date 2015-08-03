#include "stdafx.h"
#include "Solver.h"
#include "hash.h"
#include "GopBoard.h"

int GameStateNode::getHeuristicCost() const
{
	if (Solver::isStateInGoal(state))
		return cost;
	return cost + state.getHeuristicCost();
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

typedef std::priority_queue<std::shared_ptr<GameStateNode>, std::vector<std::shared_ptr<GameStateNode>>, CompareNode> gamestate_queue;

void addIfNotVisited(gamestate_queue& agenda, std::unordered_map<GameState, int>& visitedCosts, GameState state, GameAction action, std::shared_ptr<GameStateNode> parent = nullptr, int cost = 0, int numSteps = 0)
{
	for (int i = 0; i < numSteps; i++)
	{
		state.player.action = action;
		state.step();
		// Update new attract
		action = state.player.action;
	}

	if (visitedCosts.count(state) == 0 || visitedCosts[state] > cost)
	{
		visitedCosts[state] = cost;
		agenda.emplace(std::make_shared<GameStateNode>(state, action, parent, cost));
	}
}

bool Solver::isStateInGoal(const GameState& s)
{
	for (const Orb& orb : s.orbs)
		if (!GopBoard::isAdjacentToAltar(orb.location))
		return false;
	return true;
}

std::vector<std::shared_ptr<GameStateNode>> Solver::solve(const GameState& initialState, int* pNumExpanded, bool debug)
{
	gamestate_queue agenda;
	agenda.emplace(std::make_shared<GameStateNode>(initialState, GameAction::idle()));
	std::unordered_map<GameState, int> visitedCosts(200000);
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
		if (isStateInGoal(node->state))
		{
			if (minCost >= node->cost)
			{
				minCost = node->cost;
				solutions.push_back(node);
				// We don't need to branch from a solved state.
				continue;
			}
		}

		auto orbs = node->state.orbs;

		// Idle for a tick
		addIfNotVisited(agenda, visitedCosts, node->state, GameAction::idle(), node, node->cost + 1, 1);

		bool allOrbsScoring = true;
		for (int i = 0; i < (int)orbs.size(); ++i)
		{
			// If orb is about to score, don't need to touch it again!
			if (!GopBoard::willOrbScore(orbs[i]))
			{
				allOrbsScoring = false;

				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, false, false, false), node, node->cost + 1, 1);
				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, true, false, false), node, node->cost + 1, 1);
				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, false, false, true), node, node->cost + 1, 1);
				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, true, false, true), node, node->cost + 1, 1);
				// Repel variants
				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, false, true, false), node, node->cost + 1, 1);
				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, true, true, false), node, node->cost + 1, 1);
				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, false, true, true), node, node->cost + 1, 1);
				addIfNotVisited(agenda, visitedCosts, node->state, GameAction::attract(i, true, true, true), node, node->cost + 1, 1);
			}
		}

		// If all orbs are scoring, don't do anything else.
		if (!allOrbsScoring)
		{
			// All possible places to move, always running and not repelling

			// Toggle run if walking
			bool toggleRun = !node->state.player.run;
			// Change wand if repelling
			bool changeWand = node->state.player.repel;
			for (const Point& next : GopBoard::getNeighbors(node->state.player.location, PathMode::Player)) {
				for (const Point& next2 : GopBoard::getNeighbors(next, PathMode::Player)) {
					if (next2 != node->state.player.location)
						addIfNotVisited(agenda, visitedCosts, node->state, GameAction::move(next2, toggleRun, changeWand), node, node->cost + 1, 1);
				}
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
