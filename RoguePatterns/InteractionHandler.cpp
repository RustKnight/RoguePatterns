#include "InteractionHandler.h"

void InteractionHandler::addThing(Thing* thing)
{
	vThings.push_back(thing);
}

void InteractionHandler::handleAction(Thing* requester, Command* command)
{

	// determine direction of movement

	Point upcomingPosition = requester->getPosition();
	upcomingPosition += command->direction();
	bool noInteraction = true;

	for (Thing* bumpedThing : vThings) {

		// skip requester
		if (bumpedThing == requester)
			continue;

		// we bumped into something
		if (upcomingPosition == bumpedThing->getPosition()) {

			if (bumpedThing->isObstacle())
				requester->collide(*bumpedThing);
			else
				requester->attack(*bumpedThing);

			noInteraction = false;
			break;	
		}
	}

	//assume we're dealing with creatures
	if (noInteraction)
		command->execute(*static_cast<Creature*>(requester));
	

}

void InteractionHandler::update(const std::vector<Thing*>& vec)
{
	vThings = vec;
}
