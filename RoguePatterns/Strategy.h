#pragma once

#include <iostream>
#include "Thing.h"

using namespace std;



class Weapon : public Thing{
public:
	
	Weapon(int dam, Board* brd, olc::PixelGameEngine* pge):
		Thing(brd, pge), damage{ dam }
	{}

	virtual void apply(Thing& attacker, Thing& target) = 0;
	virtual ~Weapon() = default;

protected:
	int damage;
};


class Axe : public Weapon {
public:
	Axe(Board* brd, olc::PixelGameEngine* pge):
		Weapon (5, brd, pge)
	{
		name = "axe";
		avatar = '$';
		color = olc::DARK_CYAN;		
	}


	void apply(Thing& attacker, Thing& target) override {
		cout << attacker.getName() << " hacks " << target.getName() << " with his + " << damage << name << "!";
	}
};


class Sword : public Weapon {
public:
	Sword(Board* brd, olc::PixelGameEngine* pge) :
		Weapon(2, brd, pge)
	{
		name = "sword";
		avatar = '!';
		color = olc::DARK_CYAN;
	}


	void apply(Thing& attacker, Thing& target) override {
		cout << attacker.getName() << " hacks " << target.getName() << " with his + " << damage << name << "!";
	}
};