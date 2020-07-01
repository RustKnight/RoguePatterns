#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include "Thing.h"
#include "Strategy.h"


#include <string>


class Weapon;
class InteractionHandler;
class IDecisionTaker;
class Command;


class Creature : public Thing{


public:

	Creature(std::string name, char avatar, Point pos, olc::Pixel color, InteractionHandler* interact, IDecisionTaker* possessor, float* fElapsedTime, olc::PixelGameEngine* pge) :
		
		Thing(name, avatar, pos, color, interact, fElapsedTime, pge),
		intention {nullptr},
		possessor { possessor },
		weapon {nullptr},
		hp {10},
		alive {true},
		animationSpeed {14.0f}
	{}

	void act			()				override;
	void attack			(Thing& target)	override;
	void collide		(Thing& target) override;
	bool isObstacle		()				override;
	bool isDone			()				override;
	void takeDamage		(int dmg)		override;

	void switchPossesor(IDecisionTaker* newPossesor);

	void equip(Weapon* weapon);

	Command* getIntention();

	void up();
	void down();
	void left();
	void right();

	void thrownUp();
	void thrownDown();
	void thrownLeft();
	void thrownRight();

	void skipTurn();

	bool isAlive();


private:
	Command* intention;
	IDecisionTaker* possessor;
	Weapon* weapon;
	int hp;
	bool alive;

	float animationSpeed;
};