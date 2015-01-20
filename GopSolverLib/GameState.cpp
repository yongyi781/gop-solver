#include "stdafx.h"
#include "GameState.h"
#include "GopEngine.h"

GameState::GameState(Player player, std::vector<Orb> orbs)
	: player(player), orbs(orbs)
{
}

bool GameState::operator==(const GameState& other) const
{
	return player == other.player && orbs == other.orbs;
}

bool GameState::operator!=(const GameState & other) const
{
	return !(*this == other);
}

inline int sign(int x)
{
	return x == 0 ? 0 : x > 0 ? 1 : -1;
}

Point getTwoSquareOffset(Point diff)
{
	int dx = sign(diff.x);
	int dy = sign(diff.y);
	int absx = abs(diff.x);
	int absy = abs(diff.y);

	Point result;
	if (absx == 0 || absy == 0 || absx == absy)
		result = Point(2 * dx, 2 * dy);
	else if (absy > absx)
		result = absy > 2 * absx ? Point(0, 2 * dy) : Point(dx, 2 * dy);
	else
		result = absx > 2 * absy ? Point(2 * dx, 0) : Point(2 * dx, dy);
	if (abs(result.x) > abs(diff.x - dx))
		result.x = diff.x - dx;
	if (abs(result.y) > abs(diff.y - dy))
		result.y = diff.y - dy;
	return result;
}

void GameState::freeze(bool freezeOrbs)
{
	player.freeze();
	if (freezeOrbs)
		for (Orb& orb : orbs)
			orb.target = Point::invalid;
}

void GameState::step()
{
	for (Orb& orb : orbs)
		stepOrb(orb);
	stepPlayer(player);
}

inline int clamp(int x, int min, int max)
{
	return x < min ? min : x > max ? max : x;
}

void GameState::stepOrb(Orb& orb)
{
	if (GopEngine::isAdjacentToAltar(orb.location))
	{
		// Orb hit altar, don't move
		orb.target = Point::invalid;
	}
	else if (orb.target != Point::invalid && orb.location != orb.target)
	{
		Point nextLocation = GopEngine::nextOrbLocation(orb.location, orb.target);
		if (nextLocation == orb.location)
			orb.target = Point::invalid;
		orb.location = nextLocation;
	}
	if (orb.target == orb.location)
		orb.target = Point::invalid;
}

void GameState::stepPlayer(Player& p)
{
	if (p.action.getToggleRun())
		p.run = !p.run;

	p.isAttracting = false;
	p.hasMovedThisTick = false;

	if (p.forceAttractOrb != -1)
	{
		// Override player's action.
		p.action = p.previousAction.copyWithSettings(p.action.getToggleRun(), p.action.getChangeWand(), false);
	}

	if (p.action.getType() == GameActionType::Move && p.location == p.action.getLocation())
	{
		p.action = GameAction::idle(p.action.getToggleRun(), p.action.getChangeWand());
	}

	switch (p.action.getType())
	{
	case GameActionType::Idle:
		p.stopAttracting();
		p.delayAttractFromMoving = false;
		p.delayAttractFromPrototick = false;
		p.lastMoveTarget = Point::invalid;
		p.lastAttractTarget = Point::invalid;
		break;
	case GameActionType::Move:
		p.stopAttracting();
		p.lastAttractTarget = Point::invalid;
		p.delayAttractFromPrototick = false;
		if (p.lastMoveTarget != p.action.getLocation())
		{
			// Calculate move path if the player clicked somewhere else.
			p.movePath = GopEngine::getPlayerPath(p.location, p.action.getLocation(), false);
			p.lastMoveTarget = p.action.getLocation();
		}

		if (p.movePath.empty())
		{
			// Change to idle
			p.lastMoveTarget = Point::invalid;
			p.action = GameAction::idle(p.action.getToggleRun(), p.action.getChangeWand());
			p.delayAttractFromMoving = false;
		}
		else
		{
			p.stepMove();
		}
		break;
	case GameActionType::Attract:
	{
		p.lastMoveTarget = Point::invalid;
		if (p.previousAction.getType() != GameActionType::Attract || p.previousAction.getOrbIndex() != p.action.getOrbIndex())
		{
			// Must be new attract, fix it.
			p.action = p.action.copyWithSettings(p.action.getToggleRun(), p.action.getChangeWand(), true);
		}

		Orb& orb = orbs[player.action.getOrbIndex()];
		if (p.forceAttractOrb != -1 ||
			(!p.action.isNewAttract() && !GopEngine::canReach(p.location, orb.location, p.repel)))
		{
			// "pre-attract" before wand changes state.
			stepAttract(p);
		}

		p.forceAttractOrb = -1;
		break;
	}
	default:
		break;
	}

	if (p.action.getChangeWand())
		p.repel = !p.repel;
	if (p.action.getType() == GameActionType::Attract)
		stepAttract(p, true);
	p.previousAction = p.action;
}

