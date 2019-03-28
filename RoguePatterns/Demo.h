#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Board.h"
#include "Creature.h"

class Demo : public olc::PixelGameEngine
{
public:
	Demo() : winsizeX {800}, winsizeY {600}, board (25, 25, 25, 15, getWinWidth(), getWinHeight(), this),
		player(std::string{ "Knight" }, 'K', Point{ 5, 5 }, olc::DARK_YELLOW, &board, this), enemy(std::string{ "Lurker" }, 'Z', Point{ 10, 5 }, olc::DARK_RED, &board, this)
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
		
		board.drawBoard();
		player.control();
		player.draw();

		
		enemy.draw();

		return true;
	}

	int getWinWidth() const		{ return winsizeX; };
	int getWinHeight() const	{ return winsizeY; };


private:
	int winsizeX;
	int winsizeY;

	Board board;
	Creature player;
	Creature enemy;
};


