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
	/// Draw our SFML::capsuleShape and bounding box to the game window
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

	struct capsuleShape
	{
		sf::CircleShape a;
		sf::CircleShape b;
		sf::RectangleShape rect;

		float radius{ 25.0f };
		float length{ 50.0f };

		void init();
		void setPosition(sf::Vector2f t_pos);
		void setColor(sf::Color t_color);
		void draw(sf::RenderWindow& t_window);

	} m_shape;

	c2Capsule m_boundingBox = c2Capsule();
};

#endif //!CAPSULE_OBJ_H