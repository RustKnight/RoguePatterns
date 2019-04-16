#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Board.h"
#include "Creature.h"
#include "InputHandler.h"
#include "Strategy.h"

// add weapons of different attack values (Ex: Axe +2, Sword +1, etc. - naming will just be flavor for now)
// add ability for players to pick up different weapons and be able to exchange them when desired
// make an AI that always is on a look out for a best weapon, and when possible it swaps it
// action text will be outputed in the command line


// maybe make feedback text appear in game in an interface - colorfull 

class Demo : public olc::PixelGameEngine
{
public:
	Demo() : winsizeX {800}, winsizeY {600}, 
		board	(25, 25, 25, 15, getWinWidth(), getWinHeight(), this),
		player	(std::string	{ "Knight" }, 'K', Point{ 5, 5 }, olc::YELLOW, &board, this),
		enemy	(std::string	{ "Lurker" }, 'Z', Point{ 6, 5 }, olc::RED, &board, this),
		axe		(&board, this),
		sword	(&board, this),
		inputHandler (this)
	{
		sAppName = "Demo";
	}

public:
	bool OnUserCreate() override
	{
		//axe.assignRandomBoardPosition();
		//sword.assignRandomBoardPosition();
		//player.assignRandomBoardPosition();
		//enemy.assignRandomBoardPosition();

		player.equip(&sword);
		enemy.equip(&axe);

		player.attack(enemy);
		cout << endl;
		enemy.attack(player);

		vThings.push_back(&axe);
		vThings.push_back(&sword);
		vThings.push_back(&player);
		vThings.push_back(&enemy);

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

		Command* doThis = inputHandler.handleInput();
		if (doThis) doThis->execute(player);
		
		
		for (Thing* thing : vThings)
			thing->draw();

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
	vector<Thing*> vThings;

	Creature player;
	Creature enemy;
	InputHandler inputHandler;

	//weapons
	Sword sword;
	Axe axe;
};


