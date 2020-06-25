#pragma once

#include <iostream>
#include "Thing.h"

using namespace std;



class Weapon : public Thing{
public:
	
	Weapon(int dam, olc::PixelGameEngine* pge):
		Thing(pge), damage{ dam }
	{}

	virtual void apply(Thing& attacker, Thing& target) = 0;
	virtual ~Weapon() = default;



protected:
	int damage;
};


class Axe : public Weapon {
public:
	Axe(olc::PixelGameEngine* pge):
		Weapon (5, pge)
	{
		name = "axe";
		avatar = '$';
		color = olc::DARK_GREY;
	}


	void apply(Thing& attacker, Thing& target) override {
		cout << attacker.getName() << " hacks " << target.getName() << " with his +" << damage << " " << name << "!\n";
	}


	void act() {};
	void collide(Thing& wall) {};
	void attack(Thing& target) {};
	bool isObstacle() { return false; };
};


class Sword : public Weapon {
public:
	Sword(olc::PixelGameEngine* pge) :
		Weapon(2, pge)
	{
		name = "sword";
		avatar = '!';
		color = olc::DARK_GREY;
	}


	void apply(Thing& attacker, Thing& target) override {
		cout << attacker.getName() << " slashes " << target.getName() << " with his +" << damage << " " << name << "!\n";
	}

	void act() {};
	void collide(Thing& wall) {};
	void attack(Thing& target) {};
	bool isObstacle() { return false; };
};