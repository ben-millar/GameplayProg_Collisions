#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <GameObject.h>
#include <AABB_Obj.h>
#include <Capsule_Obj.h>
#include <Circle_Obj.h>
#include <Polygon_Obj.h>
#include <Ray_Obj.h>

#include <array>

class Game
{
public:

	Game();
	~Game();

	/// <summary>
	/// Our main game loop: calls processEvents/Update/Render
	/// </summary>
	void run();

private:
	/// <summary>
	/// Handle queue of incoming events; process or ignore
	/// </summary>
	void processEvents();

	/// <summary>
	/// Main update loop of our game
	/// </summary>
	/// <param name="t_deltaTime">time since last update call</param>
	void update(sf::Time t_deltaTime);

	/// <summary>
	/// Draws/Flips framebuffer
	/// </summary>
	void render();

	sf::RenderWindow m_window;
	bool m_exitGame;

	std::array<GameObject*, 5> p_objArray;

	AABB_Obj aabbObject;
	Capsule_Obj capsuleObject;
	Circle_Obj circleObject;
	Polygon_Obj polyObject;
	Ray_Obj rayObject;

};
#endif