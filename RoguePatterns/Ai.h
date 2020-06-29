#pragma once
#include "Thing.h"
#include "Command.h"
#include "map.h"
#include <vector>

// ai has different behaviour : pursue, run away, keep distance (find weapon, find health)

	// similar to commands, ai will choose these behaviours, based on his stats and surroundings. 
	// then, these behaviours will be implemented based on the game's current state/algorithm
// ai logic will be based on a behaviour interface as described above



class Ai {
public:

	Ai()
	{
		vCommands.push_back(new UpCommand);
		vCommands.push_back(new DownCommand);
		vCommands.push_back(new LeftCommand);
		vCommands.push_back(new RightCommand);
		vCommands.push_back(new WaitCommand);
	}


	Command* control(const Thing& thing);
	void controlCreatures();

	void selectBehaviour();

private:
	std::vector<Command*> vCommands;
	std::vector<Thing*> vUnits;
};