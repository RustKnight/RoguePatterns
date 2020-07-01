#include "InteractionHandler.h"



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
		}
	

	//assume we're dealing with creatures
	if (noInteraction)
		command->execute(*static_cast<Creature*>(requester));
	

}

