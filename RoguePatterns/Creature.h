#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "Thing.h"

#include <string>


class Weapon;

class Creature : public Thing{

public:

	Creature (std::string name, char avatar, Point pos, olc::Pixel color, olc::PixelGameEngine* pge):
		Thing (name, avatar, pos, color, pge)
	{}

	void equip(Weapon* weapon);
	void attack(Creature& target);

	void up();
	void down();
	void left();
	void right();


private:
	Weapon* weapon = nullptr;
};