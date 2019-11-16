#include "Ray_Obj.h"

void Ray_Obj::init()
{
	float xPos = static_cast<float>(rand() % 700 + 51); // range 50–750
	float yPos = static_cast<float>(rand() % 500 + 51); // range 50–550

	float xVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f
	float yVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f

	m_position = { xPos, yPos };
	m_velocity = { xVel, yVel };
}

/////////////////////////////////////////////////////////////

void Ray_Obj::update(sf::Time t_deltaTime)
{
}

/////////////////////////////////////////////////////////////

void Ray_Obj::draw(sf::RenderWindow& t_window)
{
}
