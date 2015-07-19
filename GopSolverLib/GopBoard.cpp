#include "stdafx.h"
#include "GopBoard.h"
#include "GameState.h"
#include "hash.h"

using namespace std;

vector<Point> getLineOfSight(int8_t x1, int8_t y1, int8_t x2, int8_t y2)
{
	int8_t distX = x2 - x1;
	int8_t distY = y2 - y1;
	vector<Point> v;
	if (distX == 0 && distY == 0)
		return v;
	else if (x1 > x2)
	{
		v = getLineOfSight(x2, y2, x1, y1);
		reverse(begin(v), end(v));
	}
	else if (y1 > y2)
	{
		v = getLineOfSight(x1, -y1, x2, -y2);
		transform(begin(v), end(v), begin(v), [](Point p) { return Point(p.x, -p.y); });
	}
	else if (distX == 0)
	{
		for (int8_t y = y1; y <= y2; y++)
			v.push_back(Point(x1, y));
	}
	else if (distY == 0)
	{
		for (int8_t x = x1; x <= x2; x++)
			v.push_back(Point(x, y1));
	}
	else if (distX == distY)
	{
		for (int8_t x = x1, y = y1; x <= x2, y <= y2; x++, y++)
			v.push_back(Point(x, y));
	}
	else if (abs(distY) > abs(distX))
	{
		if (distX * distY > 0)
		{
			v = getLineOfSight(y1, x1, y2, x2);
			transform(begin(v), end(v), begin(v), [](Point p) { return Point(p.y, p.x); });
		}
		else
		{
			v = getLineOfSight(-y1, -x1, -y2, -x2);
			transform(begin(v), end(v), begin(v), [](Point p) { return Point(-p.y, -p.x); });
		}
	}
	else    // First octant
	{
		v.push_back(Point(x1, y1));
		int8_t x = x1 + 1;
		int8_t y = y1;
		int8_t error = distX / 2;
		while (x <= x2)
		{
			v.push_back(Point(x, y));
			if (error == 0)
			{
				x += 1;
				error += distY;
			}
			else
			{
				error += distY;
				x += 1;
				if (error > distX)
				{
					y += 1;
					v.push_back(Point(x - 1, y));
					error -= distX;
				}
				else if (error == distX)
				{
					y += 1;
					// These are just edge cases.
					if (distX == 6 && (distY == 1 || distY == 5)
						|| distX == 10 && (distY == 1 || distY == 3 || distY == 7 || distY == 9))
						v.push_back(Point(x, y - 1));
					else
						v.push_back(Point(x - 1, y));
					error = 0;
				}
			}
		}
	}
	return v;
}

GopArray<Tile> GopBoard::grid;
GopArray<vector<Point>> GopBoard::neighbors[3];
GopArray<int> GopBoard::distancesToAltarTable;

std::unordered_map<pair<Point, Point>, std::list<Point>> GopBoard::playerPathCache;
std::unordered_map<pair<Point, Point>, std::list<Point>> GopBoard::playerPathClickOrbCache;
std::unordered_map<pair<Point, Point>, bool> GopBoard::reachabilityCache;

std::unordered_map<pair<Point, Point>, int> distanceToReachableCache;

Tile GopBoard::get(int8_t x, int8_t y)
{
	return grid.get(x, y);
}

void GopBoard::calculateTables()
{
	reachabilityCache.clear();
	distanceToReachableCache.clear();
	playerPathCache.clear();
	playerPathClickOrbCache.clear();

	for (int i = 0; i < 3; ++i)
	{
		neighbors[i].clear();
		for (int8_t y = -GRID_MAX; y <= GRID_MAX; y++)
		{
			for (int8_t x = -GRID_MAX; x <= GRID_MAX; x++)
			{
				Point p = Point(x, y);
				for (const Point& offset : Point::offsets)
					if (canMove(p, offset, (PathMode)i, true))
					neighbors[i][p].push_back(p + offset);
			}
		}
	}

	for (int y = 0; y < GRID_SIZE; ++y)
		for (int x = 0; x < GRID_SIZE; ++x)
		distancesToAltarTable.data[y][x] = numeric_limits<int>::max();

	queue<pair<Point, int>> agenda;
	GopArray<bool> visited;
	for (const Point& p : Point::pointsAdjacentToAltar)
	{
		agenda.emplace(p, 0);
		visited[p] = true;
	}

	while (!agenda.empty())
	{
		auto curr = agenda.front();
		agenda.pop();
		distancesToAltarTable[curr.first] = curr.second;

		for (Point d : Point::offsets)
		{
			Point next = ::get<0>(curr) + d;
			if (canMove(::get<0>(curr) + d, -d, PathMode::Orb) && !visited[next])
			{
				visited[next] = true;
				agenda.emplace(next, ::get<1>(curr) + 1);
			}
		}
	}
}

