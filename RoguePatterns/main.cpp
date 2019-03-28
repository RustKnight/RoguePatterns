

#include "Demo.h"
//	Purpose of project:

//	practice Design Patterns as provided in the 2 books


//	create a board REGION on which characters can interact
//	text will be outputed in console



int main() {

	Demo demo;
	if (demo.Construct(demo.getWinWidth(), demo.getWinHeight(), 1, 1))
		demo.Start();

	return 0;
}