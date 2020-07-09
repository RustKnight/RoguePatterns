#include "InteractionHandler.h"


// all entities should implement a bumped into function and is called here
// - walls make you bump, 
// - enteties resolve their relationship depending on each other's alligence
// - items allow to be moved on them
// - traps allow to be moved on them, but give damage


void InteractionHandler::handleAction(Thing* requester, Command* command)
{

	// determine intended direction

	Point upcomingPosition = requester->getPosition();
	upcomingPosition += command->direction();

	bool noInteraction = true;

	Cell& cell = map.checkCell(upcomingPosition);


		// we bumped into something
		if (cell.thing != nullptr && cell.thing != requester) {

			Thing& bumpedThing = *cell.thing;


			if (bumpedThing.isObstacle())
				requester->collide(bumpedThing);
			else
				requester->attack(bumpedThing);

			noInteraction = false;

			requester->physics.calculateCollision();
			// bumpedThing should also check for collision;
		}
	

	//assume we're dealing with creatures
	if (noInteraction)
		command->execute(*static_cast<Creature*>(requester));
	

}

