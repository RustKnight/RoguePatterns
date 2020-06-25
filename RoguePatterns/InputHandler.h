#pragma once

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
		skipTurn	= new WaitCommand;

	}
	
	void takeOverCreature(Creature* creature);
	void controlCreature();


private:
	Command* handleInput();


private:
	Command* buttonUp;
	Command* buttonDown;
	Command* buttonLeft;
	Command* buttonRight;
	Command* skipTurn;


	Creature* controlledCreature;
	
	olc::PixelGameEngine* pge;
};