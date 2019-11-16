#ifndef RAY_OBJ_H
#define RAY_OBJ_H

#include "GameObject.h"

class Ray_Obj :
	public GameObject
{
public:
	Ray_Obj() = default;
	~Ray_Obj() = default;


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
	inline c2Ray const* const getBounds() const { return &m_boundingBox; }

private:

	void setupShape();
	void updateBoundingBox();

	c2Ray m_boundingBox = c2Ray();

};

#endif //!RAY_OBJ_H