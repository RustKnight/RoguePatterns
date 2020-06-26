#include "map.h"

void Map::update(std::vector<Thing*> vec)
{

	clearThings();

	for (Thing* thing : vec) {

		// get Pos
		const Point p = thing->getPosition();

		// access the 1D array based on Pos
		Cell& cell = vCells[p.y * boardWidth + p.x];

		// write cell thing pointer
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

