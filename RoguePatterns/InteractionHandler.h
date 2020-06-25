#pragma once


#include "Point.h"
#include "Command.h"
#include <vector>



class InteractionHandler
{
public:

	// get all things postion
	void addThing(Thing* thing);
	void handleAction(Thing* requester, Command* command);
	
	
	void update(const std::vector<Thing*>& vec);

private:
	std::vector<Thing*> vThings;
};

