#pragma once
#include "olcPixelGameEngine.h"
#include "Point.h"
#include <string>




class Board {

public:
	Board(int cellSizeX, int cellSizeY, int boardWidth, int boardHeight, int windowX, int windowY, olc::PixelGameEngine* pge) :
		cellSizeX{ cellSizeX }, cellSizeY{ cellSizeY }, boardWidth{ boardWidth }, boardHeight{ boardHeight }, windowX{ windowX }, windowY{ windowY }, boardPosX{ 0 }, boardPosY{ 0 }, pge {pge}
	{
		centerBoard();
	}

	

	void drawBoard();
	void drawCreature(const Point& pos, const char& avatar, const olc::Pixel& color) const;
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