#include "Board.h"

void Board::centerBoard()
{
	int halfBoardX = boardWidth * cellSizeX / 2;
	int halfBoardY = boardHeight * cellSizeY / 2;

	int halfWindowX = windowX / 2;
	int halfWindowY = windowY / 2;

	boardPosX = halfWindowX - halfBoardX;
	boardPosY = halfWindowY - halfBoardY;
}

void Board::drawEdges()
{
	const int edgeWidth = 25;
	int boardPixelWidth = boardWidth	* cellSizeX;
	int boardPixelHeight = boardHeight	* cellSizeY;

	Point topLeftCorner			{ boardPosX - edgeWidth,			boardPosY - edgeWidth };
	Point topRightCorner		{ boardPosX + boardPixelWidth + 1,	boardPosY - edgeWidth };
	Point bottomLeftCorner		{ boardPosX - edgeWidth,			boardPosY + boardPixelHeight + 1 };

	// left edge
	pge->FillRect(topLeftCorner.x, topLeftCorner.y, edgeWidth, boardPixelHeight + edgeWidth * 2, olc::VERY_DARK_RED);
	// top edge
	pge->FillRect(topLeftCorner.x, topLeftCorner.y, boardPixelWidth + edgeWidth * 2, edgeWidth, olc::VERY_DARK_RED);
	
	// right edge
	pge->FillRect(topRightCorner.x, topRightCorner.y, edgeWidth, boardPixelHeight + edgeWidth * 2, olc::VERY_DARK_RED);
	// bottom edge
	pge->FillRect(bottomLeftCorner.x, bottomLeftCorner.y, boardPixelWidth + edgeWidth * 2, edgeWidth, olc::VERY_DARK_RED);
}


void Board::drawTurnNotifier(Thing* thing)
{

	pge->DrawRect(boardPosX + thing->getPosition().x * cellSizeX, boardPosX + (thing->getPosition().y +1) * cellSizeX, cellSizeX + 1, cellSizeY + 1, olc::RED);

}

void Board::drawBoard()
{

	centerBoard();

	if (showGrid){
		for (int w = boardPosX; w < boardWidth * cellSizeX + boardPosX; w += cellSizeX)
			for (int h = boardPosY; h < boardHeight * cellSizeY + boardPosY; h += cellSizeY)
				pge->DrawRect(w, h, cellSizeX, cellSizeY, olc::DARK_GREY);
	}

	//drawEdges();	
}

void Board::drawThing(const Thing& thing) const
{

	Point positionOnScreen{ boardPosX + (int)thing.getPosition().x * cellSizeX, boardPosY + (int)thing.getPosition().y * cellSizeY };
	Point centeredPos = centerSymbolInCell (positionOnScreen);

	pge->FillRect(positionOnScreen.x, positionOnScreen.y, cellSizeX + 1, cellSizeY +1, olc::VERY_DARK_GREY);
	pge->DrawString(centeredPos.x, centeredPos.y, std::string(1, thing.getAvatar()), thing.getColor(), symbolSize);

}

void Board::toggleGrid()
{
	showGrid = !showGrid;
}

Point Board::getRandomLocation() const
{
	return Point{rand() % boardWidth, rand() % boardHeight};
}


Point Board::centerSymbolInCell(Point& pos) const
{
	int halfCellX = cellSizeX / 2;
	int halfCellY = cellSizeY / 2;
	int halfSymbol = (baseSymbolSize * symbolSize) / 2 -1;

	int x = pos.x + halfCellX - halfSymbol;
	int y = pos.y + halfCellY - halfSymbol;

	return Point{ x,y };
}