void GopBoard::clear()
{
	grid.clear();
	calculateTables();
}

void GopBoard::loadAltar(const char* data)
{
	int x = 0, y = 0;
	for (int i = 0; data[i]; ++i)
	{
		if (data[i] == '\r' || data[i] == '\n')
			continue;
		if (x == GRID_SIZE)
		{
			x = 0;
			++y;
		}
		grid.data[y][x++] = (Tile)(data[i] - '0');
	}
	calculateTables();
}

void GopBoard::loadAltarFromFile(string path)
{
	ifstream fin(path);
	char c;
	int x = 0, y = 0;
	while (fin >> c)
	{
		if (x == GRID_SIZE)
		{
			x = 0;
			++y;
		}
		grid.data[y][x++] = (Tile)(c - '0');
	}
	calculateTables();
}

bool GopBoard::isPassable(Point p, PathMode mode)
{
	return grid[p] != Tile::Wall && (mode < PathMode::Orb || grid[p] != Tile::Rock) && (mode < PathMode::Player || grid[p] != Tile::Water);
}

bool GopBoard::canMoveWest(Point p, PathMode mode)
{
	return isInRange(p) && isInRange(p + Point::west) && isPassable(p, mode) && isPassable(p + Point::west, mode) && grid[p] != Tile::PanelW && grid[p] != Tile::PanelSW;
}

bool GopBoard::canMoveSouth(Point p, PathMode mode)
{
	return isInRange(p) && isInRange(p + Point::south) && isPassable(p, mode) && isPassable(p + Point::south, mode) && grid[p] != Tile::PanelS && grid[p] != Tile::PanelSW;
}

// d.x and d.y must be no more than 1 in absolute value.
bool GopBoard::canMove(Point p, Point d, PathMode mode, bool calculate)
{
	if (!calculate)
	{
		auto& v = neighbors[(int)mode][p];
		return find(begin(v), end(v), p + d) != v.end();
	}

	int8_t ddx = d.x == 1 ? 1 : 0;
	int8_t ddy = d.y == 1 ? 1 : 0;

	Tile old = grid[p];
	if (!isPassable(p, mode))
		grid[p] = Tile::Floor;

	bool result = true;
	if (d.y == 0)
		result = canMoveWest({ p.x + ddx, p.y }, mode);
	else if (d.x == 0)
		result = canMoveSouth({ p.x, p.y + ddy }, mode);
	else if (mode == PathMode::Sight)
	{
		if ((!canMoveWest({ p.x + ddx, p.y + ddy }, mode) && !canMoveWest({ p.x + ddx, p.y + ddy - 1 }, mode)) ||
			(!canMoveSouth({ p.x + ddx, p.y + ddy }, mode) && !canMoveSouth({ p.x + ddx - 1, p.y + ddy }, mode)))
			result = false;
		else if (d.x == d.y)
			result = !((!canMoveWest({ p.x + ddx, p.y + ddy }, mode) && !canMoveSouth({ p.x + ddx, p.y + ddy }, mode)) ||
				(!canMoveWest({ p.x + ddx, p.y + ddy - 1 }, mode) && !canMoveSouth({ p.x + ddx - 1, p.y + ddy }, mode)));
		else
			result = !((!canMoveWest({ p.x + ddx, p.y + ddy }, mode) && !canMoveSouth({ p.x + ddx - 1, p.y + ddy }, mode)) ||
				(!canMoveWest({ p.x + ddx, p.y + ddy - 1 }, mode) && !canMoveSouth({ p.x + ddx, p.y + ddy }, mode)));
	}
	else
	{
		if ((d.x == -d.y && get(p.x + ddx, p.y + ddy) == Tile::MiniPillar1) || (d.x == d.y && get(p.x + ddx, p.y + ddy) == Tile::MiniPillar2))
			result = false;
		else
			result = canMoveWest({ p.x + ddx, p.y + ddy }, mode)
			&& canMoveWest({ p.x + ddx, p.y + ddy - 1 }, mode)
			&& canMoveSouth({ p.x + ddx, p.y + ddy }, mode)
			&& canMoveSouth({ p.x + ddx - 1, p.y + ddy }, mode);
	}

	grid[p] = old;
	return result;
}

