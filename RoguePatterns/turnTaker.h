#pragma once

#include "Creature.h"
#include <vector>
#include <typeinfo>

// will do a typeCheck to ask for turns only for Creatures

// needs update to refresh things container, for cases where new ones are added or other ones die.

// keep track of rounds (round = 1 action from all players) for things like spells (slow, has effect 2 rounds)
// would call all creatures, creature.newRound() to inform them
	// creatures would have an effect object that alters them in a way

class TurnTaker
{
public:

	TurnTaker(std::vector<Thing*> vec) : vThings{vec}, turnID {0}//, roundCounter {0}
	{}

	void update(std::vector<Thing*> vec);
	void handleTurns();

	Thing* whoPlaysNow() const;
private:

	void nextCreature();


private:

	int turnID;
	//int roundCounter;
	std::vector<Thing*> vThings;

};

