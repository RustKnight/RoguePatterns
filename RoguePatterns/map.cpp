#include "map.h"

void Map::update(const std::vector<Thing*> vec)
{

	clearThings();

	for (Thing* thing : vec) {


		const Point p = thing->getPosition();

		Cell& cell = vCells[(int)p.y * boardWidth + (int)p.x];

		cell.thing = thing;
	}
}



void Map::updateThingPositon(Point currentPoint, Point nextPoint) {

	int index		= (int)currentPoint.y * boardWidth + (int)currentPoint.x;
	int nextIndex	= (int)nextPoint.y * boardWidth + (int)nextPoint.x;
	
	vCells[nextIndex].thing = vCells[index].thing;

	vCells[index].thing = nullptr;
}

Cell& Map::checkCell(Point p)
{
	return vCells[(int)p.y * boardWidth + (int)p.x];
}

void Map::clearThings()
{

	for (Cell& cell : vCells) {

		cell.thing = nullptr;
	}
}

