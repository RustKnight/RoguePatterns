#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "InteractionHandler.h"

#include <string>

class InteractionHandler;


class Thing {

public:
	Thing(olc::PixelGameEngine* pge):
		pge {pge}
	{}
	Thing(std::string name, char avatar, Point pos, olc::Pixel color, olc::PixelGameEngine* pge) :
		name{ name }, avatar{ avatar }, pos{ pos }, color{ color }, pge{ pge }
	{}


//	void assignRandomBoardPosition();
	std::string getName() const { return name; }
	Point getPosition() const { return pos; }
	char getAvatar() const { return avatar; }
	olc::Pixel getColor() const { return color; }


protected:
	std::string name;
	Point pos;
	char avatar;
	olc::Pixel color;

	olc::PixelGameEngine* pge;
};