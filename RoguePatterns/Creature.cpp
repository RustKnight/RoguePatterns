#include "Creature.h"

void Creature::control()
{

	if (pge->GetKey(olc::A).bPressed)
		pos.x -= 1;
	else if (pge->GetKey(olc::D).bPressed)
	 	pos.x += 1;
	else if (pge->GetKey(olc::W).bPressed)
	 	pos.y -= 1;
	else if (pge->GetKey(olc::S).bPressed)
		pos.y += 1;

}

void Creature::draw() const
{
	brd->drawCreature(pos, avatar, color);
}
