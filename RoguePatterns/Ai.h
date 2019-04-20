#pragma once
#include "Thing.h"
#include "Command.h"
#include <vector>


class Ai {
public:

	Ai()
	{
		vCommands.push_back(new UpCommand);
		vCommands.push_back(new DownCommand);
		vCommands.push_back(new LeftCommand);
		vCommands.push_back(new RightCommand);
	}


	Command* control(const Thing& thing);


private:
	std::vector<Command*> vCommands;
};