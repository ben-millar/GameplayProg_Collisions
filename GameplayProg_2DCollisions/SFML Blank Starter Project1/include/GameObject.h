#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <tinyc2.h>
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject() = default;
	~GameObject() = default;

	/// <summary>
	/// Initialise our object
	/// </summary>
	virtual void init() = 0;

	/// <summary>
	/// Main update method
	/// </summary>
	/// <param name="t_deltaTime">Time elapsed since last update call</param>
	virtual void update(sf::Time t_deltaTime) = 0;

	/// <summary>
	/// Draw our SFML::capsuleShape and bounding box to the game window
	/// </summary>
	/// <param name="t_window">render window to draw to</param>
	virtual void draw(sf::RenderWindow& t_window) = 0;


protected:
	sf::Vector2f m_position{ 0.0f,0.0f };
	sf::Vector2f m_velocity{ 0.0f,0.0f };
};

#endif //!GAMEOBJECT_H