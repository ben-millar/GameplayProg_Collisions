#include "AABB_Obj.h"

void AABB_Obj::init()
{
	float xPos = static_cast<float>(rand() % 700 + 51); // range 50–750
	float yPos = static_cast<float>(rand() % 500 + 51); // range 50–550

	float xVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f
	float yVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f

	m_position = { xPos, yPos };
	m_velocity = { xVel, yVel };

	setupShape();
	updateBoundingBox();
}

/////////////////////////////////////////////////////////////

void AABB_Obj::isColliding()
{
	m_shape.setOutlineColor(sf::Color::Yellow);
}

/////////////////////////////////////////////////////////////

void AABB_Obj::setupShape()
{
	m_shape.setSize({ 50.0f,50.0f });
	m_shape.setFillColor(sf::Color(255U,64U,64U,224U));

	m_shape.setOutlineThickness(2.0f);
}

/////////////////////////////////////////////////////////////

void AABB_Obj::update(sf::Time t_deltaTime)
{
	m_position += m_velocity;

	if (m_position.x < 0.0f || m_position.x >(800.0f - m_shape.getSize().x))
	{
		m_velocity.x *= -1.0f;
	}

	if (m_position.y < 0.0f || m_position.y >(600.0f - m_shape.getSize().y))
	{
		m_velocity.y *= -1.0f;
	}

	updateBoundingBox();

	m_shape.setOutlineColor(sf::Color(0U, 0U, 0U, 0U));
}

/////////////////////////////////////////////////////////////

void AABB_Obj::updateBoundingBox()
{
	m_boundingBox.min.x = m_position.x;
	m_boundingBox.max.x = m_position.x + m_shape.getGlobalBounds().width;

	m_boundingBox.min.y = m_position.y;
	m_boundingBox.max.y = m_position.y + m_shape.getGlobalBounds().height;
}

/////////////////////////////////////////////////////////////

void AABB_Obj::draw(sf::RenderWindow& t_window)
{
	m_shape.setPosition(m_position);

	t_window.draw(m_shape);
}