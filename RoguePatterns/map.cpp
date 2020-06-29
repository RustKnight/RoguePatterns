#include "map.h"

void Map::update(const std::vector<Thing*> vec)
{

	clearThings();

	for (Thing* thing : vec) {


		const Point p = thing->getPosition();

		Cell& cell = vCells[p.y * boardWidth + p.x];

		cell.thing = thing;
	}
}

Cell& Map::checkCell(Point p)
{
	return vCells[p.y * boardWidth + p.x];
}

void Map::clearThings()
{

	for (Cell& cell : vCells) {

		cell.thing = nullptr;
	}
}

