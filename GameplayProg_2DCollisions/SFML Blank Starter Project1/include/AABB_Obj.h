#ifndef AABB_OBJ_H
#define AABB_OBJ_H

#include "GameObject.h"

class AABB_Obj :
	public GameObject
{
public:
	AABB_Obj() = default;
	~AABB_Obj() = default;


	/// <summary>
	/// Initialise our object
	/// </summary>
	void init() override;

	/// <summary>
	/// Tells the object that it is colliding with something
	/// </summary>
	void isColliding() override;

	/// <summary>
	/// Main update method
	/// </summary>
	/// <param name="t_deltaTime">Time elapsed since last update call</param>
	void update(sf::Time t_deltaTime) override;

	/// <summary>
	/// Draw our SFML::capsuleShape and bounding box to the game window
	/// </summary>
	/// <param name="t_window">render window to draw to</param>
	void draw(sf::RenderWindow& t_window) override;

	/// <summary>
	/// Gets a const pointer to our bounding box
	/// </summary>
	/// <returns>pointer to our bounding box</returns>
	inline c2AABB const* getBounds() const { return &m_boundingBox; }

private:

	void setupShape();
	void updateBoundingBox();

	sf::RectangleShape m_shape;

	c2AABB m_boundingBox = c2AABB();
};

#endif // !AABB_OBJ_H