#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Board.h"
#include "Creature.h"
#include "InputHandler.h"
#include "Strategy.h"
#include "Ai.h"
#include "InteractionHandler.h"
#include "Obstacle.h"
#include "map.h"

#include <vector>
#include <typeinfo>


// add weapons of different attack values (Ex: Axe +2, Sword +1, etc. - naming will just be flavor for now)
// add ability for players to pick up different weapons and be able to exchange them when desired
// make an AI that always is on a look out for a best weapon, and when possible it swaps it
// action text will be outputed in the command line



// ai has different behaviour : pursue, run away, keep distance (find weapon, find health)
	// similar to commands, ai will choose these behaviours, based on his stats and surroundings. 
	// then, these behaviours will be implemented based on the game's current state/algorithm
// ai logic will be based on a behaviour interface as described above


// make the world understand grids. grids can be empty or hold things
	// ai and interactionHandler will be use of this container
	// ai can scan based on his location, his surroundings 


// 1 action = 1 move ; all creatures have 1 move per turn

// bump on wall			= remain on original postion 

// teams

// bump on enemy		= means attack

// bump on friendly		= remain on original postion 


class Demo : public olc::PixelGameEngine
{
public:
	Demo() : winsizeX {800}, winsizeY {600}, 
		board	(25, 25, 25, 15, getWinWidth(), getWinHeight(), this),
		map (board),
		interactionHandler(map),
		inputHandler (this)
	{
		sAppName = "Demo";
	}

public:
	bool OnUserCreate() override
	{

		Creature* knight = new Creature("Knight", 'K', { 10,5 }, olc::DARK_RED, &interactionHandler, this);
		knight->equip(new Sword(this));
		vpThings.push_back(knight);

		Creature* fiend = new Creature("Fiend", 'F', { 5,5 }, olc::DARK_MAGENTA, &interactionHandler, this);
		fiend->equip(new Axe(this));
		vpThings.push_back(fiend);

		for (int x = 0; x < 25; ++x)
			for (int y = 0; y < 15; ++y) {

				// left border
				if (x == 0)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, this));

				// right border
				if (x == 24)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, this));

				// top border
				if (x != 0 && y == 0)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, this));

				// bottom border
				if (x != 0 && y == 14)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, this));
			}

		for (int i = 0; i < 20; ++i) {

			int x = rand() % 26;
			int y = rand() % 16;

			vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, this));
		}

		

		inputHandler.takeOverCreature(static_cast<Creature*>(knight));
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

		map.update(vpThings);

		inputHandler.controlCreature();


		// keep skiping until button was pressed 
		if (static_cast<Creature*>(vpThings[0])->isDecided()) {

			vpThings[0]->act();

			static_cast<Creature*>(vpThings[1])->setIntetion(ai.control(*vpThings[1]));
			vpThings[1]->act();
		}

		

	
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

	InteractionHandler interactionHandler;
	Board board;
	Map map;
	Ai ai;

	vector<Thing*>vpThings;
	InputHandler inputHandler;
	

};


