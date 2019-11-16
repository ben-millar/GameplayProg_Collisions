#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <GameObject.h>
#include <AABB_Obj.h>
#include <Capsule_Obj.h>
#include <Circle_Obj.h>
#include <Polygon_Obj.h>
#include <Ray_Obj.h>

class Game
{
public:
	// #### CONSTRUCTOR/DESTRUCTOR ####

	Game();
	~Game();

	// ######## PUBLIC METHODS ########

	void run();

private:

	// ####### PRIVATE METHODS ########

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();


	// ####### PRIVATE VARIABLES ######
	sf::RenderWindow m_window;
	bool m_exitGame;

	// ################################
};
#endif