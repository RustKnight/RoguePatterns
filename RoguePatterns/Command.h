#pragma once

#include "Creature.h"


class Command {
public:

	virtual ~Command() {};
	virtual void execute(Creature& creature) = 0;
};



class UpCommand : public Command {

public:

	virtual void execute(Creature& creature) {
		creature.up();
	}

};



class DownCommand : public Command {

public:

	virtual void execute(Creature& creature) {
		creature.down();
	}

};



class LeftCommand : public Command {

public:

	virtual void execute(Creature& creature) {
		creature.left();
	}

};




class RightCommand : public Command {

public:

	virtual void execute(Creature& creature) {
		creature.right();
	}

};