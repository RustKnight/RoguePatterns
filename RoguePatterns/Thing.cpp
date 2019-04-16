#include "Thing.h"

void Thing::draw() const
{
	brd->drawCreature(pos, avatar, color);
}
