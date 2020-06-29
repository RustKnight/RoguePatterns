#pragma once

#include "Command.h"

//Rationale: Creature will have an IDecisionTaker object that can either be an AI or a Player. These 2 concrete classes will be declared in Demo.
			// when a creature is created it will requaire either an AI pointer of a Player pointer
			// when a creature needs to act(), it will ask the IDecisionTaker object for input (i.e Command) and act()


class IDecisionTaker {

public:

	virtual Command* decideAction(Creature* caller) = 0;



};