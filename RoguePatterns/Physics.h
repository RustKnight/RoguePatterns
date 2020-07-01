#pragma once

#include "Point.h"

class Thing;
class Command;

class ThrownUpCommand;
class ThrownDownCommand;
class ThrownLeftCommand;
class ThrownRightCommand;

// if thing calls collided, raise a bool hasCollided flag for Animation to stop and reset flag

class Physics {

public:

	Physics(Thing& thing) : thing{ thing }, busy{ false }
	{
		initCommands();
	}

	void getThrown(int TilesThrown, Command* dir);
	
	void execute();
	
	void calculateCollision();
	
	bool isBusy();


private:

	void initCommands();

	Command* moveToThrow(Command* moveCommand);

	int cellsLeft(Point& point);

private:
	Thing& thing;
	Point startPosition;
	Point targetPosition;
	Command* direction;
	bool busy;

	ThrownUpCommand*	thrownUp;
	ThrownDownCommand*	thrownDown;
	ThrownLeftCommand*	thrownLeft;
	ThrownRightCommand* thrownRight;
};