void GameState::stepAttract(Player& p, bool isSecondAttract)
{
	Orb& orb = orbs[player.action.getOrbIndex()];
	bool canReach = GopEngine::canReach(p.location, orb.location, p.repel);

	if (p.forceAttractOrb != -1)
	{
		// Attract no matter what!
		attractSuccess(p, player.action.getOrbIndex());
		return;
	}

	if (p.action.isNewAttract())
	{
		// Reset attract ineffectiveness and drag target.
		p.holdLength = 0;
		p.currentOrb = -1;
		p.lastOrbClickLocation = orb.location;
	}

	if (!canReach)
	{
		// Can't reach, start dragging.
		if (p.lastOrbClickLocation != p.lastAttractTarget)
		{
			// Recalculate move path.
			p.movePath = GopEngine::getPlayerPath(p.location, p.lastOrbClickLocation, true);
			p.lastAttractTarget = p.lastOrbClickLocation;
		}
		if (p.movePath.empty())
		{
			// The move path is wrong, re-calculate...
			p.movePath = GopEngine::getPlayerPath(p.location, orb.location, true);
		}

		if (!p.hasMovedThisTick)
			p.stepMove();

		if (GopEngine::canReach(p.location, orb.location, p.repel))
		{
			// Pre-movement
			forceAttractNextTick(p, player.action.getOrbIndex());
		}

		if (!isSecondAttract)
			p.delayAttractFromPrototick = false;
	}
	else if (p.delayAttractFromMoving)
	{
		// Force on next tick
		forceAttractNextTick(p, player.action.getOrbIndex());
		p.delayAttractFromPrototick = false;
	}
	else
	{
		if (p.delayAttractFromPrototick)
			p.delayAttractFromPrototick = false;
		else
			attractSuccess(p, player.action.getOrbIndex());
	}

	if (GopEngine::canReach(p.location, orb.location, p.repel) && p.currentOrb == player.action.getOrbIndex())
	{
		// Attract even after moving, if it's the same orb.
		attractSuccess(p, player.action.getOrbIndex());
	}

	//if (p.action.isNewAttract())
	//{
	//	// No longer new attract (unless the player clicked again).
	//	p.action = p.action.copyWithSettings(p.action.getToggleRun(), p.action.getChangeWand(), false);
	//}

	p.delayAttractFromMoving = p.hasMovedThisTick;
}

void GameState::forceAttractNextTick(Player& p, int orbIndex)
{
	if (!p.delayAttractFromPrototick || p.currentOrb == orbIndex)
		p.forceAttractOrb = orbIndex;
}

void GameState::attractSuccess(Player& p, int orbIndex)
{
	Orb& orb = orbs[orbIndex];
	p.forceAttractOrb = -1;
	bool cancelAttract = false;
	Point orbOffset = GopEngine::getOrbOffset(p.location - orb.location, !p.repel);
	if (p.repel)
	{
		if (p.location.walkingDistanceTo(orb.location) >= GopEngine::MAX_REPEL_REACH_DISTANCE)
			cancelAttract = true;
		else
			orbOffset = -orbOffset;
	}

	if (!cancelAttract)
	{
		orb.target = orb.location + orbOffset;
	}

	p.currentOrb = orbIndex;
	// Orb has moved, drag path is now invalid.
	p.lastOrbClickLocation = orb.location;
	if (p.action.isNewAttract())
		p.holdLength = 1;
	else if (!p.isAttracting)
		p.holdLength++;

	p.delayAttractFromPrototick = p.holdLength == 1;
	p.isAttracting = true;
}

