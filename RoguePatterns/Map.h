#pragma once

#include <vector>
#include "Point.h"
#include "Thing.h"
using namespace std;



class Map {
public:
	Map() = default;
	


private:
	vector<Thing*> vThings;
};