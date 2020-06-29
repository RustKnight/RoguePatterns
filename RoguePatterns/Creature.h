#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "Thing.h"
#include "Strategy.h"


#include <string>


class Weapon;
class InteractionHandler;
class IDecisionTaker;

class Creature : public Thing{

public:

	Creature(std::string name, char avatar, Point pos, olc::Pixel color, InteractionHandler* interact, IDecisionTaker* possesor, olc::PixelGameEngine* pge) :
		
		intention {nullptr},
		mind { possesor },
		interactionHandler {interact},
		Thing (name, avatar, pos, color, pge),
		weapon {nullptr},
		hp {10},
		alive {true}
	{}

	void act() override;
	void attack(Thing& target) override;
	void collide(Thing& target) override;
	bool isObstacle() override;
	bool isDone() override;

	void switchPossesor(IDecisionTaker* newPossesor);

	void equip(Weapon* weapon);

	void up();
	void down();
	void left();
	void right();

	void skipTurn();

	bool isAlive();

private:
	Command* intention;
	IDecisionTaker* mind;
	InteractionHandler* interactionHandler;
	Weapon* weapon;
	int hp;
	bool alive;
};