#include "Ai.h"



Command* Ai::decideAction(Creature* caller)
{

	return vCommands[rand() % 5];

	//return vCommands[4];
}

void Ai::controlCreatures()
{

	//for (Thing* unit : vUnits) {
	//
	//	unit.vCommands[rand() % 5];
	//
	//}


}
