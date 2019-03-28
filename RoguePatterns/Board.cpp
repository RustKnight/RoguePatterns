#include "Board.h"

void Board::centerBoard()
{
	
	int halfBoardX = width * cellSizeX / 2;
	int halfBoardY = height * cellSizeY / 2;

	int halfWindowX = windowX / 2;
	int halfWindowY = windowY / 2;

	positionX = halfWindowX - halfBoardX;
	positionY = halfWindowY - halfBoardY;
}

void Board::drawEdges()
{
	const int edgeWidth = 20;
	int boardPixelWidth = width * cellSizeX;
	int boardPixelHeight = height * cellSizeY;

	Point topLeftCorner			{ positionX - edgeWidth, positionY - edgeWidth };
	Point topRightCorner		{ positionX + boardPixelWidth + 1, positionY - edgeWidth };
	Point bottomLeftCorner		{ positionX - edgeWidth, positionY + boardPixelHeight + 1 };

	// left edge
	pge->FillRect(topLeftCorner.x, topLeftCorner.y, edgeWidth, boardPixelHeight + edgeWidth * 2, olc::VERY_DARK_GREY);
	// top edge
	pge->FillRect(topLeftCorner.x, topLeftCorner.y, boardPixelWidth + edgeWidth * 2, edgeWidth, olc::VERY_DARK_GREY);	
	
	// right edge
	pge->FillRect(topRightCorner.x, topRightCorner.y, edgeWidth, boardPixelHeight + edgeWidth * 2, olc::VERY_DARK_GREY);
	// bottom edge
	pge->FillRect(bottomLeftCorner.x, bottomLeftCorner.y, boardPixelWidth + edgeWidth * 2, edgeWidth, olc::VERY_DARK_GREY);
}


void Board::drawBoard()
{

	centerBoard();

	if (showGrid){
		for (int w = positionX; w < width * cellSizeX + positionX; w += cellSizeX)
			for (int h = positionY; h < height * cellSizeY + positionY; h += cellSizeY)
				pge->DrawRect(w, h, cellSizeX, cellSizeY, olc::DARK_GREY);
	}

	drawEdges();

	
}

void Board::drawCreature(const Point& pos, const char& avatar, const olc::Pixel& color) const
{

	Point positionOnScreen{ positionX + pos.x * cellSizeX, positionY + pos.y * cellSizeY };
	Point centeredPos = centerSymbolInCell (positionOnScreen);

	pge->DrawString(centeredPos.x, centeredPos.y, std::string(1, avatar), color, symbolSize);

}

void Board::toggleGrid()
{
	showGrid = !showGrid;
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