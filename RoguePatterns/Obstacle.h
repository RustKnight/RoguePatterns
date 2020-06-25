#pragma once

#include "Thing.h"


class Obstacle : public Thing
{
public:
	Obstacle(std::string name, char avatar, Point pos, olc::Pixel color, olc::PixelGameEngine* pge) :
		Thing(name, avatar, pos, color, pge)
	{}

	void	 act		() {};
	void	 collide	(Thing& wall)  {};
	void	 attack		(Thing& target) {};

	bool isObstacle() override { return true; };
};

