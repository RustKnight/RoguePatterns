#include "Ai.h"



Command* Ai::control(const Thing& thing)
{

	return vCommands[rand() % 4];
	
}
