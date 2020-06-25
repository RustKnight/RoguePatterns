#pragma once

#include "Creature.h"
#include <vector>


class turnTaker
{
public:

	turnTaker(std::vector<Creature*> vec) : creaturesInPlay {vec}
	{}

	void playTurn() const;


private:

	void nextCreature();


private:
	std::vector<Creature*> creaturesInPlay;

};

