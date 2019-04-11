#pragma once

#include <iostream>
#include "Creature.h"

using namespace std;



class Weapon {
public:
	
	Weapon(int dam):
		damage {dam}
	{}

	virtual void apply(Creature& attacker, Creature& target) = 0;
	virtual ~Weapon() = default;

protected:
	int damage;
};


class Axe : public Weapon {
public:
	Axe():
		Weapon (5)
	{}


	void apply(Creature& attacker, Creature& target) override {
		cout << attacker.getName() << " hacks " << target.getName() << " with his +" << damage << " axe!";
	}


};


class Sword : public Weapon {
public:
	Sword() :
		Weapon(1)
	{}


	void apply(Creature& attacker, Creature& target) override {
		cout << attacker.getName() << " slashes " << target.getName() << " with his +" << damage << " sword!";
	}

};