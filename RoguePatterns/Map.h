#pragma once

#include <vector>
#include "Point.h"
#include "Thing.h"
using namespace std;

class Thing;

class Map {
public:
	Map() = default;
	
	void addThing(Thing* thing);
	vector<Thing*> vThings;

private:
	
};