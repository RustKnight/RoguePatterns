#include "Ai.h"



Command* Ai::control(const Thing& thing)
{

	return vCommands[rand() % 5];
	
	//wait command
	return vCommands[4];
}
