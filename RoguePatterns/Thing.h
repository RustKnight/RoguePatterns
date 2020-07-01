#pragma once
#include"olcPixelGameEngine.h"
#include "Point.h"
#include <string>
#include "Physics.h"


class InteractionHandler;

class Thing {


public:

	Thing(olc::PixelGameEngine* pge, float* fElapsedTime) :
		pge{ pge }, 
		avatar{ 'o' }, 
		pos{ 0,0 }, 
		color{ olc::GREEN }, 
		name{ "DefaultName" },
		physics{ *this },
		fElapsedTime { fElapsedTime }
	{}


	Thing(std::string name, char avatar, Point pos, olc::Pixel color, InteractionHandler* interactionHandler, float* fElapsedTime, olc::PixelGameEngine* pge) :
		name{ name }, 
		avatar{ avatar }, 
		pos{ pos }, 
		color{ color }, 
		interactionHandler{ interactionHandler }, 
		pge{ pge },
		physics {*this},
		fElapsedTime { fElapsedTime }
	{}
	

	virtual void	 act()				     = 0;
	virtual void	 collide (Thing& wall)	 = 0;
	virtual void	 attack  (Thing& target) = 0;
	virtual bool 	 isObstacle	 ()		     = 0;

	virtual bool	 isDone() = 0;

	virtual void	 takeDamage(int dmg) = 0;

	//virtual void	 perish() -> marks thing for deletion

	std::string getName()		const { return name;	}
	Point		getPosition()	const { return pos;		}
	char		getAvatar()		const { return avatar;	}
	olc::Pixel	getColor()		const { return color;	}



protected:
	std::string name;
	Point pos;
	char avatar;
	olc::Pixel color;
	olc::PixelGameEngine* pge;

public:
	float* fElapsedTime;
	Physics physics;
	InteractionHandler* interactionHandler;
};

