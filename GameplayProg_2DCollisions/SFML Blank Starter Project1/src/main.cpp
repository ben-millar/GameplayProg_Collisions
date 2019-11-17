// @Author: Ben Millar C00236772@itcarlow.ie
// @Date: November, 2019
//
// @Brief: Simple project to demonstrate implementation of various bounding box collisions
//		   using the tinyc2 library
//
// Estimated time to complete: 6.5 hours
// Session 1 Start: 13:15 End: 15:40 – 902 lines of code
// Session 2 Start: 16:25 End: 17:45 – 248 lines of code
// Session 3 Start: 19:55 End: 20:15 – 57 lines of code
// Session 4 Start: 15:05 End: 16:15
// Total time taken: 5 hours 15 minutes


#include "Game.h"

int main()
{
	// seed our RNG for placement/velocity
	srand(static_cast<unsigned>(time(nullptr)));

	Game game;
	game.run();
	return EXIT_SUCCESS;
}