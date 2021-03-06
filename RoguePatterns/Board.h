#pragma once
#include "olcPixelGameEngine.h"
#include "Point.h"
#include "Thing.h"
#include <string>





class Board {


public:
	Board(int cellSizeX, int cellSizeY, int boardWidth, int boardHeight, int windowX, int windowY, olc::PixelGameEngine* pge) :
		cellSizeX{ cellSizeX }, cellSizeY{ cellSizeY }, boardWidth{ boardWidth }, boardHeight{ boardHeight }, windowX{ windowX }, windowY{ windowY }, boardPosX{ 0 }, boardPosY{ 0 }, pge {pge}
	{
		centerBoard();
	}

	

	void drawTurnNotifier(Thing* thing);
	void drawBoard();
	void drawThing(const Thing& thing) const;
	void toggleGrid();
	Point getRandomLocation() const;

private:
	void centerBoard();
	void drawEdges();
	Point centerSymbolInCell(Point& pos) const;

public:
	int boardPosX;
	int boardPosY;

	int cellSizeX;
	int cellSizeY;

	int boardWidth;
	int boardHeight;

	int windowX;
	int windowY;

	olc::PixelGameEngine* pge;
	int symbolSize = 2;
	static constexpr int baseSymbolSize = 8;

	bool showGrid = true;
};