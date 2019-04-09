#pragma once

#include "Creature.h"
#include "Command.h"
#include "olcPixelGameEngine.h"


class InputHandler {
public:

	InputHandler(olc::PixelGameEngine* pge) :
		pge {pge}
	{
		buttonUp	= new UpCommand;
		buttonDown	= new DownCommand;
		buttonLeft	= new LeftCommand;
		buttonRight = new RightCommand;
	}

	Command* handleInput();


private:
	Command* buttonUp;
	Command* buttonDown;
	Command* buttonLeft;
	Command* buttonRight;
	
	olc::PixelGameEngine* pge;
};