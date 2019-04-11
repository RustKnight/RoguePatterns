#include "Creature.h"

#include "Strategy.h"

void Creature::draw() const
{
	brd->drawCreature(pos, avatar, color);
}

void Creature::equip(Weapon* weapon)
{
	this->weapon = weapon;
}

void Creature::attack(Creature& target)
{
	weapon->apply(*this, target);
}

void Creature::up()
{
	pos.y -= 1;
}

void Creature::down()
{
	pos.y += 1;
}

void Creature::left()
{
	pos.x -= 1;
}

void Creature::right()
{
	pos.x += 1;
}
