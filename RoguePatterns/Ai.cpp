#include "Ai.h"



Command* Ai::control(const Thing& thing)
{


}

void Ai::controlCreatures()
{

	for (Thing* unit : vUnits) {

		unit.vCommands[rand() % 5];

	}


}