int GameState::getTwoTickHoldCost(int distances[], int currentOrb, bool prototick) const
{
	// Assuming 2 distances for now
	if (distances[0] < distances[1])
	{
		std::swap(distances[0], distances[1]);
		currentOrb = 1 - currentOrb;
	}

	bool isAttractingFartherOrb = distances[0] == distances[1] || currentOrb == 0;
	bool isAttractingCloserOrb = distances[0] == distances[1] || currentOrb == 1;

	int cost = 1 + distances[0] + distances[1] / 3;
	if (distances[1] % 3 == 1 && isAttractingCloserOrb && prototick ||
		distances[1] % 3 == 2 && isAttractingCloserOrb && prototick)
		cost += 1;
	return cost;
	//- std::max(0, (distance1 - 3) / 3) - std::max(0, (distance2 - 1) / 3);
}

bool GameState::needsToMoveForOrb(const Orb& orb) const
{
	return !GopEngine::willOrbScore(orb)
		&& orb.target == Point::invalid
		&& !GopEngine::canReach(player.location, orb.location, player.repel);
}

double GameState::getHeuristicCostSingleOrb(const Orb& orb, bool attractOnly) const
{
	double h = 0;
	Point nextLocation = GopEngine::nextOrbLocation(orb.location, orb.target);
	// Needs to move
	if (needsToMoveForOrb(orb))
	{
		int distanceToReachable = GopEngine::distanceToReachable(player.location, orb.location, player.repel);
		h += (1 + distanceToReachable) / 2;
	}

	// Add the distance to the altar.
	if (!GopEngine::isAdjacentToAltar(orb.location))
		h += 1 + GopEngine::distanceToAltar(nextLocation);
	return h;
}

double GameState::getHeuristicCost(bool attractOnly) const
{
	if (GopEngine::isStateInGoal(*this))
		return 0;

	double h = 0;

	if (orbs.size() == 1)
		return getHeuristicCostSingleOrb(orbs[0], attractOnly);
	if (orbs.size() == 2)
	{
		// Needs to move for both orbs
		bool needsToMoveFor0 = needsToMoveForOrb(orbs[0]);
		bool needsToMoveFor1 = needsToMoveForOrb(orbs[1]);
		if (needsToMoveFor0 && needsToMoveFor1)
		{
			int distanceToReachable = std::min(
				GopEngine::distanceToReachable(player.location, orbs[0].location, player.repel),
				GopEngine::distanceToReachable(player.location, orbs[1].location, player.repel));
			h += (1 + distanceToReachable) / 2;
		}
		else if (needsToMoveFor0)
		{
			int distanceToReachable = GopEngine::distanceToReachable(player.location, orbs[0].location, player.repel);
			h += (1 + distanceToReachable) / 2;
		}
		else if (needsToMoveFor1)
		{
			int distanceToReachable = GopEngine::distanceToReachable(player.location, orbs[1].location, player.repel);
			h += (1 + distanceToReachable) / 2;
		}

		Point nextLocation0 = GopEngine::nextOrbLocation(orbs[0].location, orbs[0].target),
			nextLocation1 = GopEngine::nextOrbLocation(orbs[1].location, orbs[1].target);

		if (GopEngine::isAdjacentToAltar(orbs[0].location))
			return getHeuristicCostSingleOrb(orbs[1], attractOnly);
		if (GopEngine::isAdjacentToAltar(orbs[1].location))
			return getHeuristicCostSingleOrb(orbs[0], attractOnly);

		int distances[] = {
			GopEngine::distanceToAltar(nextLocation0),
			GopEngine::distanceToAltar(nextLocation1)
		};

		h += getTwoTickHoldCost(distances, player.currentOrb, player.delayAttractFromPrototick);
	}

	return h;
}

void Player::stopAttracting()
{
	currentOrb = -1;
	isAttracting = false;
	holdLength = 0;
	forceAttractOrb = -1;
}

void Player::freeze()
{
	stopAttracting();
	delayAttractFromMoving = false;
	delayAttractFromPrototick = false;
	hasMovedThisTick = false;
	lastMoveTarget = Point::invalid;
	lastAttractTarget = Point::invalid;
	movePath.clear();
	lastOrbClickLocation = Point::invalid;
}

void Player::stepMove()
{
	if (movePath.size() > 0)
	{
		Point next = movePath.front();
		movePath.pop_front();
		if (movePath.size() > 0 && run)
		{
			next = movePath.front();
			movePath.pop_front();
		}

		location = next;
		hasMovedThisTick = true;
		delayAttractFromMoving = true;
	}
}