inline int8_t sign(int8_t x)
{
	return x == 0 ? 0 : x > 0 ? 1 : -1;
}

// Returns the value that is smaller in absolute value.
inline int8_t absmin(int8_t x, int8_t y) {
	return abs(x) < abs(y) ? x : y;
}

// Returns the orb offset from a player click.
Point GopBoard::getOrbOffset(Point diff, bool toPlayer) {
	double m = abs((double)diff.y / diff.x);
	int8_t dx = sign(diff.x);
	int8_t dy = sign(diff.y);
	Point result;
	if (m > 2)
		result = Point(0, 2 * dy);
	else if (m > 1)
		result = Point(dx, 2 * dy);
	else if (m == 1)
		result = Point(2 * dx, 2 * dy);
	else if (m >= 0.5)
		result = Point(2 * dx, dy);
	else
		result = Point(2 * dx, 0);
	return toPlayer ? Point(absmin(result.x, diff.x - dx), absmin(result.y, diff.y - dy)) : result;
}

Point GopBoard::nextOrbLocation(Point location, Point target)
{
	if (target == Point::invalid)
		return location;

	Point orbOffset = target - location;
	int8_t dx = sign(orbOffset.x);
	int8_t dy = sign(orbOffset.y);
	Point offset{ dx, dy };
	if (!GopBoard::canMove(location, Point(dx, dy), PathMode::Orb))
	{
		if (GopBoard::canMove(location, Point(dx, 0), PathMode::Orb))
			offset = Point(dx, 0);
		else if (GopBoard::canMove(location, Point(0, dy), PathMode::Orb))
			offset = Point(0, dy);
		else
			offset = Point::zero;
	}

	return location + offset;
}

bool GopBoard::canReach(Point p1, Point p2, bool repel)
{
	pair<Point, Point> key = { p1, p2 };
	if (p1 == p2 || p1.walkingDistanceTo(p2) > (repel ? MAX_REPEL_REACH_DISTANCE : MAX_REACH_DISTANCE))
		return false;

	auto iter = reachabilityCache.find(key);
	if (iter != reachabilityCache.end())
		return iter->second;

	auto lineOfSight = getLineOfSight(p1.x, p1.y, p2.x, p2.y);
	for (size_t i = 1; i < lineOfSight.size(); ++i)
	{
		if (!(i == lineOfSight.size() - 1 && !isPassable(lineOfSight[i], PathMode::Orb)) && !canMove(lineOfSight[i - 1], lineOfSight[i] - lineOfSight[i - 1], PathMode::Sight))
		{
			reachabilityCache[key] = false;
			return false;
		}
	}
	reachabilityCache[key] = true;
	return true;
}

bool GopBoard::willMoveOrb(Point pPlayer, Point pOrb, bool repel)
{
	double mabs = abs((double)(pOrb.y - pPlayer.y) / (pOrb.x - pPlayer.x));
	int8_t dx, dy;
	if (repel)
	{
		dx = pOrb.x == pPlayer.x ? 0 : pOrb.x > pPlayer.x ? 1 : -1;
		dy = pOrb.y == pPlayer.y ? 0 : pOrb.y > pPlayer.y ? 1 : -1;
	}
	else
	{
		dx = abs(pOrb.x - pPlayer.x) <= 1 ? 0 : pOrb.x > pPlayer.x ? -1 : 1;
		dy = abs(pOrb.y - pPlayer.y) <= 1 ? 0 : pOrb.y > pPlayer.y ? -1 : 1;
	}
	return !((mabs > 2 && !canMove(pOrb, { 0, dy }, PathMode::Orb)) ||
		(mabs < 0.5 && !canMove(pOrb, { dx, 0 }, PathMode::Orb)) ||
		(!canMove(pOrb, { dx, 0 }, PathMode::Orb) && !canMove(pOrb, { 0, dy }, PathMode::Orb)));
}

int GopBoard::distanceToAltar(Point p)
{
	return distancesToAltarTable[p];
}

int GopBoard::distanceToPoint(Point p1, Point p2)
{
	const auto& path = getPlayerPath(p1, p2);
	if (path.empty() || path.back() == p2)
		return (int)path.size();
	return -1;
}

