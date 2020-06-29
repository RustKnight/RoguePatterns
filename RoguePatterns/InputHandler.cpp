#include "InputHandler.h"



Command* InputHandler::decideAction(Creature* caller)
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
