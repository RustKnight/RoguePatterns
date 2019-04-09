#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "Board.h"

#include <string>




class Creature {

	class Weapon;

public:
	Creature (std::string name, char avatar, Point pos, olc::Pixel color, Board* brd, olc::PixelGameEngine* pge):
		name{ name }, avatar{ avatar }, pos{ pos }, color{ color }, brd{ brd }, pge{ pge }
	{}

	void draw() const;
	void equip(Weapon* weapon);
	void attack(Creature& target);

	void up();
	void down();
	void left();
	void right();

	std::string getName() const { return name; }

private:
	std::string name;
	Point pos;
	char avatar;
	olc::Pixel color;

	Board* brd;
	olc::PixelGameEngine* pge;

	Weapon* weapon = nullptr;
};