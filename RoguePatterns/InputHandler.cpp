#include "InputHandler.h"

void InputHandler::takeOverCreature(Creature* creature)
{
	controlledCreature = creature;
}

void InputHandler::controlCreature()
{
	Command* command = handleInput();

	if (controlledCreature)
		controlledCreature->setIntetion(command);
}

Command* InputHandler::handleInput()
{
	
	if (pge->GetKey(olc::A).bPressed)
		return buttonLeft;

	else if (pge->GetKey(olc::D).bPressed)
		return buttonRight;

	else if (pge->GetKey(olc::W).bPressed)
		return buttonUp;

	else if (pge->GetKey(olc::S).bPressed)
		return buttonDown;

	else if (pge->GetKey(olc::SPACE).bPressed)
		return skipTurn;

	return nullptr;
}
