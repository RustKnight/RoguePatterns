#include "Ai.h"



Command* Ai::decideAction(Creature* caller)
{

	return vCommands[rand() % 5];
}

void Ai::controlCreatures()
{

	//for (Thing* unit : vUnits) {
	//
	//	unit.vCommands[rand() % 5];
	//
	//}


}
