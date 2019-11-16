#ifndef CIRCLE_OBJ_H
#define CIRCLE_OBJ_H

#include "GameObject.h"

class Circle_Obj :
	public GameObject
{
public:
	Circle_Obj() : m_radius{ 25.0f } {};
	~Circle_Obj() = default;


	/// <summary>
	/// Initialise our object
	/// </summary>
	void init() override;

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
	inline c2Circle const* getBounds() const { return &m_boundingBox; }

private:

	void setupShape();
	void updateBoundingBox();

	sf::CircleShape m_shape;
	float m_radius;
	c2Circle m_boundingBox = c2Circle();
};

#endif //!CIRCLE_OBJ_H