#pragma once

#include "IDecisionTaker.h"

#include "Command.h"
#include "olcPixelGameEngine.h"


class InputHandler : public IDecisionTaker {
public:

	InputHandler(olc::PixelGameEngine* pge) :
		pge {pge}
	{
		buttonUp	= new UpCommand;
		buttonDown	= new DownCommand;
		buttonLeft	= new LeftCommand;
		buttonRight = new RightCommand;
		skipTurn	= new WaitCommand;

	}
	


	Command* decideAction(Creature* caller) override;


private:
	Command* buttonUp;
	Command* buttonDown;
	Command* buttonLeft;
	Command* buttonRight;
	Command* skipTurn;

	
	olc::PixelGameEngine* pge;
};