#pragma once
#include "olcPixelGameEngine.h"
#include "Point.h"

class Board {

public:
	Board(int cellSizeX, int cellSizeY, int boardWidth, int boardHeight, int windowX, int windowY, olc::PixelGameEngine* pge) :
		cellSizeX{ cellSizeX }, cellSizeY{ cellSizeY }, width{ boardWidth }, height{ boardHeight }, windowX{ windowX }, windowY{ windowY }, positionX{ 0 }, positionY{ 0 }, pge {pge}
	{
		centerBoard();
	}



	void drawBoard();



private:
	void centerBoard();
	void drawEdges();

public:
	int positionX;
	int positionY;

	int cellSizeX;
	int cellSizeY;

	int width;
	int height;

	int windowX;
	int windowY;

	olc::PixelGameEngine* pge;
};