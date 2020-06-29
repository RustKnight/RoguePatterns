#pragma once

#include "Thing.h"


class Obstacle : public Thing
{
public:
	Obstacle(std::string name, char avatar, Point pos, olc::Pixel color, olc::PixelGameEngine* pge) :
		Thing(name, avatar, pos, color, pge)
	{}

	void	 act		()				override {};
	void	 collide	(Thing& wall)	override {};
	void	 attack		(Thing& target) override {};
	bool	 isDone		()				override { return true; };

	bool isObstacle() override { return true; };
};

