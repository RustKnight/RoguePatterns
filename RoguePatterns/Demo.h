#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Board.h"
#include "Creature.h"
#include "InputHandler.h"
#include "Strategy.h"
#include "Ai.h"
#include "InteractionHandler.h"
#include "Obstacle.h"
#include "map.h"
#include "turnTaker.h"

#include <vector>
#include <typeinfo>


// add weapons of different attack values (Ex: Axe +2, Sword +1, etc. - naming will just be flavor for now)
// add ability for players to pick up different weapons and be able to exchange them when desired
// make an AI that always is on a look out for a best weapon, and when possible it swaps it
// action text will be outputed in the command line




// make the world understand grids. grids can be empty or hold things
	// ai and interactionHandler will be use of this container
	// ai can scan based on his location, his surroundings 


// 1 action = 1 move ; all creatures have 1 move per turn

// bump on wall			= remain on original postion 

// teams

// bump on enemy		= means attack
// bump on friendly		= remain on original postion 

// animations / physics 

//TODO: fix main loop 
			// - teams
			// - possibly add turns system
			// - accomodate implementation of animations

// a creature that is thrown should not care about map. It should go along its path and it's interactionHandlers job to monitor if it collides or not.
// if thrown creature stops, but it still had travel distance, it will take damage depending on how much travel dist. was left
// if a thrown action occurs, turnTaker should stop normal flow of turn and resolve thrown object. Then resume normal order.

// animation for creature fragging that is hit against a wall (letter sign disappears and multiple other '&' signs jump randomly around)
	// maybe have a function in creature called explode() -> how can Creature affect state of world? needs to create other flying entities
	// have a class exploder that can explode objects (isolate flyThrough algorithm for improvement)

// Animation definition: ...
// when a thing is in the state of animation, it sort of stops the turn of all other things, until that animation is finished
	// if several things are in animation state they will resolve their animation first before other things

class Demo : public olc::PixelGameEngine
{
public:
	Demo() : winsizeX {800}, winsizeY {600}, 
		board	(25, 25, 25, 15, getWinWidth(), getWinHeight(), this),
		map (board),
		interactionHandler(map),
		playerInput (this),
		turnTaker (vpThings)
	{
		sAppName = "Demo";
	}

public:
	bool OnUserCreate() override
	{

		Creature* knight = new Creature("Knight", 'K', { 10,5 }, olc::DARK_RED, &interactionHandler, &playerInput, &fElapsedTime, this);
		knight->equip(new Sword(this, &fElapsedTime));
		vpThings.push_back(knight);

		Creature* fiend = new Creature("Fiend", 'F', { 5,5 }, olc::DARK_MAGENTA, &interactionHandler, &ai, &fElapsedTime, this);
		fiend->equip(new Axe(this, &fElapsedTime));
		vpThings.push_back(fiend);

		Creature* fiend2 = new Creature("Fiend2", 'F', { 0,5 }, olc::DARK_MAGENTA, &interactionHandler, &ai, &fElapsedTime, this);
		fiend->equip(new Axe(this, &fElapsedTime));
		vpThings.push_back(fiend2);

		for (int x = 0; x < 25; ++x)
			for (int y = 0; y < 15; ++y) {

				// left border
				if (x == 0)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, &interactionHandler, &fElapsedTime, this));

				// right border
				if (x == 24)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, &interactionHandler, &fElapsedTime, this));

				// top border
				if (x != 0 && y == 0)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, &interactionHandler, &fElapsedTime, this));

				// bottom border
				if (x != 0 && y == 14)
					vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, &interactionHandler, &fElapsedTime, this));
			}

		for (int i = 0; i < 20; ++i) {

			int x = rand() % 26;
			int y = rand() % 16;

			vpThings.push_back(new Obstacle("Wall", '@', { x,y }, olc::VERY_DARK_GREY, &interactionHandler, &fElapsedTime, this));
		}

		
		return true;
	}



	bool OnUserUpdate(float fElapsedTime) override
	{

		this->fElapsedTime = fElapsedTime;
	
		Clear(olc::BLACK);
		{

			if (GetMouseWheel() > 0) {
				board.cellSizeX++;
				board.cellSizeY++;
			}

			if (GetMouseWheel() < 0) {
				board.cellSizeX--;
				board.cellSizeY--;
			}

			if (GetKey(olc::G).bPressed)
				board.toggleGrid();
		}

		
		actorSwitchDEBUG();


		turnTaker.update(vpThings);
		map.update(vpThings);

		// check and resolve animations first, if any
		bool physicsPlaying = false;

		for (Thing* thing : vpThings) {

			if (thing->physics.isBusy()) {

				thing->physics.execute();
				physicsPlaying = true;
			}
		}

		if (!physicsPlaying)
			turnTaker.handleTurns();

		
		board.drawBoard();


		for (Thing* thing : vpThings)
			board.drawThing(*thing);


		//board.drawTurnNotifier(turnTaker.whoPlaysNow());

		return true;
	}




	// Demo public methods
public:
	int getWinWidth() const		{ return winsizeX; };
	int getWinHeight() const	{ return winsizeY; };

	void actorSwitchDEBUG()    {

		if (this->GetKey(olc::L).bHeld)
			static_cast<Creature*> (vpThings[0])->switchPossesor(&ai);
		else
			static_cast<Creature*> (vpThings[0])->switchPossesor(&playerInput);
	}

	// Demo private data members
private:

	float fElapsedTime;

	int winsizeX;
	int winsizeY;

	InteractionHandler interactionHandler;
	Board board;
	Map map;
	Ai ai;

	vector<Thing*>vpThings;
	InputHandler playerInput;

	TurnTaker turnTaker;
	

};


