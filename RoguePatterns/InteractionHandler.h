#pragma once


#include "Point.h"
#include "Command.h"
#include <vector>
#include "map.h"



class InteractionHandler
{
public:

	InteractionHandler(Map& map) 
		: map {map}
	{}


	void handleAction(Thing* requester, Command* command);
	

private:
	Map& map;
};

