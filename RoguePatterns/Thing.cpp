#include "Thing.h"

void Thing::assignRandomBoardPosition()
{
	pos = brd->getRandomLocation();
}

void Thing::draw() const
{
	brd->drawThing(pos, avatar, color);
}
