#ifndef CAPSULE_OBJ_H
#define CAPSULE_OBJ_H

#include "GameObject.h"

class Capsule_Obj :
	public GameObject
{
public:
	Capsule_Obj() = default;
	~Capsule_Obj() = default;


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
	inline c2Capsule const* getBounds() const { return &m_boundingBox; }

private:

	void setupShape();
	void updateBoundingBox();

	c2Capsule m_boundingBox = c2Capsule();
};

#endif //!CAPSULE_OBJ_H