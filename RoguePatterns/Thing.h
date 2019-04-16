#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "Board.h"

#include <string>


class Thing {

public:
	Thing(Board* brd, olc::PixelGameEngine* pge):
		brd {brd}, pge {pge}
	{}
	Thing(std::string name, char avatar, Point pos, olc::Pixel color, Board* brd, olc::PixelGameEngine* pge) :
		name{ name }, avatar{ avatar }, pos{ pos }, color{ color }, brd{ brd }, pge{ pge }
	{}


	void assignRandomBoardPosition();
	void draw() const;
	std::string getName() const { return name; }



protected:
	std::string name;
	Point pos;
	char avatar;
	olc::Pixel color;

	Board* brd;
	olc::PixelGameEngine* pge;
};