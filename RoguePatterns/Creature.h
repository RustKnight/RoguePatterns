#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "Thing.h"
#include "Strategy.h"


#include <string>


class Weapon;
class InteractionHandler;

class Creature : public Thing{

public:

	Creature (std::string name, char avatar, Point pos, olc::Pixel color, InteractionHandler* interact, olc::PixelGameEngine* pge):
		interactionHandler {interact},
		Thing (name, avatar, pos, color, pge),
		intention { nullptr },
		weapon {nullptr},
		hp {10},
		alive {true}
	{}

	void act() override;
	void attack(Thing& target) override;
	void collide(Thing& target) override;
	bool isObstacle() override;

	bool isDecided();

	void setIntetion(Command* command);
	void equip(Weapon* weapon);

	void up();
	void down();
	void left();
	void right();

	void skipTurn();

	bool isAlive();

private:
	InteractionHandler* interactionHandler;
	Command* intention;
	Weapon* weapon;
	int hp;
	bool alive;
};