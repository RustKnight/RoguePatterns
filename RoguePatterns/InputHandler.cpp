#include "InputHandler.h"

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


	return nullptr;
}
