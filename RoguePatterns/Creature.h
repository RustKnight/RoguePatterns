#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "Board.h"

#include <string>

class Creature {
public:
	Creature (std::string name, char avatar, Point pos, olc::Pixel color, Board* brd, olc::PixelGameEngine* pge):
		name{ name }, avatar{ avatar }, pos{ pos }, color{ color }, brd{ brd }, pge{ pge }
	{}

	void draw() const;

	void up();
	void down();
	void left();
	void right();


private:
	std::string name;
	Point pos;
	char avatar;
	olc::Pixel color;

	Board* brd;
	olc::PixelGameEngine* pge;
};