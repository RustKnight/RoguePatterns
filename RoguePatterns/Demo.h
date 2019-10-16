#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Board.h"
#include "Creature.h"
#include "InputHandler.h"
#include "Strategy.h"
#include "Ai.h"

// add weapons of different attack values (Ex: Axe +2, Sword +1, etc. - naming will just be flavor for now)
// add ability for players to pick up different weapons and be able to exchange them when desired
// make an AI that always is on a look out for a best weapon, and when possible it swaps it
// action text will be outputed in the command line


// maybe make feedback text appear in game in an interface - colorfull 

// input handler should be a component of thing.
// it should also be 2 derived classes one that allows actual player keyboard control
// and the other that hooks it up to an AI, that produces the input
// these 2 derived classes will be switchable the Thing class holding an interface to these two.

class Demo : public olc::PixelGameEngine
{
public:
	Demo() : winsizeX {800}, winsizeY {600}, 
		board	(25, 25, 25, 15, getWinWidth(), getWinHeight(), this),
		inputHandler (this)
	{
		sAppName = "Demo";
	}

public:
	bool OnUserCreate() override
	{
			

		return true;
	}



	bool OnUserUpdate(float fElapsedTime) override
	{
	
		Clear(olc::BLACK);
		{

			if (GetMouseWheel() > 0) {
				board.cellSizeX++;
				board.cellSizeY++;
			}

			if (GetMouseWheel() < 0) {
				board.cellSizeX--;
				board.cellSizeY--;
			}

			if (GetKey(olc::G).bPressed)
				board.toggleGrid();
		}

		board.drawBoard();
			




	
		// board will call the draw routing
		for (Thing* thing : vpThings)
			board.drawThing(*thing);

		return true;
	}




	// Demo public methods
public:
	int getWinWidth() const		{ return winsizeX; };
	int getWinHeight() const	{ return winsizeY; };


	// Demo private data members
private:
	int winsizeX;
	int winsizeY;

	Board board;
	Ai ai;

	vector<Thing*>vpThings;

	InputHandler inputHandler;

};


