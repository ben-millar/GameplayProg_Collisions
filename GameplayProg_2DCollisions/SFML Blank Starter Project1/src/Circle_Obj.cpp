#include "Circle_Obj.h"

void Circle_Obj::init()
{
	float xPos = static_cast<float>(rand() % 700 + 51); // range 50–750
	float yPos = static_cast<float>(rand() % 500 + 51); // range 50–550

	float xVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f
	float yVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f

	m_position = { xPos, yPos };
	m_velocity = { xVel, yVel };

	setupShape();

	m_boundingBox.r = m_radius;

	updateBoundingBox();
}

/////////////////////////////////////////////////////////////

void Circle_Obj::isColliding()
{
	m_shape.setOutlineColor(sf::Color::Yellow);
}

/////////////////////////////////////////////////////////////

void Circle_Obj::setupShape()
{
	m_shape.setRadius(m_radius);
	m_shape.setOrigin({ m_radius, m_radius });
	m_shape.setFillColor(sf::Color::Red);

	m_shape.setOutlineThickness(2.0f);
}

/////////////////////////////////////////////////////////////

void Circle_Obj::update(sf::Time t_deltaTime)
{
	m_position += m_velocity;

	if ((m_position.x - m_radius) < 0.0f || (m_position.x + m_radius) > 800.0f)
	{
		m_velocity.x *= -1.0f;
	}

	if ((m_position.y - m_radius) < 0.0f || (m_position.y + m_radius) > 600.0f)
	{
		m_velocity.y *= -1.0f;
	}

	updateBoundingBox();

	m_shape.setOutlineColor(sf::Color(0U, 0U, 0U, 0U));
}

/////////////////////////////////////////////////////////////

void Circle_Obj::updateBoundingBox()
{
	m_boundingBox.p.x = m_position.x;
	m_boundingBox.p.y = m_position.y;
}

/////////////////////////////////////////////////////////////

void Circle_Obj::draw(sf::RenderWindow& t_window)
{
	m_shape.setPosition(m_position);
	t_window.draw(m_shape);
}