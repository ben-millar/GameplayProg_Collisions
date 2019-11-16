// @Author: Ben Millar C00236772@itcarlow.ie
// @Date: November, 2019
//
// @Brief: Simple project to demonstrate implementation of various bounding box collisions
//		   using the tinyc2 library
//
// Estimated time to complete: 6.5 hours
// Session 1 Start: 13:15 End: 15:40 – 902 lines of code
// Session 2 Start: 16:25 End: 
// Total time taken: 2 hours 25 minutes

// @TODO: Abstract collision handling out to a collision handler class

#include "Game.h"

int main()
{
	// seed our RNG for placement/velocity
	srand(static_cast<unsigned>(time(nullptr)));

	Game game;
	game.run();
	return EXIT_SUCCESS;
}