#pragma once

#include "Thing.h"

#include <SFML/Window/Event.hpp>

class Obstacle : public Thing
{
public:
	Obstacle(std::string name, char avatar, Point pos, olc::Pixel color, InteractionHandler* interactionHandler, float* fElapsedTime, olc::PixelGameEngine* pge) :
		Thing(name, avatar, pos, color, interactionHandler, fElapsedTime, pge)
	{}

	void	 act		()				override {};
	void	 collide	(Thing& wall)	override {};
	void	 attack		(Thing& target) override {};
	bool	 isDone		()				override { return true; };
	void	 takeDamage  (int dmg)		override {};

	bool isObstacle() override { return true; };
};

