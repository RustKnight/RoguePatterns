#include "Physics.h"
#include "InteractionHandler.h"



void Physics::getThrown(int TilesThrown, Command* dir)
{

    busy = true;

    // record start position
    startPosition = thing.getPosition();

    // record final position
    targetPosition =  (dir->direction() * TilesThrown) + startPosition;

    // record thrown direction
    // ThrownUpCommand* p = new ThrownUpCommand;
    direction = moveToThrow(dir);

}

bool Physics::hasWork()
{
    return busy;
}

void Physics::initCommands()
{
    thrownUp    = new ThrownUpCommand;
    thrownDown  = new ThrownDownCommand;
    thrownLeft  = new ThrownLeftCommand;
    thrownRight = new ThrownRightCommand;
}

Command* Physics::moveToThrow(Command* moveCommand)
{
    if (typeid (*moveCommand) == typeid (UpCommand))
        return thrownUp;

    else if (typeid (*moveCommand) == typeid (DownCommand))
        return thrownDown;

    else if (typeid (*moveCommand) == typeid (LeftCommand))
        return thrownLeft;

    else if (typeid (*moveCommand) == typeid (RightCommand))
        return thrownRight;
}


void Physics::execute()
{

    if (thing.getPosition() != targetPosition)
        thing.interactionHandler->handleAction(&thing, direction);

    else
        // means we didn't hit anything while flying - job done
        busy = false;
}

int Physics::cellsLeft(Point& point)
{
    if (point.x != 0) return abs (point.x);
    if (point.y != 0) return abs (point.y);

    return 0;
}


void Physics::calculateCollision()
{
    // not busy means we just bumped into something; ignore

    if (busy) {

        // check if correct
        int cells = cellsLeft (thing.getPosition() - targetPosition);
        cout << cells << "\n";

        thing.takeDamage(cells * 2);
        busy = false;


    }
    
}
