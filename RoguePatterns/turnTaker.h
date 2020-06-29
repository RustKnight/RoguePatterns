#pragma once

#include "Creature.h"
#include <vector>


class TurnTaker
{
public:

	TurnTaker(std::vector<Creature*> vec) : creaturesInPlay {vec}
	{}

	void playTurn() const;


private:

	void nextCreature();


private:
	std::vector<Creature*> creaturesInPlay;

};

