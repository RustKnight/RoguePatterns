#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Board.h"

class Demo : public olc::PixelGameEngine
{
public:
	Demo() : winsizeX {800}, winsizeY {600}, board (12, 12, 50, 30, getWinWidth(), getWinHeight(), this)
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

		
		board.drawBoard();


		return true;
	}

	int getWinWidth() const		{ return winsizeX; };
	int getWinHeight() const	{ return winsizeY; };


private:
	int winsizeX;
	int winsizeY;

	Board board;
};


