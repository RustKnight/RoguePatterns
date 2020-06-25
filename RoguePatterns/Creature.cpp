#include "Creature.h"
#include "InteractionHandler.h"




void Creature::act()
{

	interactionHandler->handleAction(this, intention);

}

void Creature::setIntetion(Command* command)
{

	intention = command;

}



void Creature::equip(Weapon* weapon)
{
	this->weapon = weapon;
}

void Creature::attack(Thing& target)
{
	weapon->apply(*this, target);
}

void Creature::collide(Thing& target)
{
	cout << this->getName() << " slams into a " << target.getName() << "!\n";
}

bool Creature::isObstacle()
{
	return false;
}

bool Creature::isDecided()
{
	return intention != nullptr;
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

void Creature::skipTurn()
{
	cout << name << " stands put.\n";
}

bool Creature::isAlive()
{
	return hp > 0;
}
