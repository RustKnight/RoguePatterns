#pragma once

#include "Creature.h"
#include "Point.h"


class Command {
public:

	virtual ~Command() {};
	virtual void execute(Creature& creature) = 0;
	virtual Point direction() = 0;

	bool nullCommand = false;
};



class UpCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.up();
	}

	Point direction() override {

		return { 0, -1 };
	}


};


class ThrownUpCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.thrownUp();
	}

	Point direction() override {

		return { 0, -1 };
	}
};




class DownCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.down();
	}

	Point direction() override {

		return { 0, 1 };
	}
};


class ThrownDownCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.thrownDown();
	}

	Point direction() override {

		return { 0, 1 };
	}
};



class LeftCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.left();
	}

	Point direction() override {

		return { -1, 0 };
	}
};


class ThrownLeftCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.thrownLeft();
	}

	Point direction() override {

		return { -1, 0 };
	}
};



class RightCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.right();
	}

	Point direction() override {

		return { 1, 0 };
	}
};



class ThrownRightCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.thrownRight();
	}

	Point direction() override {

		return { 1, 0 };
	}
};


class WaitCommand : public Command {

public:

	void execute(Creature& creature) override {
		creature.skipTurn();
	}

	Point direction() override {

		return { 0, 0 };
	}
};


