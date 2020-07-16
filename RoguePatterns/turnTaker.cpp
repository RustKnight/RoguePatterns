#include "turnTaker.h"

void TurnTaker::update(std::vector<Thing*> vec)
{

	vThings = vec;

}

//PS:  dead creatures also take turns, but call playDead() function which does nothing
//PS 2: we'll just ask everyone for turns, even if they're obstacles or etc.

void TurnTaker::handleTurns()
{
	Thing* playingThing = vThings[turnID];
		
	// stop normal turns if interrupts exist
	if (InterruptsExist())
		return;

	playingThing->act();

	// next turn only after physics is done from moving from A to B (i.e
	if (playingThing->isDone()) nextCreature();
	
}

bool TurnTaker::InterruptsExist()
{
	bool physicsPlaying = false;

	for (Thing* thing : vThings) {

		if (thing->physics.hasWork()) {

			thing->physics.execute();
			physicsPlaying = true;
		}
	}

	return physicsPlaying;
}

Thing* TurnTaker::whoPlaysNow() const
{
	return vThings[turnID];
}

void TurnTaker::nextCreature()
{
	if (turnID < vThings.size() - 1) {

		turnID++;

		// skip to creatures
		while (vThings[turnID]->isObstacle() && turnID < vThings.size() - 1)
			turnID++;
	}

	else {

		turnID = 0;
		//roundCounter++;
	}

}