int GopBoard::distanceToReachable(Point pPlayer, Point pOrb, bool repel, bool requireOrbMove)
{
	if (pPlayer == pOrb)
		return 1;	// Must move away from orb!

	auto iter = distanceToReachableCache.find({ pPlayer, pOrb });
	if (iter != distanceToReachableCache.end())
		return iter->second;

	queue<pair<Point, int>> q;
	GopArray<bool> visited;
	visited[pPlayer] = true;
	q.push({ pPlayer, 0 });
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		if (canReach(curr.first, pOrb, repel) && (!requireOrbMove || willMoveOrb(curr.first, pOrb, repel)))
		{
			distanceToReachableCache[{pPlayer, pOrb}] = curr.second;
			return curr.second;
		}

		for (const Point& neighbor : neighbors[(int)PathMode::Player][curr.first])
		{
			if (!visited[neighbor])
			{
				visited[neighbor] = true;
				q.push({ neighbor, curr.second + 1 });
			}
		}
	}

	distanceToReachableCache[{pPlayer, pOrb}] = std::numeric_limits<int>::max();
	return std::numeric_limits<int>::max();
}

bool GopBoard::isAdjacentToAltar(Point p)
{
	return p.x >= -2 && p.x <= 2 && p.y >= -2 && p.y <= 2;
}

std::list<Point>& GopBoard::getPlayerPath(Point p1, Point p2, bool clickOrb)
{
	pair<Point, Point> key = { p1, p2 };
	auto& cache = clickOrb ? playerPathClickOrbCache : playerPathCache;
	auto iter = cache.find(key);
	if (iter != cache.end())
		return iter->second;

	if (p1 == p2)
	{
		if (clickOrb)
		{
			// Player is on top of the orb and needs to move to a square adjacent to it.
			for (int i = 0; i < 4; ++i)
			{
				Point p = p1 + Point::offsets[i];
				if (isInRange(p.x, p.y) && canMove(p1, Point::offsets[i], PathMode::Player))
				{
					cache[key] = { p };
					return cache[key];
				}
			}
		}
		else
		{
			cache[key] = {};
			return cache[key];
		}
	}

	// Main case: player is not right next to the target.
	queue<Point> q;
	q.push(p1);
	GopArray<Point> parents;
	for (int y = 0; y < GRID_SIZE; ++y)
		for (int x = 0; x < GRID_SIZE; ++x)
		parents.data[y][x] = Point::invalid;
	parents[p1] = Point::zero;
	int minDist = INT_MAX;
	Point best = Point::invalid;

	while (!q.empty())
	{
		Point curr = q.front();
		q.pop();
		int dist = curr.distanceSquaredTo(p2);
		if ((clickOrb ? dist : curr.walkingDistanceTo(p2)) <= 1 && canMove(curr, p2 - curr, PathMode::Player))
		{
			parents[p2] = curr;
			best = p2;
			break;
		}
		if (minDist > dist)
		{
			minDist = dist;
			best = curr;
		}
		for (const Point& neighbor : neighbors[(int)PathMode::Player][curr])
		{
			if (parents[neighbor] == Point::invalid)
			{
				parents[neighbor] = curr;
				q.push(neighbor);
			}
		}
	}

	std::list<Point> path;
	for (Point p = best; p != p1; p = parents[p])
		path.push_front(p);
	if (clickOrb && !path.empty() && path.back() == p2)
		path.pop_back();	// Don't include orb location
	cache[key] = path;
	return cache[key];
}

// Returns the player path as an iterator pair instead of a reference to a list.
GopBoard::path_iterator_pair GopBoard::getPlayerPath2(Point p1, Point p2, bool clickOrb)
{
	auto& path = getPlayerPath(p1, p2, clickOrb);
	return{ path.cbegin(), path.cend() };
}

bool GopBoard::willOrbScore(const Orb& orb)
{
	if (orb.target == orb.location || orb.target == Point::invalid)
		return isAdjacentToAltar(orb.location);

	if (isAdjacentToAltar(orb.location) || isAdjacentToAltar(orb.target))
		return true;

	// If not one of the above, then it means that orb will move to altar in the middle of its path...
	// (and the path would take it out, but it scored in the process)
	// This takes at most 2 ticks.
	Point loc1 = nextOrbLocation(orb.location, orb.target);
	Point loc2 = nextOrbLocation(loc1, orb.target);

	return isAdjacentToAltar(loc2) || isAdjacentToAltar(loc1);
}

const std::vector<Point>& GopBoard::getNeighbors(Point p, PathMode mode)
{
	return neighbors[(int)mode][p];
}
