#pragma once

#include <iostream>
#include "Creature.h"

using namespace std;



class Weapon {
public:
	
	virtual void apply(Creature& attacker, Creature& target) = 0;
	virtual ~Weapon() = default;
};


class Axe : public Weapon {
	
public:
	void apply(Creature& attacker, Creature& target) override {
		cout << attacker.getName() << " hacks " << target.getName() << " with his +" << damage << " axe!";
	}

private:
	int damage = 2;
};


class Sword : public Weapon {
public:
	void apply(Creature& attacker, Creature& target) override {
		cout << attacker.getName() << " slashes " << target.getName() << " with his +" << damage << " sword!";
	}

private:
	int damage = 1;
};