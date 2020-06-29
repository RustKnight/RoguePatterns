#include "Creature.h"
#include "InteractionHandler.h"
#include "IDecisionTaker.h"



void Creature::act()
{


	// maybe break act() into 2 functions: 
		// decideAction and animate, and depending on the creature state (acting - animating), the correct func. will be called

	intention = mind->decideAction(this);

	if (intention == nullptr) return;

	interactionHandler->handleAction(this, intention);

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

bool Creature::isDone()
{
	return intention != nullptr;
}

void Creature::switchPossesor(IDecisionTaker* newPossesor)
{
	mind = newPossesor;
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
