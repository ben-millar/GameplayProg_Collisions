#ifndef POLYGON_OBJ_H
#define POLYGON_OBJ_H

#include "GameObject.h"

class Polygon_Obj :
	public GameObject
{
public:
	Polygon_Obj() = default;
	~Polygon_Obj() = default;


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
	/// Draw our SFML::shape and bounding box to the game window
	/// </summary>
	/// <param name="t_window">render window to draw to</param>
	void draw(sf::RenderWindow& t_window) override;

	/// <summary>
	/// Gets a const pointer to our bounding box
	/// </summary>
	/// <returns>pointer to our bounding box</returns>
	inline c2Poly const* getBounds() const { return &m_boundingBox; }

private:

	void setupShape();
	void updateBoundingBox();

	c2Poly m_boundingBox = c2Poly();

};

#endif //!POLYGON_OBJ_H