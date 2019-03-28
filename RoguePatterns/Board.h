#pragma once
#include "olcPixelGameEngine.h"
#include "Point.h"
#include <string>

class Board {

public:
	Board(int cellSizeX, int cellSizeY, int boardWidth, int boardHeight, int windowX, int windowY, olc::PixelGameEngine* pge) :
		cellSizeX{ cellSizeX }, cellSizeY{ cellSizeY }, width{ boardWidth }, height{ boardHeight }, windowX{ windowX }, windowY{ windowY }, positionX{ 0 }, positionY{ 0 }, pge {pge}
	{
		centerBoard();
	}



	void drawBoard();
	void drawCreature(const Point& pos, const char& avatar, const olc::Pixel& color) const;
	void toggleGrid();

private:
	void centerBoard();
	void drawEdges();
	Point centerSymbolInCell(Point& pos) const;

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
	int symbolSize = 2;
	static constexpr int baseSymbolSize = 8;

	bool showGrid = true;
};