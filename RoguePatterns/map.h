#pragma once

#include "Board.h"


struct Cell {

	Cell(Thing* thing) : thing{ thing }
	{}


	Thing* thing;
};

class Map
{


public:

	Map(const Board& board)
		: boardWidth {board.boardWidth}
	{

		for (int x = 0; x < board.boardWidth; ++x)
			for (int y = 0; y < board.boardHeight; ++y)
				vCells.push_back(Cell{ nullptr });		
	}


	void update(std::vector<Thing*> vec);
	
	Cell& checkCell(Point p);
	
	void clearThings();


private:

	std::vector<Cell> vCells;
	int boardWidth;
};

